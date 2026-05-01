#include "pch.h"
#include "Preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

bool WadeSpace::PreProcessor::isHex(const string& s)
{
    return s.size() > 2 && (s.compare(0, 2, "0x") == 0 || s.compare(0, 2, "0X") == 0);
}

bool WadeSpace::PreProcessor::isOct(const string& s)
{
    return s.size() > 1 && (s[0] == '0') && (s[1] >= '0') && (s[1] < '8');
}

bool WadeSpace::PreProcessor::isStringLiteral_(const string& s)
{
    return s.size() > 1 && (s[0] == '\"') && (*s.rbegin() == '\"');
}

bool WadeSpace::PreProcessor::isCharLiteral_(const string& s)
{
    return s.size() > 1 && (s[0] == '\'') && (*s.rbegin() == '\'');
}

const TokenString DEFINE("define");
const TokenString UNDEF("undef");
const TokenString INCLUDE("include");
const TokenString ERROR("error");
const TokenString WARNING("warning");
const TokenString IF("if");
const TokenString IFDEF("ifdef");
const TokenString IFNDEF("ifndef");
const TokenString DEFINED("defined");
const TokenString ELSE("else");
const TokenString ELIF("elif");
const TokenString ENDIF("endif");
const TokenString PRAGMA("pragma");
const TokenString ONCE("once");
const TokenString HAS_INCLUDE("__has_include");

#ifdef SIMPLECPP_DEBUG_MACRO_EXPANSION
string WadeSpace::PreProcessor::locstring(const Location& loc)
{
    ostringstream ostr;
    ostr << '[' << loc.file() << ':' << loc.line << ':' << loc.col << ']';
    return ostr.str();
}
#endif

long long  WadeSpace::PreProcessor::stringToLL(const string& s)
{
    long long ret;
    const bool hex = isHex(s);
    const bool oct = isOct(s);
    istringstream istr(hex ? s.substr(2) : oct ? s.substr(1) : s);
    if (hex)
        istr >> std::hex;
    else if (oct)
        istr >> std::oct;
    istr >> ret;
    return ret;
}

unsigned long long WadeSpace::PreProcessor::stringToULL(const string& s)
{
    unsigned long long ret;
    const bool hex = isHex(s);
    const bool oct = isOct(s);
    istringstream istr(hex ? s.substr(2) : oct ? s.substr(1) : s);
    if (hex)
        istr >> std::hex;
    else if (oct)
        istr >> std::oct;
    istr >> ret;
    return ret;
}

bool WadeSpace::PreProcessor::endsWith(const string& s, const string& e)
{
    return (s.size() >= e.size()) && equal(e.rbegin(), e.rend(), s.rbegin());
}

bool WadeSpace::PreProcessor::sameline(const Token* tok1, const Token* tok2)
{
    return tok1 && tok2 && tok1->location.sameline(tok2->location);
}

bool WadeSpace::PreProcessor::isAlternativeBinaryOp(const Token* tok, const string& alt)
{
    return (tok->name &&
        tok->str() == alt &&
        tok->previous &&
        tok->next &&
        (tok->previous->number || tok->previous->name || tok->previous->op == ')') &&
        (tok->next->number || tok->next->name || tok->next->op == '('));
}

bool WadeSpace::PreProcessor::isAlternativeUnaryOp(const Token* tok, const string& alt)
{
    return ((tok->name && tok->str() == alt) &&
        (!tok->previous || tok->previous->op == '(') &&
        (tok->next && (tok->next->name || tok->next->number)));
}

string WadeSpace::PreProcessor::replaceAll(string s, const string& from, const string& to)
{
    for (size_t pos = s.find(from); pos != string::npos; pos = s.find(from, pos + to.size()))
        s.replace(pos, from.size(), to);
    return s;
}

bool WadeSpace::PreProcessor::isNameChar(unsigned char ch)
{
    return isalnum(ch) || ch == '_' || ch == '$';
}

string WadeSpace::PreProcessor::escapeString(const string& str)
{
    ostringstream ostr;
    ostr << '\"';
    for (size_t i = 1U; i < str.size() - 1; ++i)
    {
        const char c = str[i];
        if (c == '\\' || c == '\"' || c == '\'')
            ostr << '\\';
        ostr << c;
    }
    ostr << '\"';
    return ostr.str();
}

void WadeSpace::PreProcessor::portabilityBackslash(OutputList* outputList, const vector<string>& files, const Location& location)
{
    if (!outputList)
        return;
    Output err(files);
    err.type = Output::PORTABILITY_BACKSLASH;
    err.location = location;
    err.msg = "Combination 'backslash space newline' is not portable.";
    outputList->push_back(err);
}

bool WadeSpace::PreProcessor::isStringLiteralPrefix(const string& str)
{
    return str == "u" || str == "U" || str == "L" || str == "u8" ||
        str == "R" || str == "uR" || str == "UR" || str == "LR" || str == "u8R";
}
