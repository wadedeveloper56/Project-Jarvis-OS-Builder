#include "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

Macro::Macro(vector<std::string>& f) : nameTokDef(nullptr), valueToken(nullptr), endToken(nullptr), files(f), tokenListDefine(f), variadic(false), variadicOpt(false), optExpandValue(nullptr), optNoExpandValue(nullptr), valueDefinedInCode_(false)
{}

Macro::Macro(const Token* tok, std::vector<std::string>& f) : nameTokDef(nullptr), files(f), tokenListDefine(f), valueDefinedInCode_(true) {
	if (sameline(tok->previousSkipComments(), tok))
		throw std::runtime_error("bad macro syntax");
	if (tok->op != '#')
		throw std::runtime_error("bad macro syntax");
	const Token* const hashtok = tok;
	tok = tok->next;
	if (!tok || tok->str() != DEFINE)
		throw std::runtime_error("bad macro syntax");
	tok = tok->next;
	if (!tok || !tok->name || !sameline(hashtok, tok))
		throw std::runtime_error("bad macro syntax");
	if (!parseDefine(tok))
		throw std::runtime_error("bad macro syntax");
}

Macro::Macro(const std::string& name, const std::string& value, std::vector<std::string>& f) : nameTokDef(nullptr), files(f), tokenListDefine(f), valueDefinedInCode_(false) {
	const std::string def(name + ' ' + value);
	StdCharBufStream stream(reinterpret_cast<const unsigned char*>(def.data()), def.size());
	tokenListDefine.readfile(stream);
	if (!parseDefine(tokenListDefine.cfront()))
		throw std::runtime_error("bad macro syntax. macroname=" + name + " value=" + value);
}

Macro::Macro(const Macro& other) : nameTokDef(nullptr), files(other.files), tokenListDefine(other.files), valueDefinedInCode_(other.valueDefinedInCode_) {
	*this = other;
}

Macro::~Macro() {
	delete optExpandValue;
	delete optNoExpandValue;
}

Macro& Macro::operator=(const Macro& other) {
	if (this != &other)
	{
		files = other.files;
		valueDefinedInCode_ = other.valueDefinedInCode_;
		if (other.tokenListDefine.empty())
			parseDefine(other.nameTokDef);
		else
		{
			tokenListDefine = other.tokenListDefine;
			parseDefine(tokenListDefine.cfront());
		}
		usageList = other.usageList;
	}
	return *this;
}

bool Macro::valueDefinedInCode() const {
	return valueDefinedInCode_;
}

const Token* Macro::expand(TokenList* const output,
	const Token* rawtok,
	const MacroMap& macros,
	std::vector<std::string>& inputFiles) const {
	std::set<TokenString> expandedmacros;

#ifdef SIMPLECPP_DEBUG_MACRO_EXPANSION
	std::cout << "expand " << name() << " " << locstring(rawtok->location) << std::endl;
#endif

	TokenList output2(inputFiles);

	if (functionLike() && rawtok->next && rawtok->next->op == '(')
	{
		// Copy macro call to a new tokenlist with no linebreaks
		const Token* const rawtok1 = rawtok;
		TokenList rawtokens2(inputFiles);
		rawtokens2.push_back(new Token(rawtok->str(), rawtok1->location, rawtok->whitespaceahead));
		rawtok = rawtok->next;
		rawtokens2.push_back(new Token(rawtok->str(), rawtok1->location, rawtok->whitespaceahead));
		rawtok = rawtok->next;
		int par = 1;
		while (rawtok && par > 0)
		{
			if (rawtok->op == '(')
				++par;
			else if (rawtok->op == ')')
				--par;
			else if (rawtok->op == '#' && !sameline(rawtok->previous, rawtok))
				throw Error(rawtok->location, "it is invalid to use a preprocessor directive as macro parameter");
			rawtokens2.push_back(new Token(rawtok->str(), rawtok1->location, rawtok->whitespaceahead));
			rawtok = rawtok->next;
		}
		if (expand(&output2, rawtok1->location, rawtokens2.cfront(), macros, expandedmacros))
			rawtok = rawtok1->next;
	}
	else
	{
		rawtok = expand(&output2, rawtok->location, rawtok, macros, expandedmacros);
	}
	while (output2.cback() && rawtok)
	{
		unsigned int par = 0;
		Token* macro2tok = output2.back();
		while (macro2tok)
		{
			if (macro2tok->op == '(')
			{
				if (par == 0)
					break;
				--par;
			}
			else if (macro2tok->op == ')')
				++par;
			macro2tok = macro2tok->previous;
		}
		if (macro2tok)
		{ // macro2tok->op == '('
			macro2tok = macro2tok->previous;
			expandedmacros.insert(name());
		}
		else if (rawtok->op == '(')
			macro2tok = output2.back();
		if (!macro2tok || !macro2tok->name)
			break;
		if (output2.cfront() != output2.cback() && macro2tok->str() == this->name())
			break;
		const MacroMap::const_iterator macro = macros.find(macro2tok->str());
		if (macro == macros.end() || !macro->second.functionLike())
			break;
		TokenList rawtokens2(inputFiles);
		const Location loc(macro2tok->location);
		while (macro2tok)
		{
			Token* const next = macro2tok->next;
			rawtokens2.push_back(new Token(macro2tok->str(), loc));
			output2.deleteToken(macro2tok);
			macro2tok = next;
		}
		par = (rawtokens2.cfront() != rawtokens2.cback()) ? 1U : 0U;
		const Token* rawtok2 = rawtok;
		for (; rawtok2; rawtok2 = rawtok2->next)
		{
			rawtokens2.push_back(new Token(rawtok2->str(), loc));
			if (rawtok2->op == '(')
				++par;
			else if (rawtok2->op == ')')
			{
				if (par <= 1U)
					break;
				--par;
			}
		}
		if (!rawtok2 || par != 1U)
			break;
		if (macro->second.expand(&output2, rawtok->location, rawtokens2.cfront(), macros, expandedmacros) != nullptr)
			break;
		rawtok = rawtok2->next;
	}
	output->takeTokens(output2);
	return rawtok;
}

/** macro name */
const TokenString& Macro::name() const {
	return nameTokDef->str();
}

/** location for macro definition */
const Location& Macro::defineLocation() const {
	return nameTokDef->location;
}

/** how has this macro been used so far */
const std::list<Location>& Macro::usage() const {
	return usageList;
}

/** is this a function like macro */
bool Macro::functionLike() const {
	return nameTokDef->next &&
		nameTokDef->next->op == '(' &&
		sameline(nameTokDef, nameTokDef->next) &&
		nameTokDef->next->location.col == nameTokDef->location.col + nameTokDef->str().size();
}

	Token* Macro::newMacroToken(const TokenString& str, const Location& loc, bool replaced, const Token* expandedFromToken) const {
		Token* tok = new Token(str, loc);
		if (replaced)
			tok->macro = nameTokDef->str();
		if (expandedFromToken)
			tok->setExpandedFrom(expandedFromToken, this);
		return tok;
	}

	bool Macro::parseDefine(const Token* nametoken) {
		nameTokDef = nametoken;
		variadic = false;
		variadicOpt = false;
		optExpandValue = nullptr;
		optNoExpandValue = nullptr;
		if (!nameTokDef)
		{
			valueToken = endToken = nullptr;
			args.clear();
			return false;
		}

		// function like macro..
		if (functionLike())
		{
			args.clear();
			const Token* argtok = nameTokDef->next->next;
			while (sameline(nametoken, argtok) && argtok->op != ')')
			{
				if (argtok->str() == "..." &&
					argtok->next && argtok->next->op == ')')
				{
					variadic = true;
					if (!argtok->previous->name)
						args.push_back("__VA_ARGS__");
					argtok = argtok->next; // goto ')'
					break;
				}
				if (argtok->op != ',')
					args.push_back(argtok->str());
				argtok = argtok->next;
			}
			if (!sameline(nametoken, argtok))
			{
				endToken = argtok ? argtok->previous : argtok;
				valueToken = nullptr;
				return false;
			}
			valueToken = argtok ? argtok->next : nullptr;
		}
		else
		{
			args.clear();
			valueToken = nameTokDef->next;
		}

		if (!sameline(valueToken, nameTokDef))
			valueToken = nullptr;
		endToken = valueToken;
		while (sameline(endToken, nameTokDef))
		{
			if (variadic && endToken->str() == "__VA_OPT__")
				variadicOpt = true;
			endToken = endToken->next;
		}

		if (variadicOpt)
		{
			TokenList expandValue(files);
			TokenList noExpandValue(files);
			for (const Token* tok = valueToken; tok && tok != endToken;)
			{
				if (tok->str() == "__VA_OPT__")
				{
					if (!sameline(tok, tok->next) || tok->next->op != '(')
						throw Error(tok->location, "In definition of '" + nameTokDef->str() + "': Missing opening parenthesis for __VA_OPT__");
					tok = tok->next->next;
					int par = 1;
					while (tok && tok != endToken)
					{
						if (tok->op == '(')
							par++;
						else if (tok->op == ')')
							par--;
						else if (tok->str() == "__VA_OPT__")
							throw Error(tok->location, "In definition of '" + nameTokDef->str() + "': __VA_OPT__ cannot be nested");
						if (par == 0)
						{
							tok = tok->next;
							break;
						}
						expandValue.push_back(new Token(*tok));
						tok = tok->next;
					}
					if (par != 0)
					{
						const Token* const lastTok = expandValue.back() ? expandValue.back() : valueToken->next;
						throw Error(lastTok->location, "In definition of '" + nameTokDef->str() + "': Missing closing parenthesis for __VA_OPT__");
					}
				}
				else
				{
					expandValue.push_back(new Token(*tok));
					noExpandValue.push_back(new Token(*tok));
					tok = tok->next;
				}
			}
			optExpandValue = new TokenList(std::move(expandValue));
			optNoExpandValue = new TokenList(std::move(noExpandValue));
		}

		return true;
	}

	unsigned int Macro::getArgNum(const TokenString& str) const {
		unsigned int par = 0;
		while (par < args.size())
		{
			if (str == args[par])
				return par;
			par++;
		}
		return ~0U;
	}

	std::vector<const Token*> Macro::getMacroParameters(const Token* nameTokInst, bool calledInDefine) const {
		if (!nameTokInst->next || nameTokInst->next->op != '(' || !functionLike())
			return std::vector<const Token*>();

		std::vector<const Token*> parametertokens;
		parametertokens.push_back(nameTokInst->next);
		unsigned int par = 0U;
		for (const Token* tok = nameTokInst->next->next; calledInDefine ? sameline(tok, nameTokInst) : (tok != nullptr); tok = tok->next)
		{
			if (tok->op == '(')
				++par;
			else if (tok->op == ')')
			{
				if (par == 0U)
				{
					parametertokens.push_back(tok);
					break;
				}
				--par;
			}
			else if (par == 0U && tok->op == ',' && (!variadic || parametertokens.size() < args.size()))
				parametertokens.push_back(tok);
		}
		return parametertokens;
	}

	const Token* Macro::appendTokens(TokenList* tokens,
		const Location& rawloc,
		const Token* const lpar,
		const MacroMap& macros,
		const std::set<TokenString>& expandedmacros,
		const std::vector<const Token*>& parametertokens) const {
		if (!lpar || lpar->op != '(')
			return nullptr;
		unsigned int par = 0;
		const Token* tok = lpar;
		while (sameline(lpar, tok))
		{
			if (tok->op == '#' && sameline(tok, tok->next) && tok->next->op == '#' && sameline(tok, tok->next->next))
			{
				// A##B => AB
				tok = expandHashHash(tokens, rawloc, tok, macros, expandedmacros, parametertokens, false);
			}
			else if (tok->op == '#' && sameline(tok, tok->next) && tok->next->op != '#')
			{
				tok = expandHash(tokens, rawloc, tok, expandedmacros, parametertokens);
			}
			else
			{
				if (!expandArg(tokens, tok, rawloc, macros, expandedmacros, parametertokens))
				{
					tokens->push_back(new Token(*tok));
					if (tok->macro.empty() && (par > 0 || tok->str() != "("))
						tokens->back()->macro = name();
				}

				if (tok->op == '(')
					++par;
				else if (tok->op == ')')
				{
					--par;
					if (par == 0U)
						break;
				}
				tok = tok->next;
			}
		}
		for (Token* tok2 = tokens->front(); tok2; tok2 = tok2->next)
			tok2->location = lpar->location;
		return sameline(lpar, tok) ? tok : nullptr;
	}

	const Token* Macro::expand(TokenList* const output, const Location& loc, const Token* const nameTokInst, const MacroMap& macros, std::set<TokenString> expandedmacros) const {
		expandedmacros.insert(nameTokInst->str());

#ifdef SIMPLECPP_DEBUG_MACRO_EXPANSION
		std::cout << "  expand " << name() << " " << locstring(defineLocation()) << std::endl;
#endif

		usageList.push_back(loc);

		if (nameTokInst->str() == "__FILE__")
		{
			output->push_back(new Token('\"' + loc.file() + '\"', loc));
			return nameTokInst->next;
		}
		if (nameTokInst->str() == "__LINE__")
		{
			output->push_back(new Token(toString(loc.line), loc));
			return nameTokInst->next;
		}
		if (nameTokInst->str() == "__COUNTER__")
		{
			output->push_back(new Token(toString(usageList.size() - 1U), loc));
			return nameTokInst->next;
		}

		const bool calledInDefine = (loc.fileIndex != nameTokInst->location.fileIndex ||
			loc.line < nameTokInst->location.line);

		std::vector<const Token*> parametertokens1(getMacroParameters(nameTokInst, calledInDefine));

		if (functionLike())
		{
			// No arguments => not macro expansion
			if (nameTokInst->next && nameTokInst->next->op != '(')
			{
				output->push_back(new Token(nameTokInst->str(), loc));
				return nameTokInst->next;
			}

			// Parse macro-call
			if (variadic)
			{
				if (parametertokens1.size() < args.size())
				{
					throw wrongNumberOfParameters(nameTokInst->location, name());
				}
			}
			else
			{
				if (parametertokens1.size() != args.size() + (args.empty() ? 2U : 1U))
					throw wrongNumberOfParameters(nameTokInst->location, name());
			}
		}

		// If macro call uses __COUNTER__ then expand that first
		TokenList tokensparams(files);
		std::vector<const Token*> parametertokens2;
		if (!parametertokens1.empty())
		{
			bool counter = false;
			for (const Token* tok = parametertokens1[0]; tok != parametertokens1.back(); tok = tok->next)
			{
				if (tok->str() == "__COUNTER__")
				{
					counter = true;
					break;
				}
			}

			const MacroMap::const_iterator m = macros.find("__COUNTER__");

			if (!counter || m == macros.end())
				parametertokens2.swap(parametertokens1);
			else
			{
				const Macro& counterMacro = m->second;
				unsigned int par = 0;
				for (const Token* tok = parametertokens1[0]; tok && par < parametertokens1.size(); tok = tok->next)
				{
					if (tok->str() == "__COUNTER__")
					{
						tokensparams.push_back(new Token(toString(counterMacro.usageList.size()), tok->location));
						counterMacro.usageList.push_back(tok->location);
					}
					else
					{
						tokensparams.push_back(new Token(*tok));
						if (tok == parametertokens1[par])
						{
							parametertokens2.push_back(tokensparams.cback());
							par++;
						}
					}
				}
			}
		}

		Token* const output_end_1 = output->back();

		const Token* valueToken2;
		const Token* endToken2;

		if (variadicOpt)
		{
			if (parametertokens2.size() > args.size() && parametertokens2[args.size() - 1]->next->op != ')')
				valueToken2 = optExpandValue->cfront();
			else
				valueToken2 = optNoExpandValue->cfront();
			endToken2 = nullptr;
		}
		else
		{
			valueToken2 = valueToken;
			endToken2 = endToken;
		}

		// expand
		for (const Token* tok = valueToken2; tok != endToken2;)
		{
			if (tok->op != '#')
			{
				// A##B => AB
				if (sameline(tok, tok->next) && tok->next && tok->next->op == '#' && tok->next->next && tok->next->next->op == '#')
				{
					if (!sameline(tok, tok->next->next->next))
						throw invalidHashHash::unexpectedNewline(tok->location, name());
					if (variadic && tok->op == ',' && tok->next->next->next->str() == args.back())
					{
						Token* const comma = newMacroToken(tok->str(), loc, isReplaced(expandedmacros), tok);
						output->push_back(comma);
						tok = expandToken(output, loc, tok->next->next->next, macros, expandedmacros, parametertokens2);
						if (output->back() == comma)
							output->deleteToken(comma);
						continue;
					}
					TokenList new_output(files);
					if (!expandArg(&new_output, tok, parametertokens2))
						output->push_back(newMacroToken(tok->str(), loc, isReplaced(expandedmacros), tok));
					else if (new_output.empty()) // placemarker token
						output->push_back(newMacroToken("", loc, isReplaced(expandedmacros)));
					else
						for (const Token* tok2 = new_output.cfront(); tok2; tok2 = tok2->next)
							output->push_back(newMacroToken(tok2->str(), loc, isReplaced(expandedmacros), tok2));
					tok = tok->next;
				}
				else
				{
					tok = expandToken(output, loc, tok, macros, expandedmacros, parametertokens2);
				}
				continue;
			}

			int numberOfHash = 1;
			const Token* hashToken = tok->next;
			while (sameline(tok, hashToken) && hashToken->op == '#')
			{
				hashToken = hashToken->next;
				++numberOfHash;
			}
			if (numberOfHash == 4 && tok->next->location.col + 1 == tok->next->next->location.col)
			{
				// # ## #  => ##
				output->push_back(newMacroToken("##", loc, isReplaced(expandedmacros)));
				tok = hashToken;
				continue;
			}

			if (numberOfHash >= 2 && tok->location.col + 1 < tok->next->location.col)
			{
				output->push_back(new Token(*tok));
				tok = tok->next;
				continue;
			}

			tok = tok->next;
			if (tok == endToken2)
			{
				output->push_back(new Token(*tok->previous));
				break;
			}
			if (tok->op == '#')
			{
				// A##B => AB
				tok = expandHashHash(output, loc, tok->previous, macros, expandedmacros, parametertokens2);
			}
			else
			{
				// #123 => "123"
				tok = expandHash(output, loc, tok->previous, expandedmacros, parametertokens2);
			}
		}

		if (!functionLike())
		{
			for (Token* tok = output_end_1 ? output_end_1->next : output->front(); tok; tok = tok->next)
			{
				tok->macro = nameTokInst->str();
			}
		}

		if (!parametertokens1.empty())
			parametertokens1.swap(parametertokens2);

		return functionLike() ? parametertokens2.back()->next : nameTokInst->next;
	}

	const Token* Macro::recursiveExpandToken(TokenList* output, TokenList& temp, const Location& loc, const Token* tok, const MacroMap& macros, const std::set<TokenString>& expandedmacros, const std::vector<const Token*>& parametertokens) const {
		if (!(temp.cback() && temp.cback()->name && tok->next && tok->next->op == '('))
		{
			output->takeTokens(temp);
			return tok->next;
		}

		if (!sameline(tok, tok->next))
		{
			output->takeTokens(temp);
			return tok->next;
		}

		const MacroMap::const_iterator it = macros.find(temp.cback()->str());
		if (it == macros.end() || expandedmacros.find(temp.cback()->str()) != expandedmacros.end())
		{
			output->takeTokens(temp);
			return tok->next;
		}

		const Macro& calledMacro = it->second;
		if (!calledMacro.functionLike())
		{
			output->takeTokens(temp);
			return tok->next;
		}

		TokenList temp2(files);
		temp2.push_back(new Token(temp.cback()->str(), tok->location));

		const Token* const tok2 = appendTokens(&temp2, loc, tok->next, macros, expandedmacros, parametertokens);
		if (!tok2)
			return tok->next;
		output->takeTokens(temp);
		output->deleteToken(output->back());
		calledMacro.expand(output, loc, temp2.cfront(), macros, expandedmacros);
		return tok2->next;
	}

	const Token* Macro::expandToken(TokenList* output, const Location& loc, const Token* tok, const MacroMap& macros, const std::set<TokenString>& expandedmacros, const std::vector<const Token*>& parametertokens) const {
		// Not name..
		if (!tok->name)
		{
			output->push_back(newMacroToken(tok->str(), loc, true, tok));
			return tok->next;
		}

		// Macro parameter..
		{
			TokenList temp(files);
			if (expandArg(&temp, tok, loc, macros, expandedmacros, parametertokens))
			{
				if (tok->str() == "__VA_ARGS__" && temp.empty() && output->cback() && output->cback()->str() == "," &&
					tok->nextSkipComments() && tok->nextSkipComments()->str() == ")")
					output->deleteToken(output->back());
				return recursiveExpandToken(output, temp, loc, tok, macros, expandedmacros, parametertokens);
			}
		}

		// Macro..
		const MacroMap::const_iterator it = macros.find(tok->str());
		if (it != macros.end() && expandedmacros.find(tok->str()) == expandedmacros.end())
		{
			std::set<std::string> expandedmacros2(expandedmacros);
			expandedmacros2.insert(tok->str());

			const Macro& calledMacro = it->second;
			if (!calledMacro.functionLike())
			{
				TokenList temp(files);
				calledMacro.expand(&temp, loc, tok, macros, expandedmacros);
				return recursiveExpandToken(output, temp, loc, tok, macros, expandedmacros2, parametertokens);
			}
			if (!sameline(tok, tok->next))
			{
				output->push_back(newMacroToken(tok->str(), loc, true, tok));
				return tok->next;
			}
			TokenList tokens(files);
			tokens.push_back(new Token(*tok));
			const Token* tok2 = nullptr;
			if (tok->next->op == '(')
				tok2 = appendTokens(&tokens, loc, tok->next, macros, expandedmacros, parametertokens);
			else if (expandArg(&tokens, tok->next, loc, macros, expandedmacros, parametertokens))
			{
				tokens.front()->location = loc;
				if (tokens.cfront()->next && tokens.cfront()->next->op == '(')
					tok2 = tok->next;
			}
			if (!tok2)
			{
				output->push_back(newMacroToken(tok->str(), loc, true, tok));
				return tok->next;
			}
			TokenList temp(files);
			calledMacro.expand(&temp, loc, tokens.cfront(), macros, expandedmacros);
			return recursiveExpandToken(output, temp, loc, tok2, macros, expandedmacros, parametertokens);
		}

		if (tok->str() == DEFINED)
		{
			const Token* const tok2 = tok->next;
			const Token* const tok3 = tok2 ? tok2->next : nullptr;
			const Token* const tok4 = tok3 ? tok3->next : nullptr;
			const Token* defToken = nullptr;
			const Token* lastToken = nullptr;
			if (sameline(tok, tok4) && tok2->op == '(' && tok3->name && tok4->op == ')')
			{
				defToken = tok3;
				lastToken = tok4;
			}
			else if (sameline(tok, tok2) && tok2->name)
			{
				defToken = lastToken = tok2;
			}
			if (defToken)
			{
				std::string macroName = defToken->str();
				if (defToken->next && defToken->next->op == '#' && defToken->next->next && defToken->next->next->op == '#' && defToken->next->next->next && defToken->next->next->next->name && sameline(defToken, defToken->next->next->next))
				{
					TokenList temp(files);
					if (expandArg(&temp, defToken, parametertokens))
						macroName = temp.cback()->str();
					if (expandArg(&temp, defToken->next->next->next, parametertokens))
						macroName += temp.cback() ? temp.cback()->str() : "";
					else
						macroName += defToken->next->next->next->str();
					lastToken = defToken->next->next->next;
				}
				const bool def = (macros.find(macroName) != macros.end());
				output->push_back(newMacroToken(def ? "1" : "0", loc, true));
				return lastToken->next;
			}
		}

		output->push_back(newMacroToken(tok->str(), loc, true, tok));
		return tok->next;
	}

	bool Macro::expandArg(TokenList* output, const Token* tok, const std::vector<const Token*>& parametertokens) const {
		if (!tok->name)
			return false;

		const unsigned int argnr = getArgNum(tok->str());
		if (argnr >= args.size())
			return false;

		// empty variadic parameter
		if (variadic && argnr + 1U >= parametertokens.size())
			return true;

		for (const Token* partok = parametertokens[argnr]->next; partok != parametertokens[argnr + 1U]; partok = partok->next)
			output->push_back(new Token(*partok));

		return true;
	}

	bool Macro::expandArg(TokenList* output, const Token* tok, const Location& loc, const MacroMap& macros, const std::set<TokenString>& expandedmacros, const std::vector<const Token*>& parametertokens) const {
		if (!tok->name)
			return false;
		const unsigned int argnr = getArgNum(tok->str());
		if (argnr >= args.size())
			return false;
		if (variadic && argnr + 1U >= parametertokens.size()) // empty variadic parameter
			return true;
		for (const Token* partok = parametertokens[argnr]->next; partok != parametertokens[argnr + 1U];)
		{
			const MacroMap::const_iterator it = macros.find(partok->str());
			if (it != macros.end() && !partok->isExpandedFrom(&it->second) && (partok->str() == name() || expandedmacros.find(partok->str()) == expandedmacros.end()))
			{
				std::set<TokenString> expandedmacros2(expandedmacros); // temporary amnesia to allow reexpansion of currently expanding macros during argument evaluation
				expandedmacros2.erase(name());
				partok = it->second.expand(output, loc, partok, macros, expandedmacros2);
			}
			else
			{
				output->push_back(newMacroToken(partok->str(), loc, isReplaced(expandedmacros), partok));
				output->back()->macro = partok->macro;
				partok = partok->next;
			}
		}
		if (tok->whitespaceahead && output->back())
			output->back()->whitespaceahead = true;
		return true;
	}

	const Token* Macro::expandHash(TokenList* output, const Location& loc, const Token* tok, const std::set<TokenString>& expandedmacros, const std::vector<const Token*>& parametertokens) const {
		TokenList tokenListHash(files);
		const MacroMap macros2; // temporarily bypass macro expansion
		tok = expandToken(&tokenListHash, loc, tok->next, macros2, expandedmacros, parametertokens);
		std::ostringstream ostr;
		ostr << '\"';
		for (const Token* hashtok = tokenListHash.cfront(), *next; hashtok; hashtok = next)
		{
			next = hashtok->next;
			ostr << hashtok->str();
			if (next && hashtok->whitespaceahead)
				ostr << ' ';
		}
		ostr << '\"';
		output->push_back(newMacroToken(escapeString(ostr.str()), loc, isReplaced(expandedmacros)));
		return tok;
	}

	const Token* Macro::expandHashHash(TokenList* output, const Location& loc, const Token* tok, const MacroMap& macros, const std::set<TokenString>& expandedmacros, const std::vector<const Token*>& parametertokens, bool expandResult) const {
		Token* A = output->back();
		if (!A)
			throw invalidHashHash(tok->location, name(), "Missing first argument");
		if (!sameline(tok, tok->next) || !sameline(tok, tok->next->next))
			throw invalidHashHash::unexpectedNewline(tok->location, name());

		const bool canBeConcatenatedWithEqual = A->isOneOf("+-*/%&|^") || A->str() == "<<" || A->str() == ">>";
		const bool canBeConcatenatedStringOrChar = isStringLiteral_(A->str()) || isCharLiteral_(A->str());
		const bool unexpectedA = (!A->name && !A->number && !A->str().empty() && !canBeConcatenatedWithEqual && !canBeConcatenatedStringOrChar);

		Token* const B = tok->next->next;
		if (!B->name && !B->number && B->op && !B->isOneOf("#="))
			throw invalidHashHash::unexpectedToken(tok->location, name(), B);

		if ((canBeConcatenatedWithEqual && B->op != '=') ||
			(!canBeConcatenatedWithEqual && B->op == '='))
			throw invalidHashHash::cannotCombine(tok->location, name(), A, B);

		// Superficial check; more in-depth would in theory be possible _after_ expandArg
		if (canBeConcatenatedStringOrChar && (B->number || !B->name))
			throw invalidHashHash::cannotCombine(tok->location, name(), A, B);

		TokenList tokensB(files);
		const Token* nextTok = B->next;

		if (canBeConcatenatedStringOrChar)
		{
			if (unexpectedA)
				throw invalidHashHash::unexpectedToken(tok->location, name(), A);

			// It seems clearer to handle this case separately even though the code is similar-ish, but we don't want to merge here.
			// TODO The question is whether the ## or varargs may still apply, and how to provoke?
			if (expandArg(&tokensB, B, parametertokens))
			{
				for (Token* b = tokensB.front(); b; b = b->next)
					b->location = loc;
			}
			else
			{
				tokensB.push_back(new Token(*B));
				tokensB.back()->location = loc;
			}
			output->takeTokens(tokensB);
		}
		else
		{
			std::string strAB;

			const bool varargs = variadic && !args.empty() && B->str() == args[args.size() - 1U];

			if (expandArg(&tokensB, B, parametertokens))
			{
				if (tokensB.empty())
					strAB = A->str();
				else if (varargs && A->op == ',')
					strAB = ",";
				else if (varargs && unexpectedA)
					throw invalidHashHash::unexpectedToken(tok->location, name(), A);
				else
				{
					strAB = A->str() + tokensB.cfront()->str();
					tokensB.deleteToken(tokensB.front());
				}
			}
			else
			{
				if (unexpectedA)
					throw invalidHashHash::unexpectedToken(tok->location, name(), A);
				strAB = A->str() + B->str();
			}

			// producing universal character is undefined behavior
			if (A->previous && A->previous->str() == "\\")
			{
				if (strAB[0] == 'u' && strAB.size() == 5)
					throw invalidHashHash::universalCharacterUB(tok->location, name(), A, strAB);
				if (strAB[0] == 'U' && strAB.size() == 9)
					throw invalidHashHash::universalCharacterUB(tok->location, name(), A, strAB);
			}

			if (varargs && tokensB.empty() && tok->previous->str() == ",")
				output->deleteToken(A);
			else if (strAB != "," && macros.find(strAB) == macros.end())
			{
				A->setstr(strAB);
				for (Token* b = tokensB.front(); b; b = b->next)
					b->location = loc;
				output->takeTokens(tokensB);
			}
			else if (sameline(B, nextTok) && sameline(B, nextTok->next) && nextTok->op == '#' && nextTok->next->op == '#')
			{
				TokenList output2(files);
				output2.push_back(new Token(strAB, tok->location));
				nextTok = expandHashHash(&output2, loc, nextTok, macros, expandedmacros, parametertokens);
				output->deleteToken(A);
				output->takeTokens(output2);
			}
			else
			{
				output->deleteToken(A);
				TokenList tokens(files);
				tokens.push_back(new Token(strAB, tok->location));
				// for function like macros, push the (...)
				if (tokensB.empty() && sameline(B, B->next) && B->next->op == '(')
				{
					const MacroMap::const_iterator it = macros.find(strAB);
					if (it != macros.end() && expandedmacros.find(strAB) == expandedmacros.end() && it->second.functionLike())
					{
						const Token* const tok2 = appendTokens(&tokens, loc, B->next, macros, expandedmacros, parametertokens);
						if (tok2)
							nextTok = tok2->next;
					}
				}
				if (expandResult)
					expandToken(output, loc, tokens.cfront(), macros, expandedmacros, parametertokens);
				else
					output->takeTokens(tokens);
				for (Token* b = tokensB.front(); b; b = b->next)
					b->location = loc;
				output->takeTokens(tokensB);
			}
		}

		return nextTok;
	}

	bool Macro::isReplaced(const std::set<std::string>& expandedmacros) {
		// return true if size > 1
		std::set<std::string>::const_iterator it = expandedmacros.begin();
		if (it == expandedmacros.end())
			return false;
		++it;
		return (it != expandedmacros.end());
	}


