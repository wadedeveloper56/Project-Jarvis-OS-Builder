#include "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

TokenList::TokenList(vector<string>& filenames) : frontToken(nullptr), backToken(nullptr), files(filenames) {}

TokenList::TokenList(istream& istr, vector<std::string>& filenames, const string& filename, OutputList* outputList)
	: frontToken(nullptr), backToken(nullptr), files(filenames)
{
	StdIStream stream(istr);
	readfile(stream, filename, outputList);
}

TokenList::TokenList(const unsigned char* data, std::size_t size, std::vector<std::string>& filenames, const std::string& filename, OutputList* outputList)
	: frontToken(nullptr), backToken(nullptr), files(filenames)
{
	StdCharBufStream stream(data, size);
	readfile(stream, filename, outputList);
}

TokenList::TokenList(const char* data, std::size_t size, std::vector<std::string>& filenames, const std::string& filename, OutputList* outputList)
	: frontToken(nullptr), backToken(nullptr), files(filenames)
{
	StdCharBufStream stream(reinterpret_cast<const unsigned char*>(data), size);
	readfile(stream, filename, outputList);
}

TokenList::TokenList(const std::string& filename, std::vector<std::string>& filenames, OutputList* outputList)
	: frontToken(nullptr), backToken(nullptr), files(filenames)
{
	try
	{
		FileStream stream(filename, filenames);
		readfile(stream, filename, outputList);
	}
	catch (const Output& e)
	{ // TODO handle extra type of errors
		outputList->push_back(e);
	}
}

TokenList::TokenList(const TokenList& other) : frontToken(nullptr), backToken(nullptr), files(other.files)
{
	*this = other;
}

TokenList::TokenList(TokenList&& other) : frontToken(nullptr), backToken(nullptr), files(other.files)
{
	*this = std::move(other);
}

TokenList::~TokenList()
{
	clear();
}

TokenList& TokenList::operator=(const TokenList& other)
{
	if (this != &other)
	{
		clear();
		files = other.files;
		for (const Token* tok = other.cfront(); tok; tok = tok->next)
			push_back(new Token(*tok));
		sizeOfType = other.sizeOfType;
	}
	return *this;
}

TokenList& TokenList::operator=(TokenList&& other)
{
	if (this != &other)
	{
		clear();
		frontToken = other.frontToken;
		other.frontToken = nullptr;
		backToken = other.backToken;
		other.backToken = nullptr;
		files = other.files;
		sizeOfType = std::move(other.sizeOfType);
	}
	return *this;
}

void TokenList::clear()
{
	backToken = nullptr;
	while (frontToken)
	{
		Token* const next = frontToken->next;
		delete frontToken;
		frontToken = next;
	}
	sizeOfType.clear();
}

bool TokenList::empty() const {
	return !frontToken;
}

void TokenList::push_back(Token* tok)
{
	if (!frontToken)
		frontToken = tok;
	else
		backToken->next = tok;
	tok->previous = backToken;
	backToken = tok;
}

void TokenList::dump() const
{
	cout << stringify() << endl;
}

string TokenList::stringify() const
{
	ostringstream ret;
	Location loc(files);
	for (const Token* tok = cfront(); tok; tok = tok->next)
	{
		if (tok->location.line < loc.line || tok->location.fileIndex != loc.fileIndex)
		{
			ret << "\n#line " << tok->location.line << " \"" << tok->location.file() << "\"\n";
			loc = tok->location;
		}

		while (tok->location.line > loc.line)
		{
			ret << '\n';
			loc.line++;
		}

		if (sameline(tok->previous, tok))
			ret << ' ';

		ret << tok->str();

		loc.adjust(tok->str());
	}

	return ret.str();
}

static const string COMMENT_END("*/");

void TokenList::readfile(Stream& stream, const string& filename, OutputList* outputList)
{
	stack<Location> loc;

	unsigned int multiline = 0U;

	const Token* oldLastToken = nullptr;

	Location location(files);
	location.fileIndex = fileIndex(filename);
	location.line = 1U;
	location.col = 1U;
	while (stream.good())
	{
		unsigned char ch = stream.readChar();
		if (!stream.good())
			break;

		if (ch >= 0x80)
		{
			if (outputList)
			{
				Output err(files);
				err.type = Output::UNHANDLED_CHAR_ERROR;
				err.location = location;
				ostringstream s;
				s << static_cast<int>(ch);
				err.msg = "The code contains unhandled character(s) (character code=" + s.str() + "). Neither unicode nor extended ascii is supported.";
				outputList->push_back(err);
			}
			clear();
			return;
		}
		 
		if (ch == '\n')
		{
			if (cback() && cback()->op == '\\')
			{
				if (location.col > cback()->location.col + 1U)
					portabilityBackslash(outputList, files, cback()->location);
				++multiline;
				deleteToken(back());
			}
			else
			{
				location.line += multiline + 1;
				multiline = 0U;
			}
			if (!multiline)
				location.col = 1;

			if (oldLastToken != cback())
			{
				oldLastToken = cback();
				if (!isLastLinePreprocessor())
					continue;
				const std::string lastline(lastLine());
				if (lastline == "# file %str%")
				{
					const Token* strtok = cback();
					while (strtok->comment)
						strtok = strtok->previous;
					loc.push(location);
					location.fileIndex = fileIndex(strtok->str().substr(1U, strtok->str().size() - 2U));
					location.line = 1U;
				}
				else if (lastline == "# line %num%")
				{
					const Token* numtok = cback();
					while (numtok->comment)
						numtok = numtok->previous;
					lineDirective(location.fileIndex, atol(numtok->str().c_str()), &location);
				}
				else if (lastline == "# %num% %str%" || lastline == "# line %num% %str%")
				{
					const Token* strtok = cback();
					while (strtok->comment)
						strtok = strtok->previous;
					const Token* numtok = strtok->previous;
					while (numtok->comment)
						numtok = numtok->previous;
					lineDirective(fileIndex(replaceAll(strtok->str().substr(1U, strtok->str().size() - 2U), "\\\\", "\\")),
						atol(numtok->str().c_str()), &location);
				}
				// #endfile
				else if (lastline == "# endfile" && !loc.empty())
				{
					location = loc.top();
					loc.pop();
				}
			}

			continue;
		}

		if (ch <= ' ')
		{
			location.col++;
			continue;
		}

		TokenString currentToken;

		if (cback() && cback()->location.line == location.line && cback()->previous && cback()->previous->op == '#')
		{
			const Token* const llTok = lastLineTok();
			if (llTok && llTok->op == '#' && llTok->next && (llTok->next->str() == "error" || llTok->next->str() == "warning"))
			{
				char prev = ' ';
				while (stream.good() && (prev == '\\' || (ch != '\r' && ch != '\n')))
				{
					currentToken += ch;
					prev = ch;
					ch = stream.readChar();
				}
				stream.ungetChar();
				push_back(new Token(currentToken, location));
				location.adjust(currentToken);
				continue;
			}
		}

		// number or name
		if (isNameChar(ch))
		{
			const bool num = !!std::isdigit(ch);
			while (stream.good() && isNameChar(ch))
			{
				currentToken += ch;
				ch = stream.readChar();
				if (num && ch == '\'' && isNameChar(stream.peekChar()))
					ch = stream.readChar();
			}

			stream.ungetChar();
		}

		// comment
		else if (ch == '/' && stream.peekChar() == '/')
		{
			while (stream.good() && ch != '\n')
			{
				currentToken += ch;
				ch = stream.readChar();
				if (ch == '\\')
				{
					TokenString tmp;
					char tmp_ch = ch;
					while ((stream.good()) && (tmp_ch == '\\' || tmp_ch == ' ' || tmp_ch == '\t'))
					{
						tmp += tmp_ch;
						tmp_ch = stream.readChar();
					}
					if (!stream.good())
					{
						break;
					}

					if (tmp_ch != '\n')
					{
						currentToken += tmp;
					}
					else
					{
						const TokenString check_portability = currentToken + tmp;
						const std::string::size_type pos = check_portability.find_last_not_of(" \t");
						if (pos < check_portability.size() - 1U && check_portability[pos] == '\\')
							portabilityBackslash(outputList, files, location);
						++multiline;
						tmp_ch = stream.readChar();
						currentToken += '\n';
					}
					ch = tmp_ch;
				}
			}
			if (ch == '\n')
			{
				stream.ungetChar();
			}
		}

		// comment
		else if (ch == '/' && stream.peekChar() == '*')
		{
			currentToken = "/*";
			(void)stream.readChar();
			ch = stream.readChar();
			while (stream.good())
			{
				currentToken += ch;
				if (currentToken.size() >= 4U && endsWith(currentToken, COMMENT_END))
					break;
				ch = stream.readChar();
			}
			// multiline..

			std::string::size_type pos = 0;
			while ((pos = currentToken.find("\\\n", pos)) != std::string::npos)
			{
				currentToken.erase(pos, 2);
				++multiline;
			}
			if (multiline || isLastLinePreprocessor())
			{
				pos = 0;
				while ((pos = currentToken.find('\n', pos)) != std::string::npos)
				{
					currentToken.erase(pos, 1);
					++multiline;
				}
			}
		}

		// string / char literal
		else if (ch == '\"' || ch == '\'')
		{
			std::string prefix;
			if (cback() && cback()->name && isStringLiteralPrefix(cback()->str()) &&
				((cback()->location.col + cback()->str().size()) == location.col) &&
				(cback()->location.line == location.line))
			{
				prefix = cback()->str();
			}
			// C++11 raw string literal
			if (ch == '\"' && !prefix.empty() && *cback()->str().rbegin() == 'R')
			{
				std::string delim;
				currentToken = ch;
				prefix.resize(prefix.size() - 1);
				ch = stream.readChar();
				while (stream.good() && ch != '(' && ch != '\n')
				{
					delim += ch;
					ch = stream.readChar();
				}
				if (!stream.good() || ch == '\n')
				{
					if (outputList)
					{
						Output err(files);
						err.type = Output::SYNTAX_ERROR;
						err.location = location;
						err.msg = "Invalid newline in raw string delimiter.";
						outputList->push_back(err);
					}
					return;
				}
				const std::string endOfRawString(')' + delim + currentToken);
				while (stream.good() && !(endsWith(currentToken, endOfRawString) && currentToken.size() > 1))
					currentToken += stream.readChar();
				if (!endsWith(currentToken, endOfRawString))
				{
					if (outputList)
					{
						Output err(files);
						err.type = Output::SYNTAX_ERROR;
						err.location = location;
						err.msg = "Raw string missing terminating delimiter.";
						outputList->push_back(err);
					}
					return;
				}
				currentToken.erase(currentToken.size() - endOfRawString.size(), endOfRawString.size() - 1U);
				currentToken = escapeString(currentToken);
				currentToken.insert(0, prefix);
				back()->setstr(currentToken);
				location.adjust(currentToken);
				if (currentToken.find_first_of("\r\n") == std::string::npos)
					location.col += (unsigned int)(2 + 2 * delim.size());
				else
					location.col += (unsigned int)(1 + delim.size());

				continue;
			}

			currentToken = readUntil(stream, location, ch, ch, outputList);
			if (currentToken.size() < 2U)
				// Error is reported by readUntil()
				return;

			std::string s = currentToken;
			std::string::size_type pos;
			int newlines = 0;
			while ((pos = s.find_first_of("\r\n")) != std::string::npos)
			{
				s.erase(pos, 1);
				newlines++;
			}

			if (prefix.empty())
				push_back(new Token(s, location, !!std::isspace(stream.peekChar()))); // push string without newlines
			else
				back()->setstr(prefix + s);

			if (newlines > 0)
			{
				const Token* const llTok = lastLineTok();
				if (llTok && llTok->op == '#' && llTok->next && (llTok->next->str() == "define" || llTok->next->str() == "pragma") && llTok->next->next)
				{
					multiline += newlines;
					location.adjust(s);
					continue;
				}
			}

			location.adjust(currentToken);
			continue;
		}

		else
		{
			currentToken += ch;
		}

		if (*currentToken.begin() == '<')
		{
			const Token* const llTok = lastLineTok();
			if (llTok && llTok->op == '#' && llTok->next && llTok->next->str() == "include")
			{
				currentToken = readUntil(stream, location, '<', '>', outputList);
				if (currentToken.size() < 2U)
					return;
			}
		}

		push_back(new Token(currentToken, location, !!std::isspace(stream.peekChar())));

		if (multiline)
			location.col += (unsigned int)(currentToken.size());
		else
			location.adjust(currentToken);
	}

	combineOperators();
}

void TokenList::constFold()
{
	while (cfront())
	{
		// goto last '('
		Token* tok = back();
		while (tok && tok->op != '(')
			tok = tok->previous;

		// no '(', goto first token
		if (!tok)
			tok = front();

		// Constant fold expression
		constFoldUnaryNotPosNeg(tok);
		constFoldMulDivRem(tok);
		constFoldAddSub(tok);
		constFoldShift(tok);
		constFoldComparison(tok);
		constFoldBitwise(tok);
		constFoldLogicalOp(tok);
		constFoldQuestionOp(&tok);

		// If there is no '(' we are done with the constant folding
		if (tok->op != '(')
			break;

		if (!tok->next || !tok->next->next || tok->next->next->op != ')')
			break;

		tok = tok->next;
		deleteToken(tok->previous);
		deleteToken(tok->next);
	}
}

void TokenList::removeComments()
{
	Token* tok = frontToken;
	while (tok)
	{
		Token* const tok1 = tok;
		tok = tok->next;
		if (tok1->comment)
			deleteToken(tok1);
	}
}

Token* TokenList::front() {
	return frontToken;
}

const Token* TokenList::cfront() const {
	return frontToken;
}

Token* TokenList::back() {
	return backToken;
}

const Token* TokenList::cback() const {
	return backToken;
}

void TokenList::deleteToken(Token* tok) {
	if (!tok)
		return;
	Token* const prev = tok->previous;
	Token* const next = tok->next;
	if (prev)
		prev->next = next;
	if (next)
		next->previous = prev;
	if (frontToken == tok)
		frontToken = next;
	if (backToken == tok)
		backToken = prev;
	delete tok;
}

void TokenList::takeTokens(TokenList& other) {
	if (!other.frontToken)
		return;
	if (!frontToken)
	{
		frontToken = other.frontToken;
	}
	else
	{
		backToken->next = other.frontToken;
		other.frontToken->previous = backToken;
	}
	backToken = other.backToken;
	other.frontToken = other.backToken = nullptr;
}

/** sizeof(T) */
map<string, size_t> sizeOfType;

const vector<string>& TokenList::getFiles() const {
	return files;
}

void TokenList::combineOperators()
{
	std::stack<bool> executableScope;
	executableScope.push(false);
	for (Token* tok = front(); tok; tok = tok->next)
	{
		if (tok->op == '{')
		{
			if (executableScope.top())
			{
				executableScope.push(true);
				continue;
			}
			const Token* prev = tok->previous;
			while (prev && prev->isOneOf(";{}()"))
				prev = prev->previous;
			executableScope.push(prev && prev->op == ')');
			continue;
		}
		if (tok->op == '}')
		{
			if (executableScope.size() > 1)
				executableScope.pop();
			continue;
		}

		if (tok->op == '.')
		{
			// ellipsis ...
			if (tok->next && tok->next->op == '.' && tok->next->location.col == (tok->location.col + 1) &&
				tok->next->next && tok->next->next->op == '.' && tok->next->next->location.col == (tok->location.col + 2))
			{
				tok->setstr("...");
				deleteToken(tok->next);
				deleteToken(tok->next);
				continue;
			}
			// float literals..
			if (tok->previous && tok->previous->number && sameline(tok->previous, tok) && tok->previous->str().find_first_of("._") == std::string::npos)
			{
				tok->setstr(tok->previous->str() + '.');
				deleteToken(tok->previous);
				if (sameline(tok, tok->next) && (isFloatSuffix(tok->next) || (tok->next && tok->next->startsWithOneOf("AaBbCcDdEeFfPp"))))
				{
					tok->setstr(tok->str() + tok->next->str());
					deleteToken(tok->next);
				}
			}
			if (tok->next && tok->next->number)
			{
				tok->setstr(tok->str() + tok->next->str());
				deleteToken(tok->next);
			}
		}
		// match: [0-9.]+E [+-] [0-9]+
		const char lastChar = tok->str()[tok->str().size() - 1];
		if (tok->number && !isOct(tok->str()) &&
			((!isHex(tok->str()) && (lastChar == 'E' || lastChar == 'e')) ||
				(isHex(tok->str()) && (lastChar == 'P' || lastChar == 'p'))) &&
			tok->next && tok->next->isOneOf("+-") && tok->next->next && tok->next->next->number)
		{
			tok->setstr(tok->str() + tok->next->op + tok->next->next->str());
			deleteToken(tok->next);
			deleteToken(tok->next);
		}

		if (tok->op == '\0' || !tok->next || tok->next->op == '\0')
			continue;
		if (!sameline(tok, tok->next))
			continue;
		if (tok->location.col + 1U != tok->next->location.col)
			continue;

		if (tok->next->op == '=' && tok->isOneOf("=!<>+-*/%&|^"))
		{
			if (tok->op == '&' && !executableScope.top())
			{
				// don't combine &= if it is a anonymous reference parameter with default value:
				// void f(x&=2)
				int indentlevel = 0;
				const Token* start = tok;
				while (indentlevel >= 0 && start)
				{
					if (start->op == ')')
						++indentlevel;
					else if (start->op == '(')
						--indentlevel;
					else if (start->isOneOf(";{}"))
						break;
					start = start->previous;
				}
				if (indentlevel == -1 && start)
				{
					const Token* const ftok = start;
					bool isFuncDecl = ftok->name;
					while (isFuncDecl)
					{
						if (!start->name && start->str() != "::" && start->op != '*' && start->op != '&')
							isFuncDecl = false;
						if (!start->previous)
							break;
						if (start->previous->isOneOf(";{}:"))
							break;
						start = start->previous;
					}
					isFuncDecl &= start != ftok && start->name;
					if (isFuncDecl)
					{
						// TODO: we could loop through the parameters here and check if they are correct.
						continue;
					}
				}
			}
			tok->setstr(tok->str() + "=");
			deleteToken(tok->next);
		}
		else if ((tok->op == '|' || tok->op == '&') && tok->op == tok->next->op)
		{
			tok->setstr(tok->str() + tok->next->str());
			deleteToken(tok->next);
		}
		else if (tok->op == ':' && tok->next->op == ':')
		{
			tok->setstr(tok->str() + tok->next->str());
			deleteToken(tok->next);
		}
		else if (tok->op == '-' && tok->next->op == '>')
		{
			tok->setstr(tok->str() + tok->next->str());
			deleteToken(tok->next);
		}
		else if ((tok->op == '<' || tok->op == '>') && tok->op == tok->next->op)
		{
			tok->setstr(tok->str() + tok->next->str());
			deleteToken(tok->next);
			if (tok->next && tok->next->op == '=' && tok->next->next && tok->next->next->op != '=')
			{
				tok->setstr(tok->str() + tok->next->str());
				deleteToken(tok->next);
			}
		}
		else if ((tok->op == '+' || tok->op == '-') && tok->op == tok->next->op)
		{
			if (tok->location.col + 1U != tok->next->location.col)
				continue;
			if (tok->previous && tok->previous->number)
				continue;
			if (tok->next->next && tok->next->next->number)
				continue;
			tok->setstr(tok->str() + tok->next->str());
			deleteToken(tok->next);
		}
	}
}

static const std::string COMPL("compl");
static const std::string NOT("not");

void TokenList::constFoldUnaryNotPosNeg(Token* tok)
{
	for (; tok && tok->op != ')'; tok = tok->next)
	{
		// "not" might be !
		if (isAlternativeUnaryOp(tok, NOT))
			tok->op = '!';
		// "compl" might be ~
		else if (isAlternativeUnaryOp(tok, COMPL))
			tok->op = '~';

		if (tok->op == '!' && tok->next && tok->next->number)
		{
			tok->setstr(tok->next->str() == "0" ? "1" : "0");
			deleteToken(tok->next);
		}
		else if (tok->op == '~' && tok->next && tok->next->number)
		{
			tok->setstr(toString(~stringToLL(tok->next->str())));
			deleteToken(tok->next);
		}
		else
		{
			if (tok->previous && (tok->previous->number || tok->previous->name))
				continue;
			if (!tok->next || !tok->next->number)
				continue;
			switch (tok->op)
			{
				case '+':
					tok->setstr(tok->next->str());
					deleteToken(tok->next);
					break;
				case '-':
					tok->setstr(tok->op + tok->next->str());
					deleteToken(tok->next);
					break;
			}
		}
	}
}

void TokenList::constFoldMulDivRem(Token* tok)
{
	for (; tok && tok->op != ')'; tok = tok->next)
	{
		if (!tok->previous || !tok->previous->number)
			continue;
		if (!tok->next || !tok->next->number)
			continue;

		long long result;
		if (tok->op == '*')
			result = (stringToLL(tok->previous->str()) * stringToLL(tok->next->str()));
		else if (tok->op == '/' || tok->op == '%')
		{
			const long long rhs = stringToLL(tok->next->str());
			if (rhs == 0)
				throw std::overflow_error("division/modulo by zero");
			const long long lhs = stringToLL(tok->previous->str());
			if (rhs == -1 && lhs == std::numeric_limits<long long>::min())
				throw std::overflow_error("division overflow");
			if (tok->op == '/')
				result = (lhs / rhs);
			else
				result = (lhs % rhs);
		}
		else
			continue;

		tok = tok->previous;
		tok->setstr(toString(result));
		deleteToken(tok->next);
		deleteToken(tok->next);
	}
}

void TokenList::constFoldAddSub(Token* tok)
{
	for (; tok && tok->op != ')'; tok = tok->next)
	{
		if (!tok->previous || !tok->previous->number)
			continue;
		if (!tok->next || !tok->next->number)
			continue;

		long long result;
		if (tok->op == '+')
			result = stringToLL(tok->previous->str()) + stringToLL(tok->next->str());
		else if (tok->op == '-')
			result = stringToLL(tok->previous->str()) - stringToLL(tok->next->str());
		else
			continue;

		tok = tok->previous;
		tok->setstr(toString(result));
		deleteToken(tok->next);
		deleteToken(tok->next);
	}
}

void TokenList::constFoldShift(Token* tok)
{
	for (; tok && tok->op != ')'; tok = tok->next)
	{
		if (!tok->previous || !tok->previous->number)
			continue;
		if (!tok->next || !tok->next->number)
			continue;

		long long result;
		if (tok->str() == "<<")
			result = stringToLL(tok->previous->str()) << stringToLL(tok->next->str());
		else if (tok->str() == ">>")
			result = stringToLL(tok->previous->str()) >> stringToLL(tok->next->str());
		else
			continue;

		tok = tok->previous;
		tok->setstr(toString(result));
		deleteToken(tok->next);
		deleteToken(tok->next);
	}
}

static const std::string NOTEQ("not_eq");
void TokenList::constFoldComparison(Token* tok)
{
	for (; tok && tok->op != ')'; tok = tok->next)
	{
		if (isAlternativeBinaryOp(tok, NOTEQ))
			tok->setstr("!=");

		if (!tok->startsWithOneOf("<>=!"))
			continue;
		if (!tok->previous || !tok->previous->number)
			continue;
		if (!tok->next || !tok->next->number)
			continue;

		int result;
		if (tok->str() == "==")
			result = (stringToLL(tok->previous->str()) == stringToLL(tok->next->str()));
		else if (tok->str() == "!=")
			result = (stringToLL(tok->previous->str()) != stringToLL(tok->next->str()));
		else if (tok->str() == ">")
			result = (stringToLL(tok->previous->str()) > stringToLL(tok->next->str()));
		else if (tok->str() == ">=")
			result = (stringToLL(tok->previous->str()) >= stringToLL(tok->next->str()));
		else if (tok->str() == "<")
			result = (stringToLL(tok->previous->str()) < stringToLL(tok->next->str()));
		else if (tok->str() == "<=")
			result = (stringToLL(tok->previous->str()) <= stringToLL(tok->next->str()));
		else
			continue;

		tok = tok->previous;
		tok->setstr(toString(result));
		deleteToken(tok->next);
		deleteToken(tok->next);
	}
}

static const std::string BITAND("bitand");
static const std::string BITOR("bitor");
static const std::string XOR("xor");
void TokenList::constFoldBitwise(Token* tok)
{
	Token* const tok1 = tok;
	for (const char* op = "&^|"; *op; op++)
	{
		const std::string* alternativeOp;
		if (*op == '&')
			alternativeOp = &BITAND;
		else if (*op == '|')
			alternativeOp = &BITOR;
		else
			alternativeOp = &XOR;
		for (tok = tok1; tok && tok->op != ')'; tok = tok->next)
		{
			if (tok->op != *op && !isAlternativeBinaryOp(tok, *alternativeOp))
				continue;
			if (!tok->previous || !tok->previous->number)
				continue;
			if (!tok->next || !tok->next->number)
				continue;
			long long result;
			if (*op == '&')
				result = (stringToLL(tok->previous->str()) & stringToLL(tok->next->str()));
			else if (*op == '^')
				result = (stringToLL(tok->previous->str()) ^ stringToLL(tok->next->str()));
			else /*if (*op == '|')*/
				result = (stringToLL(tok->previous->str()) | stringToLL(tok->next->str()));
			tok = tok->previous;
			tok->setstr(toString(result));
			deleteToken(tok->next);
			deleteToken(tok->next);
		}
	}
}

static const std::string AND("and");
static const std::string OR("or");
void TokenList::constFoldLogicalOp(Token* tok)
{
	for (; tok && tok->op != ')'; tok = tok->next)
	{
		if (tok->name)
		{
			if (isAlternativeBinaryOp(tok, AND))
				tok->setstr("&&");
			else if (isAlternativeBinaryOp(tok, OR))
				tok->setstr("||");
		}
		if (tok->str() != "&&" && tok->str() != "||")
			continue;
		if (!tok->previous || !tok->previous->number)
			continue;
		if (!tok->next || !tok->next->number)
			continue;

		int result;
		if (tok->str() == "||")
			result = (stringToLL(tok->previous->str()) || stringToLL(tok->next->str()));
		else /*if (tok->str() == "&&")*/
			result = (stringToLL(tok->previous->str()) && stringToLL(tok->next->str()));

		tok = tok->previous;
		tok->setstr(toString(result));
		deleteToken(tok->next);
		deleteToken(tok->next);
	}
}

void TokenList::constFoldQuestionOp(Token** tok1)
{
	bool gotoTok1 = false;
	for (Token* tok = *tok1; tok&& tok->op != ')'; tok = gotoTok1 ? *tok1 : tok->next)
	{
		gotoTok1 = false;
		if (tok->str() != "?")
			continue;
		if (!tok->previous || !tok->next || !tok->next->next)
			throw std::runtime_error("invalid expression");
		if (!tok->previous->number)
			continue;
		if (tok->next->next->op != ':')
			continue;
		Token* const condTok = tok->previous;
		Token* const trueTok = tok->next;
		Token* const falseTok = trueTok->next->next;
		if (!falseTok)
			throw std::runtime_error("invalid expression");
		if (condTok == *tok1)
			*tok1 = (condTok->str() != "0" ? trueTok : falseTok);
		deleteToken(condTok->next); // ?
		deleteToken(trueTok->next); // :
		deleteToken(condTok->str() == "0" ? trueTok : falseTok);
		deleteToken(condTok);
		gotoTok1 = true;
	}
}

string TokenList::readUntil(Stream& stream, const Location& location, const char start, const char end, OutputList* outputList)
{
	std::string ret;
	ret += start;

	bool backslash = false;
	char ch = 0;
	while (ch != end && ch != '\r' && ch != '\n' && stream.good())
	{
		ch = stream.readChar();
		if (backslash && ch == '\n')
		{
			ch = 0;
			backslash = false;
			continue;
		}
		backslash = false;
		ret += ch;
		if (ch == '\\')
		{
			bool update_ch = false;
			char next = 0;
			do
			{
				next = stream.readChar();
				if (next == '\r' || next == '\n')
				{
					ret.erase(ret.size() - 1U);
					backslash = (next == '\r');
					update_ch = false;
				}
				else if (next == '\\')
					update_ch = !update_ch;
				ret += next;
			} while (next == '\\');
			if (update_ch)
				ch = next;
		}
	}

	if (!stream.good() || ch != end)
	{
		clear();
		if (outputList)
		{
			Output err(files);
			err.type = Output::SYNTAX_ERROR;
			err.location = location;
			err.msg = std::string("No pair for character (") + start + "). Can't process file. File is either invalid or unicode, which is currently not supported.";
			outputList->push_back(err);
		}
		return "";
	}

	return ret;
}

void TokenList::lineDirective(unsigned int fileIndex, unsigned int line, Location* location)
{
	if (fileIndex != location->fileIndex || line >= location->line)
	{
		location->fileIndex = fileIndex;
		location->line = line;
		return;
	}

	if (line + 2 >= location->line)
	{
		location->line = line;
		while (cback()->op != '#')
			deleteToken(back());
		deleteToken(back());
		return;
	}
}

string TokenList::lastLine(int maxsize) const
{
	string ret;
	int count = 0;
	for (const Token* tok = cback(); ; tok = tok->previous)
	{
		if (!sameline(tok, cback()))
		{
			break;
		}
		if (tok->comment)
			continue;
		if (++count > maxsize)
			return "";
		if (!ret.empty())
			ret += ' ';
		// add tokens in reverse for performance reasons
		if (tok->str()[0] == '\"')
			ret += "%rts%"; // %str%
		else if (tok->number)
			ret += "%mun%"; // %num%
		else
		{
			ret += tok->str();
			std::reverse(ret.end() - tok->str().length(), ret.end());
		}
	}
	std::reverse(ret.begin(), ret.end());
	return ret;
}

const Token* TokenList::lastLineTok(int maxsize) const
{
	const Token* prevTok = nullptr;
	int count = 0;
	for (const Token* tok = cback(); ; tok = tok->previous)
	{
		if (!sameline(tok, cback()))
			break;
		if (tok->comment)
			continue;
		if (++count > maxsize)
			return nullptr;
		prevTok = tok;
	}
	return prevTok;
}

bool TokenList::isLastLinePreprocessor(int maxsize) const
{
	const Token* const prevTok = lastLineTok(maxsize);
	return prevTok && prevTok->op == '#';
}

unsigned int TokenList::fileIndex(const std::string& filename)
{
	for (unsigned int i = 0; i < files.size(); ++i)
	{
		if (files[i] == filename)
			return i;
	}
	files.push_back(filename);
	return (unsigned int)(files.size() - 1U);
}