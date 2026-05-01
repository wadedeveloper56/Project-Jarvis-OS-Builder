#include "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

namespace WadeSpace::PreProcessor
{
    class Macro;
    using MacroMap = unordered_map<TokenString,Macro>;

    class Macro {
    public:
        explicit Macro(vector<string> &f) : nameTokDef(nullptr), valueToken(nullptr), endToken(nullptr), files(f), tokenListDefine(f), variadic(false), variadicOpt(false), optExpandValue(nullptr), optNoExpandValue(nullptr), valueDefinedInCode_(false) {}

        Macro(const Token *tok, vector<string> &f) : nameTokDef(nullptr), files(f), tokenListDefine(f), valueDefinedInCode_(true) {
            if (sameline(tok->previousSkipComments(), tok))
                throw runtime_error("bad macro syntax");
            if (tok->op != '#')
                throw runtime_error("bad macro syntax");
            const Token * const hashtok = tok;
            tok = tok->next;
            if (!tok || tok->str() != DEFINE)
                throw runtime_error("bad macro syntax");
            tok = tok->next;
            if (!tok || !tok->name || !sameline(hashtok,tok))
                throw runtime_error("bad macro syntax");
            if (!parseDefine(tok))
                throw runtime_error("bad macro syntax");
        }

        Macro(const string &name, const string &value, vector<string> &f) : nameTokDef(nullptr), files(f), tokenListDefine(f), valueDefinedInCode_(false) {
            const string def(name + ' ' + value);
            StdCharBufStream stream(reinterpret_cast<const unsigned char*>(def.data()), def.size());
            tokenListDefine.readfile(stream);
            if (!parseDefine(tokenListDefine.cfront()))
                throw runtime_error("bad macro syntax. macroname=" + name + " value=" + value);
        }

        Macro(const Macro &other) : nameTokDef(nullptr), files(other.files), tokenListDefine(other.files), valueDefinedInCode_(other.valueDefinedInCode_) {
            *this = other;
        }

        ~Macro() {
            delete optExpandValue;
            delete optNoExpandValue;
        }

        Macro &operator=(const Macro &other) {
            if (this != &other) {
                files = other.files;
                valueDefinedInCode_ = other.valueDefinedInCode_;
                if (other.tokenListDefine.empty())
                    parseDefine(other.nameTokDef);
                else {
                    tokenListDefine = other.tokenListDefine;
                    parseDefine(tokenListDefine.cfront());
                }
                usageList = other.usageList;
            }
            return *this;
        }

        bool valueDefinedInCode() const {
            return valueDefinedInCode_;
        }

        /**
         * Expand macro. This will recursively expand inner macros.
         * @param output     destination tokenlist
         * @param rawtok     macro token
         * @param macros     list of macros
         * @param inputFiles the input files
         * @return token after macro
         * @throw Can throw wrongNumberOfParameters or invalidHashHash
         */
        const Token * expand(TokenList * const output,
                             const Token * rawtok,
                             const MacroMap &macros,
                             vector<string> &inputFiles) const {
            set<TokenString> expandedmacros;

#ifdef SIMPLECPP_DEBUG_MACRO_EXPANSION
            cout << "expand " << name() << " " << locstring(rawtok->location) << endl;
#endif

            TokenList output2(inputFiles);

            if (functionLike() && rawtok->next && rawtok->next->op == '(') {
                // Copy macro call to a new tokenlist with no linebreaks
                const Token * const rawtok1 = rawtok;
                TokenList rawtokens2(inputFiles);
                rawtokens2.push_back(new Token(rawtok->str(), rawtok1->location, rawtok->whitespaceahead));
                rawtok = rawtok->next;
                rawtokens2.push_back(new Token(rawtok->str(), rawtok1->location, rawtok->whitespaceahead));
                rawtok = rawtok->next;
                int par = 1;
                while (rawtok && par > 0) {
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
            } else {
                rawtok = expand(&output2, rawtok->location, rawtok, macros, expandedmacros);
            }
            while (output2.cback() && rawtok) {
                unsigned int par = 0;
                Token* macro2tok = output2.back();
                while (macro2tok) {
                    if (macro2tok->op == '(') {
                        if (par==0)
                            break;
                        --par;
                    } else if (macro2tok->op == ')')
                        ++par;
                    macro2tok = macro2tok->previous;
                }
                if (macro2tok) { // macro2tok->op == '('
                    macro2tok = macro2tok->previous;
                    expandedmacros.insert(name());
                } else if (rawtok->op == '(')
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
                while (macro2tok) {
                    Token * const next = macro2tok->next;
                    rawtokens2.push_back(new Token(macro2tok->str(), loc));
                    output2.deleteToken(macro2tok);
                    macro2tok = next;
                }
                par = (rawtokens2.cfront() != rawtokens2.cback()) ? 1U : 0U;
                const Token *rawtok2 = rawtok;
                for (; rawtok2; rawtok2 = rawtok2->next) {
                    rawtokens2.push_back(new Token(rawtok2->str(), loc));
                    if (rawtok2->op == '(')
                        ++par;
                    else if (rawtok2->op == ')') {
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
        const TokenString &name() const {
            return nameTokDef->str();
        }

        /** location for macro definition */
        const Location &defineLocation() const {
            return nameTokDef->location;
        }

        /** how has this macro been used so far */
        const list<Location> &usage() const {
            return usageList;
        }

        /** is this a function like macro */
        bool functionLike() const {
            return nameTokDef->next &&
                   nameTokDef->next->op == '(' &&
                   sameline(nameTokDef, nameTokDef->next) &&
                   nameTokDef->next->location.col == nameTokDef->location.col + nameTokDef->str().size();
        }

        /** base class for errors */
        struct Error {
            Error(const Location &loc, const string &s) : location(loc), what(s) {}
            const Location location;
            const string what;
        };

        /** Struct that is thrown when macro is expanded with wrong number of parameters */
        struct wrongNumberOfParameters : public Error {
            wrongNumberOfParameters(const Location &loc, const string &macroName) : Error(loc, "Wrong number of parameters for macro \'" + macroName + "\'.") {}
        };

        /** Struct that is thrown when there is invalid ## usage */
        struct invalidHashHash : public Error {
            static inline string format(const string &macroName, const string &message) {
                return "Invalid ## usage when expanding \'" + macroName + "\': " + message;
            }

            invalidHashHash(const Location &loc, const string &macroName, const string &message)
                : Error(loc, format(macroName, message)) { }

            static inline invalidHashHash unexpectedToken(const Location &loc, const string &macroName, const Token *tokenA) {
                return invalidHashHash(loc, macroName, "Unexpected token '"+ tokenA->str()+"'");
            }

            static inline invalidHashHash cannotCombine(const Location &loc, const string &macroName, const Token *tokenA, const Token *tokenB) {
                return invalidHashHash(loc, macroName, "Combining '"+ tokenA->str()+ "' and '"+ tokenB->str() + "' yields an invalid token.");
            }

            static inline invalidHashHash unexpectedNewline(const Location &loc, const string &macroName) {
                return invalidHashHash(loc, macroName, "Unexpected newline");
            }

            static inline invalidHashHash universalCharacterUB(const Location &loc, const string &macroName, const Token* tokenA, const string& strAB) {
                return invalidHashHash(loc, macroName, "Combining '\\"+ tokenA->str()+ "' and '"+ strAB.substr(tokenA->str().size()) + "' yields universal character '\\" + strAB + "'. This is undefined behavior according to C standard chapter 5.1.1.2, paragraph 4.");
            }
        };
    private:
        /** Create new token where Token::macro is set for replaced tokens */
        Token *newMacroToken(const TokenString &str, const Location &loc, bool replaced, const Token *expandedFromToken=nullptr) const {
            Token *tok = new Token(str,loc);
            if (replaced)
                tok->macro = nameTokDef->str();
            if (expandedFromToken)
                tok->setExpandedFrom(expandedFromToken, this);
            return tok;
        }

        bool parseDefine(const Token *nametoken) {
            nameTokDef = nametoken;
            variadic = false;
            variadicOpt = false;
            optExpandValue = nullptr;
            optNoExpandValue = nullptr;
            if (!nameTokDef) {
                valueToken = endToken = nullptr;
                args.clear();
                return false;
            }

            // function like macro..
            if (functionLike()) {
                args.clear();
                const Token *argtok = nameTokDef->next->next;
                while (sameline(nametoken, argtok) && argtok->op != ')') {
                    if (argtok->str() == "..." &&
                        argtok->next && argtok->next->op == ')') {
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
                if (!sameline(nametoken, argtok)) {
                    endToken = argtok ? argtok->previous : argtok;
                    valueToken = nullptr;
                    return false;
                }
                valueToken = argtok ? argtok->next : nullptr;
            } else {
                args.clear();
                valueToken = nameTokDef->next;
            }

            if (!sameline(valueToken, nameTokDef))
                valueToken = nullptr;
            endToken = valueToken;
            while (sameline(endToken, nameTokDef)) {
                if (variadic && endToken->str() == "__VA_OPT__")
                    variadicOpt = true;
                endToken = endToken->next;
            }

            if (variadicOpt) {
                TokenList expandValue(files);
                TokenList noExpandValue(files);
                for (const Token *tok = valueToken; tok && tok != endToken;) {
                    if (tok->str() == "__VA_OPT__") {
                        if (!sameline(tok, tok->next) || tok->next->op != '(')
                            throw Error(tok->location, "In definition of '" + nameTokDef->str() + "': Missing opening parenthesis for __VA_OPT__");
                        tok = tok->next->next;
                        int par = 1;
                        while (tok && tok != endToken) {
                            if (tok->op == '(')
                                par++;
                            else if (tok->op == ')')
                                par--;
                            else if (tok->str() == "__VA_OPT__")
                                throw Error(tok->location, "In definition of '" + nameTokDef->str() + "': __VA_OPT__ cannot be nested");
                            if (par == 0) {
                                tok = tok->next;
                                break;
                            }
                            expandValue.push_back(new Token(*tok));
                            tok = tok->next;
                        }
                        if (par != 0) {
                            const Token *const lastTok = expandValue.back() ? expandValue.back() : valueToken->next;
                            throw Error(lastTok->location, "In definition of '" + nameTokDef->str() + "': Missing closing parenthesis for __VA_OPT__");
                        }
                    } else {
                        expandValue.push_back(new Token(*tok));
                        noExpandValue.push_back(new Token(*tok));
                        tok = tok->next;
                    }
                }
                optExpandValue = new TokenList(move(expandValue));
                optNoExpandValue = new TokenList(move(noExpandValue));
            }

            return true;
        }

        unsigned int getArgNum(const TokenString &str) const {
            unsigned int par = 0;
            while (par < args.size()) {
                if (str == args[par])
                    return par;
                par++;
            }
            return ~0U;
        }

        vector<const Token *> getMacroParameters(const Token *nameTokInst, bool calledInDefine) const {
            if (!nameTokInst->next || nameTokInst->next->op != '(' || !functionLike())
                return vector<const Token *>();

            vector<const Token *> parametertokens;
            parametertokens.push_back(nameTokInst->next);
            unsigned int par = 0U;
            for (const Token *tok = nameTokInst->next->next; calledInDefine ? sameline(tok, nameTokInst) : (tok != nullptr); tok = tok->next) {
                if (tok->op == '(')
                    ++par;
                else if (tok->op == ')') {
                    if (par == 0U) {
                        parametertokens.push_back(tok);
                        break;
                    }
                    --par;
                } else if (par == 0U && tok->op == ',' && (!variadic || parametertokens.size() < args.size()))
                    parametertokens.push_back(tok);
            }
            return parametertokens;
        }

        const Token *appendTokens(TokenList *tokens,
                                  const Location &rawloc,
                                  const Token * const lpar,
                                  const MacroMap &macros,
                                  const set<TokenString> &expandedmacros,
                                  const vector<const Token*> &parametertokens) const {
            if (!lpar || lpar->op != '(')
                return nullptr;
            unsigned int par = 0;
            const Token *tok = lpar;
            while (sameline(lpar, tok)) {
                if (tok->op == '#' && sameline(tok,tok->next) && tok->next->op == '#' && sameline(tok,tok->next->next)) {
                    // A##B => AB
                    tok = expandHashHash(tokens, rawloc, tok, macros, expandedmacros, parametertokens, false);
                } else if (tok->op == '#' && sameline(tok, tok->next) && tok->next->op != '#') {
                    tok = expandHash(tokens, rawloc, tok, expandedmacros, parametertokens);
                } else {
                    if (!expandArg(tokens, tok, rawloc, macros, expandedmacros, parametertokens)) {
                        tokens->push_back(new Token(*tok));
                        if (tok->macro.empty() && (par > 0 || tok->str() != "("))
                            tokens->back()->macro = name();
                    }

                    if (tok->op == '(')
                        ++par;
                    else if (tok->op == ')') {
                        --par;
                        if (par == 0U)
                            break;
                    }
                    tok = tok->next;
                }
            }
            for (Token *tok2 = tokens->front(); tok2; tok2 = tok2->next)
                tok2->location = lpar->location;
            return sameline(lpar,tok) ? tok : nullptr;
        }

        const Token * expand(TokenList * const output, const Location &loc, const Token * const nameTokInst, const MacroMap &macros, set<TokenString> expandedmacros) const {
            expandedmacros.insert(nameTokInst->str());

#ifdef SIMPLECPP_DEBUG_MACRO_EXPANSION
            cout << "  expand " << name() << " " << locstring(defineLocation()) << endl;
#endif

            usageList.push_back(loc);

            if (nameTokInst->str() == "__FILE__") {
                output->push_back(new Token('\"'+loc.file()+'\"', loc));
                return nameTokInst->next;
            }
            if (nameTokInst->str() == "__LINE__") {
                output->push_back(new Token(toString(loc.line), loc));
                return nameTokInst->next;
            }
            if (nameTokInst->str() == "__COUNTER__") {
                output->push_back(new Token(toString(usageList.size()-1U), loc));
                return nameTokInst->next;
            }

            const bool calledInDefine = (loc.fileIndex != nameTokInst->location.fileIndex ||
                                         loc.line < nameTokInst->location.line);

            vector<const Token*> parametertokens1(getMacroParameters(nameTokInst, calledInDefine));

            if (functionLike()) {
                // No arguments => not macro expansion
                if (nameTokInst->next && nameTokInst->next->op != '(') {
                    output->push_back(new Token(nameTokInst->str(), loc));
                    return nameTokInst->next;
                }

                // Parse macro-call
                if (variadic) {
                    if (parametertokens1.size() < args.size()) {
                        throw wrongNumberOfParameters(nameTokInst->location, name());
                    }
                } else {
                    if (parametertokens1.size() != args.size() + (args.empty() ? 2U : 1U))
                        throw wrongNumberOfParameters(nameTokInst->location, name());
                }
            }

            // If macro call uses __COUNTER__ then expand that first
            TokenList tokensparams(files);
            vector<const Token *> parametertokens2;
            if (!parametertokens1.empty()) {
                bool counter = false;
                for (const Token *tok = parametertokens1[0]; tok != parametertokens1.back(); tok = tok->next) {
                    if (tok->str() == "__COUNTER__") {
                        counter = true;
                        break;
                    }
                }

                const MacroMap::const_iterator m = macros.find("__COUNTER__");

                if (!counter || m == macros.end())
                    parametertokens2.swap(parametertokens1);
                else {
                    const Macro &counterMacro = m->second;
                    unsigned int par = 0;
                    for (const Token *tok = parametertokens1[0]; tok && par < parametertokens1.size(); tok = tok->next) {
                        if (tok->str() == "__COUNTER__") {
                            tokensparams.push_back(new Token(toString(counterMacro.usageList.size()), tok->location));
                            counterMacro.usageList.push_back(tok->location);
                        } else {
                            tokensparams.push_back(new Token(*tok));
                            if (tok == parametertokens1[par]) {
                                parametertokens2.push_back(tokensparams.cback());
                                par++;
                            }
                        }
                    }
                }
            }

            Token * const output_end_1 = output->back();

            const Token *valueToken2;
            const Token *endToken2;

            if (variadicOpt) {
                if (parametertokens2.size() > args.size() && parametertokens2[args.size() - 1]->next->op != ')')
                    valueToken2 = optExpandValue->cfront();
                else
                    valueToken2 = optNoExpandValue->cfront();
                endToken2 = nullptr;
            } else {
                valueToken2 = valueToken;
                endToken2 = endToken;
            }

            // expand
            for (const Token *tok = valueToken2; tok != endToken2;) {
                if (tok->op != '#') {
                    // A##B => AB
                    if (sameline(tok, tok->next) && tok->next && tok->next->op == '#' && tok->next->next && tok->next->next->op == '#') {
                        if (!sameline(tok, tok->next->next->next))
                            throw invalidHashHash::unexpectedNewline(tok->location, name());
                        if (variadic && tok->op == ',' && tok->next->next->next->str() == args.back()) {
                            Token *const comma = newMacroToken(tok->str(), loc, isReplaced(expandedmacros), tok);
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
                            for (const Token *tok2 = new_output.cfront(); tok2; tok2 = tok2->next)
                                output->push_back(newMacroToken(tok2->str(), loc, isReplaced(expandedmacros), tok2));
                        tok = tok->next;
                    } else {
                        tok = expandToken(output, loc, tok, macros, expandedmacros, parametertokens2);
                    }
                    continue;
                }

                int numberOfHash = 1;
                const Token *hashToken = tok->next;
                while (sameline(tok,hashToken) && hashToken->op == '#') {
                    hashToken = hashToken->next;
                    ++numberOfHash;
                }
                if (numberOfHash == 4 && tok->next->location.col + 1 == tok->next->next->location.col) {
                    // # ## #  => ##
                    output->push_back(newMacroToken("##", loc, isReplaced(expandedmacros)));
                    tok = hashToken;
                    continue;
                }

                if (numberOfHash >= 2 && tok->location.col + 1 < tok->next->location.col) {
                    output->push_back(new Token(*tok));
                    tok = tok->next;
                    continue;
                }

                tok = tok->next;
                if (tok == endToken2) {
                    output->push_back(new Token(*tok->previous));
                    break;
                }
                if (tok->op == '#') {
                    // A##B => AB
                    tok = expandHashHash(output, loc, tok->previous, macros, expandedmacros, parametertokens2);
                } else {
                    // #123 => "123"
                    tok = expandHash(output, loc, tok->previous, expandedmacros, parametertokens2);
                }
            }

            if (!functionLike()) {
                for (Token *tok = output_end_1 ? output_end_1->next : output->front(); tok; tok = tok->next) {
                    tok->macro = nameTokInst->str();
                }
            }

            if (!parametertokens1.empty())
                parametertokens1.swap(parametertokens2);

            return functionLike() ? parametertokens2.back()->next : nameTokInst->next;
        }

        const Token *recursiveExpandToken(TokenList *output, TokenList &temp, const Location &loc, const Token *tok, const MacroMap &macros, const set<TokenString> &expandedmacros, const vector<const Token*> &parametertokens) const {
            if (!(temp.cback() && temp.cback()->name && tok->next && tok->next->op == '(')) {
                output->takeTokens(temp);
                return tok->next;
            }

            if (!sameline(tok, tok->next)) {
                output->takeTokens(temp);
                return tok->next;
            }

            const MacroMap::const_iterator it = macros.find(temp.cback()->str());
            if (it == macros.end() || expandedmacros.find(temp.cback()->str()) != expandedmacros.end()) {
                output->takeTokens(temp);
                return tok->next;
            }

            const Macro &calledMacro = it->second;
            if (!calledMacro.functionLike()) {
                output->takeTokens(temp);
                return tok->next;
            }

            TokenList temp2(files);
            temp2.push_back(new Token(temp.cback()->str(), tok->location));

            const Token * const tok2 = appendTokens(&temp2, loc, tok->next, macros, expandedmacros, parametertokens);
            if (!tok2)
                return tok->next;
            output->takeTokens(temp);
            output->deleteToken(output->back());
            calledMacro.expand(output, loc, temp2.cfront(), macros, expandedmacros);
            return tok2->next;
        }

        const Token *expandToken(TokenList *output, const Location &loc, const Token *tok, const MacroMap &macros, const set<TokenString> &expandedmacros, const vector<const Token*> &parametertokens) const {
            // Not name..
            if (!tok->name) {
                output->push_back(newMacroToken(tok->str(), loc, true, tok));
                return tok->next;
            }

            // Macro parameter..
            {
                TokenList temp(files);
                if (expandArg(&temp, tok, loc, macros, expandedmacros, parametertokens)) {
                    if (tok->str() == "__VA_ARGS__" && temp.empty() && output->cback() && output->cback()->str() == "," &&
                        tok->nextSkipComments() && tok->nextSkipComments()->str() == ")")
                        output->deleteToken(output->back());
                    return recursiveExpandToken(output, temp, loc, tok, macros, expandedmacros, parametertokens);
                }
            }

            // Macro..
            const MacroMap::const_iterator it = macros.find(tok->str());
            if (it != macros.end() && expandedmacros.find(tok->str()) == expandedmacros.end()) {
                set<string> expandedmacros2(expandedmacros);
                expandedmacros2.insert(tok->str());

                const Macro &calledMacro = it->second;
                if (!calledMacro.functionLike()) {
                    TokenList temp(files);
                    calledMacro.expand(&temp, loc, tok, macros, expandedmacros);
                    return recursiveExpandToken(output, temp, loc, tok, macros, expandedmacros2, parametertokens);
                }
                if (!sameline(tok, tok->next)) {
                    output->push_back(newMacroToken(tok->str(), loc, true, tok));
                    return tok->next;
                }
                TokenList tokens(files);
                tokens.push_back(new Token(*tok));
                const Token * tok2 = nullptr;
                if (tok->next->op == '(')
                    tok2 = appendTokens(&tokens, loc, tok->next, macros, expandedmacros, parametertokens);
                else if (expandArg(&tokens, tok->next, loc, macros, expandedmacros, parametertokens)) {
                    tokens.front()->location = loc;
                    if (tokens.cfront()->next && tokens.cfront()->next->op == '(')
                        tok2 = tok->next;
                }
                if (!tok2) {
                    output->push_back(newMacroToken(tok->str(), loc, true, tok));
                    return tok->next;
                }
                TokenList temp(files);
                calledMacro.expand(&temp, loc, tokens.cfront(), macros, expandedmacros);
                return recursiveExpandToken(output, temp, loc, tok2, macros, expandedmacros, parametertokens);
            }

            if (tok->str() == DEFINED) {
                const Token * const tok2 = tok->next;
                const Token * const tok3 = tok2 ? tok2->next : nullptr;
                const Token * const tok4 = tok3 ? tok3->next : nullptr;
                const Token *defToken = nullptr;
                const Token *lastToken = nullptr;
                if (sameline(tok, tok4) && tok2->op == '(' && tok3->name && tok4->op == ')') {
                    defToken = tok3;
                    lastToken = tok4;
                } else if (sameline(tok,tok2) && tok2->name) {
                    defToken = lastToken = tok2;
                }
                if (defToken) {
                    string macroName = defToken->str();
                    if (defToken->next && defToken->next->op == '#' && defToken->next->next && defToken->next->next->op == '#' && defToken->next->next->next && defToken->next->next->next->name && sameline(defToken,defToken->next->next->next)) {
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

        bool expandArg(TokenList *output, const Token *tok, const vector<const Token*> &parametertokens) const {
            if (!tok->name)
                return false;

            const unsigned int argnr = getArgNum(tok->str());
            if (argnr >= args.size())
                return false;

            // empty variadic parameter
            if (variadic && argnr + 1U >= parametertokens.size())
                return true;

            for (const Token *partok = parametertokens[argnr]->next; partok != parametertokens[argnr + 1U]; partok = partok->next)
                output->push_back(new Token(*partok));

            return true;
        }

        bool expandArg(TokenList *output, const Token *tok, const Location &loc, const MacroMap &macros, const set<TokenString> &expandedmacros, const vector<const Token*> &parametertokens) const {
            if (!tok->name)
                return false;
            const unsigned int argnr = getArgNum(tok->str());
            if (argnr >= args.size())
                return false;
            if (variadic && argnr + 1U >= parametertokens.size()) // empty variadic parameter
                return true;
            for (const Token *partok = parametertokens[argnr]->next; partok != parametertokens[argnr + 1U];) {
                const MacroMap::const_iterator it = macros.find(partok->str());
                if (it != macros.end() && !partok->isExpandedFrom(&it->second) && (partok->str() == name() || expandedmacros.find(partok->str()) == expandedmacros.end())) {
                    set<TokenString> expandedmacros2(expandedmacros); // temporary amnesia to allow reexpansion of currently expanding macros during argument evaluation
                    expandedmacros2.erase(name());
                    partok = it->second.expand(output, loc, partok, macros, expandedmacros2);
                } else {
                    output->push_back(newMacroToken(partok->str(), loc, isReplaced(expandedmacros), partok));
                    output->back()->macro = partok->macro;
                    partok = partok->next;
                }
            }
            if (tok->whitespaceahead && output->back())
                output->back()->whitespaceahead = true;
            return true;
        }

        /**
         * Expand #X => "X"
         * @param output  destination tokenlist
         * @param loc     location for expanded token
         * @param tok     The # token
         * @param expandedmacros   set with expanded macros, with this macro
         * @param parametertokens  parameters given when expanding this macro
         * @return token after the X
         */
        const Token *expandHash(TokenList *output, const Location &loc, const Token *tok, const set<TokenString> &expandedmacros, const vector<const Token*> &parametertokens) const {
            TokenList tokenListHash(files);
            const MacroMap macros2; // temporarily bypass macro expansion
            tok = expandToken(&tokenListHash, loc, tok->next, macros2, expandedmacros, parametertokens);
            ostringstream ostr;
            ostr << '\"';
            for (const Token *hashtok = tokenListHash.cfront(), *next; hashtok; hashtok = next) {
                next = hashtok->next;
                ostr << hashtok->str();
                if (next && hashtok->whitespaceahead)
                    ostr << ' ';
            }
            ostr << '\"';
            output->push_back(newMacroToken(escapeString(ostr.str()), loc, isReplaced(expandedmacros)));
            return tok;
        }

        /**
         * Expand A##B => AB
         * The A should already be expanded. Call this when you reach the first # token
         * @param output  destination tokenlist
         * @param loc     location for expanded token
         * @param tok     first # token
         * @param macros  all macros
         * @param expandedmacros   set with expanded macros, with this macro
         * @param parametertokens  parameters given when expanding this macro
         * @param expandResult     expand ## result i.e. "AB"?
         * @return token after B
         */
        const Token *expandHashHash(TokenList *output, const Location &loc, const Token *tok, const MacroMap &macros, const set<TokenString> &expandedmacros, const vector<const Token*> &parametertokens, bool expandResult=true) const {
            Token *A = output->back();
            if (!A)
                throw invalidHashHash(tok->location, name(), "Missing first argument");
            if (!sameline(tok, tok->next) || !sameline(tok, tok->next->next))
                throw invalidHashHash::unexpectedNewline(tok->location, name());

            const bool canBeConcatenatedWithEqual = A->isOneOf("+-*/%&|^") || A->str() == "<<" || A->str() == ">>";
            const bool canBeConcatenatedStringOrChar = isStringLiteral_(A->str()) || isCharLiteral_(A->str());
            const bool unexpectedA = (!A->name && !A->number && !A->str().empty() && !canBeConcatenatedWithEqual && !canBeConcatenatedStringOrChar);

            Token * const B = tok->next->next;
            if (!B->name && !B->number && B->op && !B->isOneOf("#="))
                throw invalidHashHash::unexpectedToken(tok->location, name(), B);

            if ((canBeConcatenatedWithEqual && B->op != '=') ||
                (!canBeConcatenatedWithEqual && B->op == '='))
                throw invalidHashHash::cannotCombine(tok->location, name(), A, B);

            // Superficial check; more in-depth would in theory be possible _after_ expandArg
            if (canBeConcatenatedStringOrChar && (B->number || !B->name))
                throw invalidHashHash::cannotCombine(tok->location, name(), A, B);

            TokenList tokensB(files);
            const Token *nextTok = B->next;

            if (canBeConcatenatedStringOrChar) {
                if (unexpectedA)
                    throw invalidHashHash::unexpectedToken(tok->location, name(), A);

                // It seems clearer to handle this case separately even though the code is similar-ish, but we don't want to merge here.
                // TODO The question is whether the ## or varargs may still apply, and how to provoke?
                if (expandArg(&tokensB, B, parametertokens)) {
                    for (Token *b = tokensB.front(); b; b = b->next)
                        b->location = loc;
                } else {
                    tokensB.push_back(new Token(*B));
                    tokensB.back()->location = loc;
                }
                output->takeTokens(tokensB);
            } else {
                string strAB;

                const bool varargs = variadic && !args.empty() && B->str() == args[args.size()-1U];

                if (expandArg(&tokensB, B, parametertokens)) {
                    if (tokensB.empty())
                        strAB = A->str();
                    else if (varargs && A->op == ',')
                        strAB = ",";
                    else if (varargs && unexpectedA)
                        throw invalidHashHash::unexpectedToken(tok->location, name(), A);
                    else {
                        strAB = A->str() + tokensB.cfront()->str();
                        tokensB.deleteToken(tokensB.front());
                    }
                } else {
                    if (unexpectedA)
                        throw invalidHashHash::unexpectedToken(tok->location, name(), A);
                    strAB = A->str() + B->str();
                }

                // producing universal character is undefined behavior
                if (A->previous && A->previous->str() == "\\") {
                    if (strAB[0] == 'u' && strAB.size() == 5)
                        throw invalidHashHash::universalCharacterUB(tok->location, name(), A, strAB);
                    if (strAB[0] == 'U' && strAB.size() == 9)
                        throw invalidHashHash::universalCharacterUB(tok->location, name(), A, strAB);
                }

                if (varargs && tokensB.empty() && tok->previous->str() == ",")
                    output->deleteToken(A);
                else if (strAB != "," && macros.find(strAB) == macros.end()) {
                    A->setstr(strAB);
                    for (Token *b = tokensB.front(); b; b = b->next)
                        b->location = loc;
                    output->takeTokens(tokensB);
                } else if (sameline(B, nextTok) && sameline(B, nextTok->next) && nextTok->op == '#' && nextTok->next->op == '#') {
                    TokenList output2(files);
                    output2.push_back(new Token(strAB, tok->location));
                    nextTok = expandHashHash(&output2, loc, nextTok, macros, expandedmacros, parametertokens);
                    output->deleteToken(A);
                    output->takeTokens(output2);
                } else {
                    output->deleteToken(A);
                    TokenList tokens(files);
                    tokens.push_back(new Token(strAB, tok->location));
                    // for function like macros, push the (...)
                    if (tokensB.empty() && sameline(B,B->next) && B->next->op=='(') {
                        const MacroMap::const_iterator it = macros.find(strAB);
                        if (it != macros.end() && expandedmacros.find(strAB) == expandedmacros.end() && it->second.functionLike()) {
                            const Token * const tok2 = appendTokens(&tokens, loc, B->next, macros, expandedmacros, parametertokens);
                            if (tok2)
                                nextTok = tok2->next;
                        }
                    }
                    if (expandResult)
                        expandToken(output, loc, tokens.cfront(), macros, expandedmacros, parametertokens);
                    else
                        output->takeTokens(tokens);
                    for (Token *b = tokensB.front(); b; b = b->next)
                        b->location = loc;
                    output->takeTokens(tokensB);
                }
            }

            return nextTok;
        }

        static bool isReplaced(const set<string> &expandedmacros) {
            // return true if size > 1
            set<string>::const_iterator it = expandedmacros.begin();
            if (it == expandedmacros.end())
                return false;
            ++it;
            return (it != expandedmacros.end());
        }

        /** name token in definition */
        const Token *nameTokDef;

        /** arguments for macro */
        vector<TokenString> args;

        /** first token in replacement string */
        const Token *valueToken;

        /** token after replacement string */
        const Token *endToken;

        /** files */
        vector<string> &files;

        /** this is used for -D where the definition is not seen anywhere in code */
        TokenList tokenListDefine;

        /** usage of this macro */
        mutable list<Location> usageList;

        /** is macro variadic? */
        bool variadic;

        /** does the macro expansion have __VA_OPT__? */
        bool variadicOpt;

        /** Expansion value for varadic macros with __VA_OPT__ expanded and discarded respectively */
        const TokenList *optExpandValue;
        const TokenList *optNoExpandValue;

        /** was the value of this macro actually defined in the code? */
        bool valueDefinedInCode_;
    };
}

namespace simplecpp {

#ifdef __CYGWIN__
    string convertCygwinToWindowsPath(const string &cygwinPath)
    {
        string windowsPath;

        string::size_type pos = 0;
        if (cygwinPath.size() >= 11 && startsWith_(cygwinPath, "/cygdrive/")) {
            const unsigned char driveLetter = cygwinPath[10];
            if (isalpha(driveLetter)) {
                if (cygwinPath.size() == 11) {
                    windowsPath = toupper(driveLetter);
                    windowsPath += ":\\";   // volume root directory
                    pos = 11;
                } else if (cygwinPath[11] == '/') {
                    windowsPath = toupper(driveLetter);
                    windowsPath += ":";
                    pos = 11;
                }
            }
        }

        for (; pos < cygwinPath.size(); ++pos) {
            unsigned char c = cygwinPath[pos];
            if (c == '/')
                c = '\\';
            windowsPath += c;
        }

        return windowsPath;
    }
#endif
}

#ifdef SIMPLECPP_WINDOWS
static bool isAbsolutePath(const string &path)
{
    if (path.length() >= 3 && path[0] > 0 && isalpha(path[0]) && path[1] == ':' && (path[2] == '\\' || path[2] == '/'))
        return true;
    return path.length() > 1U && (path[0] == '/' || path[0] == '\\');
}
#else
static bool isAbsolutePath(const string &path)
{
    return path.length() > 1U && path[0] == '/';
}
#endif

namespace simplecpp {
    /**
     * perform path simplifications for . and ..
     */
    string simplifyPath(string path)
    {
        if (path.empty())
            return path;

        string::size_type pos;

        // replace backslash separators
        replace(path.begin(), path.end(), '\\', '/');

        const bool unc(path.compare(0,2,"//") == 0);

        // replace "//" with "/"
        pos = 0;
        while ((pos = path.find("//",pos)) != string::npos) {
            path.erase(pos,1);
        }

        // remove "./"
        pos = 0;
        while ((pos = path.find("./",pos)) != string::npos) {
            if (pos == 0 || path[pos - 1U] == '/')
                path.erase(pos,2);
            else
                pos += 2;
        }

        // remove trailing dot if path ends with "/."
        if (endsWith(path,"/."))
            path.erase(path.size()-1);

        // simplify ".."
        pos = 1; // don't simplify ".." if path starts with that
        while ((pos = path.find("/..", pos)) != string::npos) {
            // not end of path, then string must be "/../"
            if (pos + 3 < path.size() && path[pos + 3] != '/') {
                ++pos;
                continue;
            }
            // get previous subpath
            string::size_type pos1 = path.rfind('/', pos - 1U);
            if (pos1 == string::npos) {
                pos1 = 0;
            } else {
                pos1 += 1U;
            }
            const string previousSubPath = path.substr(pos1, pos - pos1);
            if (previousSubPath == "..") {
                // don't simplify
                ++pos;
            } else {
                // remove previous subpath and ".."
                path.erase(pos1, pos - pos1 + 4);
                if (path.empty())
                    path = ".";
                // update pos
                pos = (pos1 == 0) ? 1 : (pos1 - 1);
            }
        }

        // Remove trailing '/'?
        //if (path.size() > 1 && endsWith(path, "/"))
        //    path.erase(path.size()-1);

        if (unc)
            path = '/' + path;

        return path;
    }
}

static void simplifySizeof(TokenList &expr, const map<string, size_t> &sizeOfType)
{
    for (Token *tok = expr.front(); tok; tok = tok->next) {
        if (tok->str() != "sizeof")
            continue;
        Token *tok1 = tok->next;
        if (!tok1) {
            throw runtime_error("missing sizeof argument");
        }
        Token *tok2 = tok1->next;
        if (!tok2) {
            throw runtime_error("missing sizeof argument");
        }
        if (tok1->op == '(') {
            tok1 = tok1->next;
            while (tok2->op != ')') {
                tok2 = tok2->next;
                if (!tok2) {
                    throw runtime_error("invalid sizeof expression");
                }
            }
        }

        string type;
        for (Token *typeToken = tok1; typeToken != tok2; typeToken = typeToken->next) {
            if ((typeToken->str() == "unsigned" || typeToken->str() == "signed") && typeToken->next->name)
                continue;
            if (typeToken->str() == "*" && type.find('*') != string::npos)
                continue;
            if (!type.empty())
                type += ' ';
            type += typeToken->str();
        }

        const map<string, size_t>::const_iterator it = sizeOfType.find(type);
        if (it != sizeOfType.end())
            tok->setstr(toString(it->second));
        else
            continue;

        tok2 = tok2->next;
        while (tok->next != tok2)
            expr.deleteToken(tok->next);
    }
}

static bool isCpp17OrLater(const DUI &dui)
{
    const string std_ver = WadeSpace::PreProcessor::getCppStdString(dui.std);
    return !std_ver.empty() && (std_ver >= "201703L");
}

static bool isGnu(const DUI &dui)
{
    return dui.std.rfind("gnu", 0) != string::npos;
}

static string dirPath(const string& path, bool withTrailingSlash=true)
{
    const size_t lastSlash = path.find_last_of("\\/");
    if (lastSlash == string::npos) {
        return "";
    }
    return path.substr(0, lastSlash + (withTrailingSlash ? 1U : 0U));
}

static string openHeader(ifstream &f, const DUI &dui, const string &sourcefile, const string &header, bool systemheader);
static void simplifyHasInclude(TokenList &expr, const DUI &dui)
{
    if (!isCpp17OrLater(dui) && !isGnu(dui))
        return;

    for (Token *tok = expr.front(); tok; tok = tok->next) {
        if (tok->str() != HAS_INCLUDE)
            continue;
        Token *tok1 = tok->next;
        if (!tok1) {
            throw runtime_error("missing __has_include argument");
        }
        Token *tok2 = tok1->next;
        if (!tok2) {
            throw runtime_error("missing __has_include argument");
        }
        if (tok1->op == '(') {
            tok1 = tok1->next;
            while (tok2->op != ')') {
                tok2 = tok2->next;
                if (!tok2) {
                    throw runtime_error("invalid __has_include expression");
                }
            }
        }

        const string &sourcefile = tok->location.file();
        const bool systemheader = (tok1 && tok1->op == '<');
        string header;
        if (systemheader) {
            Token *tok3 = tok1->next;
            if (!tok3) {
                throw runtime_error("missing __has_include closing angular bracket");
            }
            while (tok3->op != '>') {
                tok3 = tok3->next;
                if (!tok3) {
                    throw runtime_error("invalid __has_include expression");
                }
            }

            for (Token *headerToken = tok1->next; headerToken != tok3; headerToken = headerToken->next)
                header += headerToken->str();
        } else {
            header = tok1->str().substr(1U, tok1->str().size() - 2U);
        }
        ifstream f;
        const string header2 = openHeader(f,dui,sourcefile,header,systemheader);
        tok->setstr(header2.empty() ? "0" : "1");

        tok2 = tok2->next;
        while (tok->next != tok2)
            expr.deleteToken(tok->next);
    }
}

static const char * const altopData[] = {"and","or","bitand","bitor","compl","not","not_eq","xor"};
static const set<string> altop(&altopData[0], &altopData[8]);
static void simplifyName(TokenList &expr)
{
    for (Token *tok = expr.front(); tok; tok = tok->next) {
        if (tok->name) {
            if (altop.find(tok->str()) != altop.end()) {
                bool alt;
                if (tok->str() == "not" || tok->str() == "compl") {
                    alt = isAlternativeUnaryOp(tok,tok->str());
                } else {
                    alt = isAlternativeBinaryOp(tok,tok->str());
                }
                if (alt)
                    continue;
            }
            if (tok->next && tok->next->str() == "(")
                throw runtime_error("undefined function-like macro invocation: " + tok->str() + "( ... )");
            tok->setstr("0");
        }
    }
}

/*
 * Reads at least minlen and at most maxlen digits (inc. prefix) in base base
 * from s starting at position pos and converts them to a
 * unsigned long long value, updating pos to point to the first
 * unused element of s.
 * Returns ULLONG_MAX if the result is not representable and
 * throws if the above requirements were not possible to satisfy.
 */
static unsigned long long stringToULLbounded(
    const string& s,
    size_t& pos,
    int base = 0,
    ptrdiff_t minlen = 1,
    size_t maxlen = string::npos
)
{
    const string sub = s.substr(pos, maxlen);
    const char * const start = sub.c_str();
    char* end;
    const unsigned long long value = strtoull(start, &end, base);
    pos += end - start;
    if (end - start < minlen)
        throw runtime_error("expected digit");
    return value;
}

/* Converts character literal (including prefix, but not ud-suffix)
 * to long long value.
 *
 * Assumes ASCII-compatible single-byte encoded str for narrow literals
 * and UTF-8 otherwise.
 *
 * For target assumes
 * - execution character set encoding matching str
 * - UTF-32 execution wide-character set encoding
 * - requirements for __STDC_UTF_16__, __STDC_UTF_32__ and __STDC_ISO_10646__ satisfied
 * - char16_t is 16bit wide
 * - char32_t is 32bit wide
 * - wchar_t is 32bit wide and unsigned
 * - matching char signedness to host
 * - matching sizeof(int) to host
 *
 * For host assumes
 * - ASCII-compatible execution character set
 *
 * For host and target assumes
 * - CHAR_BIT == 8
 * - two's complement
 *
 * Implements multi-character narrow literals according to GCC's behavior,
 * except multi code unit universal character names are not supported.
 * Multi-character wide literals are not supported.
 * Limited support of universal character names for non-UTF-8 execution character set encodings.
 */
long long characterLiteralToLL(const string& str)
{
    // default is wide/utf32
    bool narrow = false;
    bool utf8 = false;
    bool utf16 = false;

    size_t pos;

    if (!str.empty() && str[0] == '\'') {
        narrow = true;
        pos = 1;
    } else if (str.size() >= 2 && str[0] == 'u' && str[1] == '\'') {
        utf16 = true;
        pos = 2;
    } else if (str.size() >= 3 && str[0] == 'u' && str[1] == '8' && str[2] == '\'') {
        utf8 = true;
        pos = 3;
    } else if (str.size() >= 2 && (str[0] == 'L' || str[0] == 'U') && str[1] == '\'') {
        pos = 2;
    } else
        throw runtime_error("expected a character literal");

    unsigned long long multivalue = 0;

    size_t nbytes = 0;

    while (pos + 1 < str.size()) {
        if (str[pos] == '\'' || str[pos] == '\n')
            throw runtime_error("raw single quotes and newlines not allowed in character literals");

        if (nbytes >= 1 && !narrow)
            throw runtime_error("multiple characters only supported in narrow character literals");

        unsigned long long value;

        if (str[pos] == '\\') {
            pos++;
            const char escape = str[pos++];

            if (pos >= str.size())
                throw runtime_error("unexpected end of character literal");

            switch (escape) {
            // obscure GCC extensions
            case '%':
            case '(':
            case '[':
            case '{':
            // standard escape sequences
            case '\'':
            case '"':
            case '?':
            case '\\':
                value = static_cast<unsigned char>(escape);
                break;

            case 'a':
                value = static_cast<unsigned char>('\a');
                break;
            case 'b':
                value = static_cast<unsigned char>('\b');
                break;
            case 'f':
                value = static_cast<unsigned char>('\f');
                break;
            case 'n':
                value = static_cast<unsigned char>('\n');
                break;
            case 'r':
                value = static_cast<unsigned char>('\r');
                break;
            case 't':
                value = static_cast<unsigned char>('\t');
                break;
            case 'v':
                value = static_cast<unsigned char>('\v');
                break;

            // GCC extension for ESC character
            case 'e':
            case 'E':
                value = static_cast<unsigned char>('\x1b');
                break;

            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
                // octal escape sequences consist of 1 to 3 digits
                value = stringToULLbounded(str, --pos, 8, 1, 3);
                break;

            case 'x':
                // hexadecimal escape sequences consist of at least 1 digit
                value = stringToULLbounded(str, pos, 16);
                break;

            case 'u':
            case 'U': {
                // universal character names have exactly 4 or 8 digits
                const size_t ndigits = (escape == 'u' ? 4 : 8);
                value = stringToULLbounded(str, pos, 16, ndigits, ndigits);

                // UTF-8 encodes code points above 0x7f in multiple code units
                // code points above 0x10ffff are not allowed
                if (((narrow || utf8) && value > 0x7f) || (utf16 && value > 0xffff) || value > 0x10ffff)
                    throw runtime_error("code point too large");

                if (value >= 0xd800 && value <= 0xdfff)
                    throw runtime_error("surrogate code points not allowed in universal character names");

                break;
            }

            default:
                throw runtime_error("invalid escape sequence");
            }
        } else {
            value = static_cast<unsigned char>(str[pos++]);

            if (!narrow && value >= 0x80) {
                // Assuming this is a UTF-8 encoded code point.
                // This decoder may not completely validate the input.
                // Noncharacters are neither rejected nor replaced.

                int additional_bytes;
                if (value >= 0xf5)  // higher values would result in code points above 0x10ffff
                    throw runtime_error("assumed UTF-8 encoded source, but sequence is invalid");
                if (value >= 0xf0)
                    additional_bytes = 3;
                else if (value >= 0xe0)
                    additional_bytes = 2;
                else if (value >= 0xc2) // 0xc0 and 0xc1 are always overlong 2-bytes encodings
                    additional_bytes = 1;
                else
                    throw runtime_error("assumed UTF-8 encoded source, but sequence is invalid");

                value &= (1 << (6 - additional_bytes)) - 1;

                while (additional_bytes--) {
                    if (pos + 1 >= str.size())
                        throw runtime_error("assumed UTF-8 encoded source, but character literal ends unexpectedly");

                    const unsigned char c = str[pos++];

                    if (((c >> 6) != 2)    // ensure c has form 0xb10xxxxxx
                        || (!value && additional_bytes == 1 && c < 0xa0)    // overlong 3-bytes encoding
                        || (!value && additional_bytes == 2 && c < 0x90))   // overlong 4-bytes encoding
                        throw runtime_error("assumed UTF-8 encoded source, but sequence is invalid");

                    value = (value << 6) | (c & ((1 << 7) - 1));
                }

                if (value >= 0xd800 && value <= 0xdfff)
                    throw runtime_error("assumed UTF-8 encoded source, but sequence is invalid");

                if ((utf8 && value > 0x7f) || (utf16 && value > 0xffff) || value > 0x10ffff)
                    throw runtime_error("code point too large");
            }
        }

        if (((narrow || utf8) && value > numeric_limits<unsigned char>::max()) || (utf16 && value >> 16) || value >> 32)
            throw runtime_error("numeric escape sequence too large");

        multivalue <<= CHAR_BIT;
        multivalue |= value;
        nbytes++;
    }

    if (pos + 1 != str.size() || str[pos] != '\'')
        throw runtime_error("missing closing quote in character literal");

    if (!nbytes)
        throw runtime_error("empty character literal");

    // ordinary narrow character literal's value is determined by (possibly signed) char
    if (narrow && nbytes == 1)
        return static_cast<char>(multivalue);

    // while multi-character literal's value is determined by (signed) int
    if (narrow)
        return static_cast<int>(multivalue);

    // All other cases are unsigned. Since long long is at least 64bit wide,
    // while the literals at most 32bit wide, the conversion preserves all values.
    return multivalue;
}

static void simplifyNumbers(TokenList &expr)
{
    for (Token *tok = expr.front(); tok; tok = tok->next) {
        if (tok->str().size() == 1U)
            continue;
        if (tok->str().compare(0,2,"0x") == 0)
            tok->setstr(toString(stringToULL(tok->str())));
        else if (!tok->number && tok->str().find('\'') != string::npos)
            tok->setstr(toString(WadeSpace::PreProcessor::characterLiteralToLL(tok->str())));
    }
}

static void simplifyComments(TokenList &expr)
{
    for (Token *tok = expr.front(); tok;) {
        Token * const d = tok;
        tok = tok->next;
        if (d->comment)
            expr.deleteToken(d);
    }
}

static long long evaluate(TokenList &expr, const DUI &dui, const map<string, size_t> &sizeOfType)
{
    simplifyComments(expr);
    simplifySizeof(expr, sizeOfType);
    simplifyHasInclude(expr, dui);
    simplifyName(expr);
    simplifyNumbers(expr);
    expr.constFold();
    // TODO: handle invalid expressions
    return expr.cfront() && expr.cfront() == expr.cback() && expr.cfront()->number ? stringToLL(expr.cfront()->str()) : 0LL;
}

static const Token *gotoNextLine(const Token *tok)
{
    const unsigned int line = tok->location.line;
    const unsigned int file = tok->location.fileIndex;
    while (tok && tok->location.line == line && tok->location.fileIndex == file)
        tok = tok->next;
    return tok;
}

#ifdef SIMPLECPP_WINDOWS

class NonExistingFilesCache {
public:
    NonExistingFilesCache() {}

    bool contains(const string& path) {
        lock_guard<mutex> lock(m_mutex);
        return (m_pathSet.find(path) != m_pathSet.end());
    }

    void add(const string& path) {
        lock_guard<mutex> lock(m_mutex);
        m_pathSet.insert(path);
    }

    void clear() {
        lock_guard<mutex> lock(m_mutex);
        m_pathSet.clear();
    }

private:
    set<string> m_pathSet;
    mutex m_mutex;
};

static NonExistingFilesCache nonExistingFilesCache;

#endif

static string openHeaderDirect(ifstream &f, const string &path)
{
#ifdef SIMPLECPP_WINDOWS
    if (nonExistingFilesCache.contains(path))
        return "";  // file is known not to exist, skip expensive file open call
#endif
    f.open(path.c_str());
    if (f.is_open())
        return path;
#ifdef SIMPLECPP_WINDOWS
    nonExistingFilesCache.add(path);
#endif
    return "";
}

static string openHeader(ifstream &f, const DUI &dui, const string &sourcefile, const string &header, bool systemheader)
{
    if (isAbsolutePath(header))
        return openHeaderDirect(f, simplifyPath(header));

    // prefer first to search the header relatively to source file if found, when not a system header
    if (!systemheader) {
        string path = openHeaderDirect(f, simplifyPath(dirPath(sourcefile) + header));
        if (!path.empty()) {
            return path;
        }
    }

    // search the header on the include paths (provided by the flags "-I...")
    for (const auto &includePath : dui.includePaths) {
        string path = openHeaderDirect(f, simplifyPath(includePath + "/" + header));
        if (!path.empty())
            return path;
    }
    return "";
}

pair<FileData *, bool> FileDataCache::tryload(FileDataCache::name_map_type::iterator &name_it, const DUI &dui, vector<string> &filenames, OutputList *outputList)
{
    const string &path = name_it->first;
    FileID fileId;

    if (!getFileId(path, fileId))
        return {nullptr, false};

    const auto id_it = mIdMap.find(fileId);
    if (id_it != mIdMap.end()) {
        name_it->second = id_it->second;
        return {id_it->second, false};
    }

    ifstream f(path);
    FileData *const data = new FileData {path, TokenList(f, filenames, path, outputList)};

    if (dui.removeComments)
        data->tokens.removeComments();

    name_it->second = data;
    mIdMap.emplace(fileId, data);
    mData.emplace_back(data);

    return {data, true};
}

pair<FileData *, bool> FileDataCache::get(const string &sourcefile, const string &header, const DUI &dui, bool systemheader, vector<string> &filenames, OutputList *outputList)
{
    if (isAbsolutePath(header)) {
        auto ins = mNameMap.emplace(simplifyPath(header), nullptr);

        if (ins.second) {
            const auto ret = tryload(ins.first, dui, filenames, outputList);
            if (ret.first != nullptr) {
                return ret;
            }
        } else {
            return {ins.first->second, false};
        }

        return {nullptr, false};
    }

    if (!systemheader) {
        auto ins = mNameMap.emplace(simplifyPath(dirPath(sourcefile) + header), nullptr);

        if (ins.second) {
            const auto ret = tryload(ins.first, dui, filenames, outputList);
            if (ret.first != nullptr) {
                return ret;
            }
        } else if (ins.first->second != nullptr) {
            return {ins.first->second, false};
        }
    }

    for (const auto &includePath : dui.includePaths) {
        auto ins = mNameMap.emplace(simplifyPath(includePath + "/" + header), nullptr);

        if (ins.second) {
            const auto ret = tryload(ins.first, dui, filenames, outputList);
            if (ret.first != nullptr) {
                return ret;
            }
        } else if (ins.first->second != nullptr) {
            return {ins.first->second, false};
        }
    }

    return {nullptr, false};
}

bool FileDataCache::getFileId(const string &path, FileID &id)
{
#ifdef SIMPLECPP_WINDOWS
    HANDLE hFile = CreateFileA(path.c_str(), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE)
        return false;

    const BOOL ret = GetFileInformationByHandleEx(hFile, FileIdInfo, &id.fileIdInfo, sizeof(id.fileIdInfo));

    CloseHandle(hFile);

    return ret == TRUE;
#else
    struct stat statbuf;

    if (stat(path.c_str(), &statbuf) != 0)
        return false;

    id.dev = statbuf.st_dev;
    id.ino = statbuf.st_ino;

    return true;
#endif
}

FileDataCache load(const TokenList &rawtokens, vector<string> &filenames, const DUI &dui, OutputList *outputList)
{
#ifdef SIMPLECPP_WINDOWS
    if (dui.clearIncludeCache)
        nonExistingFilesCache.clear();
#endif

    FileDataCache cache;

    list<const Token *> filelist;

    // -include files
    for (list<string>::const_iterator it = dui.includes.begin(); it != dui.includes.end(); ++it) {
        const string &filename = *it;

        const auto loadResult = cache.get("", filename, dui, false, filenames, outputList);
        const bool loaded = loadResult.second;
        FileData *const filedata = loadResult.first;

        if (filedata == nullptr) {
            if (outputList) {
                Output err(filenames);
                err.type = Output::EXPLICIT_INCLUDE_NOT_FOUND;
                err.location = Location(filenames);
                err.msg = "Can not open include file '" + filename + "' that is explicitly included.";
                outputList->push_back(err);
            }
            continue;
        }

        if (!loaded)
            continue;

        if (!filedata->tokens.front())
            continue;

        if (dui.removeComments)
            filedata->tokens.removeComments();

        filelist.push_back(filedata->tokens.front());
    }

    for (const Token *rawtok = rawtokens.cfront(); rawtok || !filelist.empty(); rawtok = rawtok ? rawtok->next : nullptr) {
        if (rawtok == nullptr) {
            rawtok = filelist.back();
            filelist.pop_back();
        }

        if (rawtok->op != '#' || sameline(rawtok->previousSkipComments(), rawtok))
            continue;

        rawtok = rawtok->nextSkipComments();
        if (!rawtok || rawtok->str() != INCLUDE)
            continue;

        const string &sourcefile = rawtok->location.file();

        const Token * const htok = rawtok->nextSkipComments();
        if (!sameline(rawtok, htok))
            continue;

        const bool systemheader = (htok->str()[0] == '<');
        const string header(htok->str().substr(1U, htok->str().size() - 2U));

        FileData *const filedata = cache.get(sourcefile, header, dui, systemheader, filenames, outputList).first;
        if (!filedata)
            continue;

        if (dui.removeComments)
            filedata->tokens.removeComments();

        if (filedata->tokens.front())
            filelist.push_back(filedata->tokens.front());
    }

    return cache;
}

static bool preprocessToken(TokenList &output, const Token **tok1, MacroMap &macros, vector<string> &files, OutputList *outputList)
{
    const Token * const tok = *tok1;
    const MacroMap::const_iterator it = macros.find(tok->str());
    if (it != macros.end()) {
        TokenList value(files);
        try {
            *tok1 = it->second.expand(&value, tok, macros, files);
        } catch (Macro::Error &err) {
            if (outputList) {
                Output out(files);
                out.type = Output::SYNTAX_ERROR;
                out.location = err.location;
                out.msg = "failed to expand \'" + tok->str() + "\', " + err.what;
                outputList->push_back(out);
            }
            return false;
        }
        output.takeTokens(value);
    } else {
        if (!tok->comment)
            output.push_back(new Token(*tok));
        *tok1 = tok->next;
    }
    return true;
}

static void getLocaltime(struct tm &ltime)
{
    time_t t;
    time(&t);
#ifndef _WIN32
    // NOLINTNEXTLINE(misc-include-cleaner) - false positive
    localtime_r(&t, &ltime);
#else
    localtime_s(&ltime, &t);
#endif
}

static string getDateDefine(const struct tm *timep)
{
    char buf[] = "??? ?? ????";
    strftime(buf, sizeof(buf), "%b %d %Y", timep);
    return string("\"").append(buf).append("\"");
}

static string getTimeDefine(const struct tm *timep)
{
    char buf[] = "??:??:??";
    strftime(buf, sizeof(buf), "%H:%M:%S", timep);
    return string("\"").append(buf).append("\"");
}

void preprocess(TokenList &output, const TokenList &rawtokens, vector<string> &files, FileDataCache &cache, const DUI &dui, OutputList *outputList, list<MacroUsage> *macroUsage, list<IfCond> *ifCond)
{
#ifdef SIMPLECPP_WINDOWS
    if (dui.clearIncludeCache)
        nonExistingFilesCache.clear();
#endif

    map<string, size_t> sizeOfType(rawtokens.sizeOfType);
    sizeOfType.insert(make_pair("char", sizeof(char)));
    sizeOfType.insert(make_pair("short", sizeof(short)));
    sizeOfType.insert(make_pair("short int", sizeOfType["short"]));
    sizeOfType.insert(make_pair("int", sizeof(int)));
    sizeOfType.insert(make_pair("long", sizeof(long)));
    sizeOfType.insert(make_pair("long int", sizeOfType["long"]));
    sizeOfType.insert(make_pair("long long", sizeof(long long)));
    sizeOfType.insert(make_pair("float", sizeof(float)));
    sizeOfType.insert(make_pair("double", sizeof(double)));
    sizeOfType.insert(make_pair("long double", sizeof(long double)));
    sizeOfType.insert(make_pair("char *", sizeof(char *)));
    sizeOfType.insert(make_pair("short *", sizeof(short *)));
    sizeOfType.insert(make_pair("short int *", sizeOfType["short *"]));
    sizeOfType.insert(make_pair("int *", sizeof(int *)));
    sizeOfType.insert(make_pair("long *", sizeof(long *)));
    sizeOfType.insert(make_pair("long int *", sizeOfType["long *"]));
    sizeOfType.insert(make_pair("long long *", sizeof(long long *)));
    sizeOfType.insert(make_pair("float *", sizeof(float *)));
    sizeOfType.insert(make_pair("double *", sizeof(double *)));
    sizeOfType.insert(make_pair("long double *", sizeof(long double *)));

    // use a dummy vector for the macros because as this is not part of the file and would add an empty entry - e.g. /usr/include/poll.h
    vector<string> dummy;

    const bool hasInclude = isCpp17OrLater(dui) || isGnu(dui);
    MacroMap macros;
    bool strictAnsiDefined = false;
    for (list<string>::const_iterator it = dui.defines.begin(); it != dui.defines.end(); ++it) {
        const string &macrostr = *it;
        const string::size_type eq = macrostr.find('=');
        const string::size_type par = macrostr.find('(');
        const string macroname = macrostr.substr(0, min(eq,par));
        if (macroname == "__STRICT_ANSI__")
            strictAnsiDefined = true;
        if (dui.undefined.find(macroname) != dui.undefined.end())
            continue;
        const string lhs(macrostr.substr(0,eq));
        const string rhs(eq==string::npos ? string("1") : macrostr.substr(eq+1));
        const Macro macro(lhs, rhs, dummy);
        macros.insert(pair<TokenString,Macro>(macro.name(), macro));
    }

    const bool strictAnsiUndefined = dui.undefined.find("__STRICT_ANSI__") != dui.undefined.cend();
    if (!isGnu(dui) && !strictAnsiDefined && !strictAnsiUndefined)
        macros.insert(pair<TokenString, Macro>("__STRICT_ANSI__", Macro("__STRICT_ANSI__", "1", dummy)));

    macros.insert(make_pair("__FILE__", Macro("__FILE__", "__FILE__", dummy)));
    macros.insert(make_pair("__LINE__", Macro("__LINE__", "__LINE__", dummy)));
    macros.insert(make_pair("__COUNTER__", Macro("__COUNTER__", "__COUNTER__", dummy)));
    struct tm ltime = {};
    getLocaltime(ltime);
    macros.insert(make_pair("__DATE__", Macro("__DATE__", getDateDefine(&ltime), dummy)));
    macros.insert(make_pair("__TIME__", Macro("__TIME__", getTimeDefine(&ltime), dummy)));

    if (!dui.std.empty()) {
        const cstd_t c_std = WadeSpace::PreProcessor::getCStd(dui.std);
        if (c_std != CUnknown) {
            const string std_def = WadeSpace::PreProcessor::getCStdString(c_std);
            if (!std_def.empty())
                macros.insert(make_pair("__STDC_VERSION__", Macro("__STDC_VERSION__", std_def, dummy)));
        } else {
            const cppstd_t cpp_std = WadeSpace::PreProcessor::getCppStd(dui.std);
            if (cpp_std == CPPUnknown) {
                if (outputList) {
                    Output err(files);
                    err.type = Output::DUI_ERROR;
                    err.msg = "unknown standard specified: '" + dui.std + "'";
                    outputList->push_back(err);
                }
                output.clear();
                return;
            }
            const string std_def = WadeSpace::PreProcessor::getCppStdString(cpp_std);
            if (!std_def.empty())
                macros.insert(make_pair("__cplusplus", Macro("__cplusplus", std_def, dummy)));
        }
    }

    // True => code in current #if block should be kept
    // ElseIsTrue => code in current #if block should be dropped. the code in the #else should be kept.
    // AlwaysFalse => drop all code in #if and #else
    enum IfState { True, ElseIsTrue, AlwaysFalse };
    stack<int> ifstates;
    stack<const Token *> iftokens;
    ifstates.push(True);

    stack<const Token *> includetokenstack;

    set<string> pragmaOnce;

    includetokenstack.push(rawtokens.cfront());
    for (list<string>::const_iterator it = dui.includes.begin(); it != dui.includes.end(); ++it) {
        const FileData *const filedata = cache.get("", *it, dui, false, files, outputList).first;
        if (filedata != nullptr && filedata->tokens.cfront() != nullptr)
            includetokenstack.push(filedata->tokens.cfront());
    }

    map<string, list<Location> > maybeUsedMacros;

    for (const Token *rawtok = nullptr; rawtok || !includetokenstack.empty();) {
        if (rawtok == nullptr) {
            rawtok = includetokenstack.top();
            includetokenstack.pop();
            continue;
        }

        if (rawtok->op == '#' && !sameline(rawtok->previousSkipComments(), rawtok)) {
            if (!sameline(rawtok, rawtok->next)) {
                rawtok = rawtok->next;
                continue;
            }
            rawtok = rawtok->next;
            if (!rawtok->name) {
                rawtok = gotoNextLine(rawtok);
                continue;
            }

            if (ifstates.size() <= 1U && (rawtok->str() == ELIF || rawtok->str() == ELSE || rawtok->str() == ENDIF)) {
                if (outputList) {
                    Output err(files);
                    err.type = Output::SYNTAX_ERROR;
                    err.location = rawtok->location;
                    err.msg = "#" + rawtok->str() + " without #if";
                    outputList->push_back(err);
                }
                output.clear();
                return;
            }

            if (ifstates.top() == True && (rawtok->str() == ERROR || rawtok->str() == WARNING)) {
                if (outputList) {
                    Output err(rawtok->location.files);
                    err.type = rawtok->str() == ERROR ? Output::ERROR : Output::WARNING;
                    err.location = rawtok->location;
                    for (const Token *tok = rawtok->next; tok && sameline(rawtok,tok); tok = tok->next) {
                        if (!err.msg.empty() && isNameChar(tok->str()[0]))
                            err.msg += ' ';
                        err.msg += tok->str();
                    }
                    err.msg = '#' + rawtok->str() + ' ' + err.msg;
                    outputList->push_back(err);
                }
                if (rawtok->str() == ERROR) {
                    output.clear();
                    return;
                }
            }

            if (rawtok->str() == DEFINE) {
                if (ifstates.top() != True)
                    continue;
                try {
                    const Macro &macro = Macro(rawtok->previous, files);
                    if (dui.undefined.find(macro.name()) == dui.undefined.end()) {
                        const MacroMap::iterator it = macros.find(macro.name());
                        if (it == macros.end())
                            macros.insert(pair<TokenString, Macro>(macro.name(), macro));
                        else
                            it->second = macro;
                    }
                } catch (const runtime_error &) {
                    if (outputList) {
                        Output err(files);
                        err.type = Output::SYNTAX_ERROR;
                        err.location = rawtok->location;
                        err.msg = "Failed to parse #define";
                        outputList->push_back(err);
                    }
                    output.clear();
                    return;
                } catch (Macro::Error &err) {
                    if (outputList) {
                        Output out(files);
                        out.type = Output::SYNTAX_ERROR;
                        out.location = err.location;
                        out.msg = "Failed to parse #define, " + err.what;
                        outputList->push_back(out);
                    }
                    output.clear();
                    return;
                }
            } else if (ifstates.top() == True && rawtok->str() == INCLUDE) {
                TokenList inc1(files);
                for (const Token *inctok = rawtok->next; sameline(rawtok,inctok); inctok = inctok->next) {
                    if (!inctok->comment)
                        inc1.push_back(new Token(*inctok));
                }
                TokenList inc2(files);
                if (!inc1.empty() && inc1.cfront()->name) {
                    const Token *inctok = inc1.cfront();
                    if (!preprocessToken(inc2, &inctok, macros, files, outputList)) {
                        output.clear();
                        return;
                    }
                } else {
                    inc2.takeTokens(inc1);
                }

                if (!inc1.empty() && !inc2.empty() && inc2.cfront()->op == '<' && inc2.cback()->op == '>') {
                    TokenString hdr;
                    // TODO: Sometimes spaces must be added in the string
                    // Somehow preprocessToken etc must be told that the location should be source location not destination location
                    for (const Token *tok = inc2.cfront(); tok; tok = tok->next) {
                        hdr += tok->str();
                    }
                    inc2.clear();
                    inc2.push_back(new Token(hdr, inc1.cfront()->location));
                    inc2.front()->op = '<';
                }

                if (inc2.empty() || inc2.cfront()->str().size() <= 2U) {
                    if (outputList) {
                        Output err(files);
                        err.type = Output::SYNTAX_ERROR;
                        err.location = rawtok->location;
                        err.msg = "No header in #include";
                        outputList->push_back(err);
                    }
                    output.clear();
                    return;
                }

                const Token * const inctok = inc2.cfront();

                const bool systemheader = (inctok->str()[0] == '<');
                const string header(inctok->str().substr(1U, inctok->str().size() - 2U));
                const FileData *const filedata = cache.get(rawtok->location.file(), header, dui, systemheader, files, outputList).first;
                if (filedata == nullptr) {
                    if (outputList) {
                        Output out(files);
                        out.type = Output::MISSING_HEADER;
                        out.location = rawtok->location;
                        out.msg = "Header not found: " + inctok->str();
                        outputList->push_back(out);
                    }
                } else if (includetokenstack.size() >= 400) {
                    if (outputList) {
                        Output out(files);
                        out.type = Output::INCLUDE_NESTED_TOO_DEEPLY;
                        out.location = rawtok->location;
                        out.msg = "#include nested too deeply";
                        outputList->push_back(out);
                    }
                } else if (pragmaOnce.find(filedata->filename) == pragmaOnce.end()) {
                    includetokenstack.push(gotoNextLine(rawtok));
                    rawtok = filedata->tokens.cfront();
                    continue;
                }
            } else if (rawtok->str() == IF || rawtok->str() == IFDEF || rawtok->str() == IFNDEF || rawtok->str() == ELIF) {
                if (!sameline(rawtok,rawtok->next)) {
                    if (outputList) {
                        Output out(files);
                        out.type = Output::SYNTAX_ERROR;
                        out.location = rawtok->location;
                        out.msg = "Syntax error in #" + rawtok->str();
                        outputList->push_back(out);
                    }
                    output.clear();
                    return;
                }

                bool conditionIsTrue;
                if (ifstates.top() == AlwaysFalse || (ifstates.top() == ElseIsTrue && rawtok->str() != ELIF))
                    conditionIsTrue = false;
                else if (rawtok->str() == IFDEF) {
                    conditionIsTrue = (macros.find(rawtok->next->str()) != macros.end() || (hasInclude && rawtok->next->str() == HAS_INCLUDE));
                    maybeUsedMacros[rawtok->next->str()].push_back(rawtok->next->location);
                } else if (rawtok->str() == IFNDEF) {
                    conditionIsTrue = (macros.find(rawtok->next->str()) == macros.end() && !(hasInclude && rawtok->next->str() == HAS_INCLUDE));
                    maybeUsedMacros[rawtok->next->str()].push_back(rawtok->next->location);
                } else { /*if (rawtok->str() == IF || rawtok->str() == ELIF)*/
                    TokenList expr(files);
                    for (const Token *tok = rawtok->next; tok && tok->location.sameline(rawtok->location); tok = tok->next) {
                        if (!tok->name) {
                            expr.push_back(new Token(*tok));
                            continue;
                        }

                        if (tok->str() == DEFINED) {
                            tok = tok->next;
                            const bool par = (tok && tok->op == '(');
                            if (par)
                                tok = tok->next;
                            maybeUsedMacros[rawtok->next->str()].push_back(rawtok->next->location);
                            if (tok) {
                                if (macros.find(tok->str()) != macros.end())
                                    expr.push_back(new Token("1", tok->location));
                                else if (hasInclude && tok->str() == HAS_INCLUDE)
                                    expr.push_back(new Token("1", tok->location));
                                else
                                    expr.push_back(new Token("0", tok->location));
                            }
                            if (par)
                                tok = tok ? tok->next : nullptr;
                            if (!tok || !sameline(rawtok,tok) || (par && tok->op != ')')) {
                                if (outputList) {
                                    Output out(rawtok->location.files);
                                    out.type = Output::SYNTAX_ERROR;
                                    out.location = rawtok->location;
                                    out.msg = "failed to evaluate " + string(rawtok->str() == IF ? "#if" : "#elif") + " condition";
                                    outputList->push_back(out);
                                }
                                output.clear();
                                return;
                            }
                            continue;
                        }

                        if (hasInclude && tok->str() == HAS_INCLUDE) {
                            tok = tok->next;
                            const bool par = (tok && tok->op == '(');
                            if (par)
                                tok = tok->next;
                            bool closingAngularBracket = false;
                            if (tok) {
                                const string &sourcefile = rawtok->location.file();
                                const bool systemheader = (tok && tok->op == '<');
                                string header;

                                if (systemheader) {
                                    while ((tok = tok->next) && tok->op != '>')
                                        header += tok->str();
                                    if (tok && tok->op == '>')
                                        closingAngularBracket = true;
                                } else {
                                    header = tok->str().substr(1U, tok->str().size() - 2U);
                                    closingAngularBracket = true;
                                }
                                ifstream f;
                                const string header2 = openHeader(f,dui,sourcefile,header,systemheader);
                                expr.push_back(new Token(header2.empty() ? "0" : "1", tok->location));
                            }
                            if (par)
                                tok = tok ? tok->next : nullptr;
                            if (!tok || !sameline(rawtok,tok) || (par && tok->op != ')') || (!closingAngularBracket)) {
                                if (outputList) {
                                    Output out(rawtok->location.files);
                                    out.type = Output::SYNTAX_ERROR;
                                    out.location = rawtok->location;
                                    out.msg = "failed to evaluate " + string(rawtok->str() == IF ? "#if" : "#elif") + " condition";
                                    outputList->push_back(out);
                                }
                                output.clear();
                                return;
                            }
                            continue;
                        }

                        maybeUsedMacros[rawtok->next->str()].push_back(rawtok->next->location);

                        const Token *tmp = tok;
                        if (!preprocessToken(expr, &tmp, macros, files, outputList)) {
                            output.clear();
                            return;
                        }
                        if (!tmp)
                            break;
                        tok = tmp->previous;
                    }
                    try {
                        if (ifCond) {
                            string E;
                            for (const Token *tok = expr.cfront(); tok; tok = tok->next)
                                E += (E.empty() ? "" : " ") + tok->str();
                            const long long result = evaluate(expr, dui, sizeOfType);
                            conditionIsTrue = (result != 0);
                            ifCond->push_back(IfCond(rawtok->location, E, result));
                        } else {
                            const long long result = evaluate(expr, dui, sizeOfType);
                            conditionIsTrue = (result != 0);
                        }
                    } catch (const exception &e) {
                        if (outputList) {
                            Output out(rawtok->location.files);
                            out.type = Output::SYNTAX_ERROR;
                            out.location = rawtok->location;
                            out.msg = "failed to evaluate " + string(rawtok->str() == IF ? "#if" : "#elif") + " condition";
                            if (e.what() && *e.what())
                                out.msg += string(", ") + e.what();
                            outputList->push_back(out);
                        }
                        output.clear();
                        return;
                    }
                }

                if (rawtok->str() != ELIF) {
                    // push a new ifstate..
                    if (ifstates.top() != True)
                        ifstates.push(AlwaysFalse);
                    else
                        ifstates.push(conditionIsTrue ? True : ElseIsTrue);
                    iftokens.push(rawtok);
                } else if (ifstates.top() == True) {
                    ifstates.top() = AlwaysFalse;
                    iftokens.top()->nextcond = rawtok;
                    iftokens.top() = rawtok;
                } else if (ifstates.top() == ElseIsTrue && conditionIsTrue) {
                    ifstates.top() = True;
                    iftokens.top()->nextcond = rawtok;
                    iftokens.top() = rawtok;
                }
            } else if (rawtok->str() == ELSE) {
                ifstates.top() = (ifstates.top() == ElseIsTrue) ? True : AlwaysFalse;
                iftokens.top()->nextcond = rawtok;
                iftokens.top() = rawtok;
            } else if (rawtok->str() == ENDIF) {
                ifstates.pop();
                iftokens.top()->nextcond = rawtok;
                iftokens.pop();
            } else if (rawtok->str() == UNDEF) {
                if (ifstates.top() == True) {
                    const Token *tok = rawtok->next;
                    while (sameline(rawtok,tok) && tok->comment)
                        tok = tok->next;
                    if (sameline(rawtok, tok))
                        macros.erase(tok->str());
                }
            } else if (ifstates.top() == True && rawtok->str() == PRAGMA && rawtok->next && rawtok->next->str() == ONCE && sameline(rawtok,rawtok->next)) {
                pragmaOnce.insert(rawtok->location.file());
            }
            if (ifstates.top() != True && rawtok->nextcond)
                rawtok = rawtok->nextcond->previous;
            else
                rawtok = gotoNextLine(rawtok);
            continue;
        }

        if (ifstates.top() != True) {
            // drop code
            rawtok = gotoNextLine(rawtok);
            continue;
        }

        bool hash=false, hashhash=false;
        if (rawtok->op == '#' && sameline(rawtok,rawtok->next)) {
            if (rawtok->next->op != '#') {
                hash = true;
                rawtok = rawtok->next; // skip '#'
            } else if (sameline(rawtok,rawtok->next->next)) {
                hashhash = true;
                rawtok = rawtok->next->next; // skip '#' '#'
            }
        }

        const Location loc(rawtok->location);
        TokenList tokens(files);

        if (!preprocessToken(tokens, &rawtok, macros, files, outputList)) {
            output.clear();
            return;
        }

        if (hash || hashhash) {
            string s;
            for (const Token *hashtok = tokens.cfront(); hashtok; hashtok = hashtok->next)
                s += hashtok->str();
            if (hash)
                output.push_back(new Token('\"' + s + '\"', loc));
            else if (output.back())
                output.back()->setstr(output.cback()->str() + s);
            else
                output.push_back(new Token(s, loc));
        } else {
            output.takeTokens(tokens);
        }
    }

    if (macroUsage) {
        for (MacroMap::const_iterator macroIt = macros.begin(); macroIt != macros.end(); ++macroIt) {
            const Macro &macro = macroIt->second;
            list<Location> usage = macro.usage();
            const list<Location>& temp = maybeUsedMacros[macro.name()];
            usage.insert(usage.end(), temp.begin(), temp.end());
            for (list<Location>::const_iterator usageIt = usage.begin(); usageIt != usage.end(); ++usageIt) {
                MacroUsage mu(usageIt->files, macro.valueDefinedInCode());
                mu.macroName = macro.name();
                mu.macroLocation = macro.defineLocation();
                mu.useLocation = *usageIt;
                macroUsage->push_back(mu);
            }
        }
    }
}

void cleanup(FileDataCache &cache)
{
    cache.clear();
}

cstd_t getCStd(const string &std)
{
    if (std == "c90" || std == "c89" || std == "iso9899:1990" || std == "iso9899:199409" || std == "gnu90" || std == "gnu89")
        return C89;
    if (std == "c99" || std == "c9x" || std == "iso9899:1999" || std == "iso9899:199x" || std == "gnu99"|| std == "gnu9x")
        return C99;
    if (std == "c11" || std == "c1x" || std == "iso9899:2011" || std == "gnu11" || std == "gnu1x")
        return C11;
    if (std == "c17" || std == "c18" || std == "iso9899:2017" || std == "iso9899:2018" || std == "gnu17"|| std == "gnu18")
        return C17;
    if (std == "c23" || std == "gnu23" || std == "c2x" || std == "gnu2x")
        return C23;
    return CUnknown;
}

string getCStdString(cstd_t std)
{
    switch (std) {
    case C89:
        // __STDC_VERSION__ is not set for C90 although the macro was added in the 1994 amendments
        return "";
    case C99:
        return "199901L";
    case C11:
        return "201112L";
    case C17:
        return "201710L";
    case C23:
        // supported by GCC 9+ and Clang 9+
        // Clang 9, 10, 11, 12, 13 return "201710L"
        // Clang 14, 15, 16, 17 return "202000L"
        // Clang 9, 10, 11, 12, 13, 14, 15, 16, 17 do not support "c23" and "gnu23"
        return "202311L";
    case CUnknown:
        return "";
    }
    return "";
}

string getCStdString(const string &std)
{
    return WadeSpace::PreProcessor::getCStdString(WadeSpace::PreProcessor::getCStd(std));
}

cppstd_t getCppStd(const string &std)
{
    if (std == "c++98" || std == "c++03" || std == "gnu++98" || std == "gnu++03")
        return CPP03;
    if (std == "c++11" || std == "gnu++11" || std == "c++0x" || std == "gnu++0x")
        return CPP11;
    if (std == "c++14" || std == "c++1y" || std == "gnu++14" || std == "gnu++1y")
        return CPP14;
    if (std == "c++17" || std == "c++1z" || std == "gnu++17" || std == "gnu++1z")
        return CPP17;
    if (std == "c++20" || std == "c++2a" || std == "gnu++20" || std == "gnu++2a")
        return CPP20;
    if (std == "c++23" || std == "c++2b" || std == "gnu++23" || std == "gnu++2b")
        return CPP23;
    if (std == "c++26" || std == "c++2c" || std == "gnu++26" || std == "gnu++2c")
        return CPP26;
    return CPPUnknown;
}

string getCppStdString(cppstd_t std)
{
    switch (std) {
    case CPP03:
        return "199711L";
    case CPP11:
        return "201103L";
    case CPP14:
        return "201402L";
    case CPP17:
        return "201703L";
    case CPP20:
        // GCC 10 returns "201703L" - correct in 11+
        return "202002L";
    case CPP23:
        // supported by GCC 11+ and Clang 12+
        // GCC 11, 12, 13 return "202100L"
        // Clang 12, 13, 14, 15, 16 do not support "c++23" and "gnu++23" and return "202101L"
        // Clang 17, 18 return "202302L"
        return "202302L";
    case CPP26:
        // supported by Clang 17+
        return "202400L";
    case CPPUnknown:
        return "";
    }
    return "";
}

string getCppStdString(const string &std)
{
    return WadeSpace::PreProcessor::getCppStdString(WadeSpace::PreProcessor::getCppStd(std));
}
