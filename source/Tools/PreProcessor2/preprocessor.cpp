#include "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

bool sameline(const Token* tok1, const Token* tok2)
{
    return tok1 && tok2 && tok1->location.sameline(tok2->location);
}

bool isHex(const std::string& s)
{
    return s.size() > 2 && (s.compare(0, 2, "0x") == 0 || s.compare(0, 2, "0X") == 0);
}

bool isOct(const std::string& s)
{
    return s.size() > 1 && (s[0] == '0') && (s[1] >= '0') && (s[1] < '8');
}

long long stringToLL(const std::string& s)
{
    long long ret;
    const bool hex = WadeSpace::PreProcessor::isHex(s);
    const bool oct = WadeSpace::PreProcessor::isOct(s);
    istringstream istr(hex ? s.substr(2) : oct ? s.substr(1) : s);
    if (hex)
        istr >> std::hex;
    else if (oct)
        istr >> std::oct;
    istr >> ret;
    return ret;
}

unsigned long long stringToULL(const string& s)
{
    unsigned long long ret;
    const bool hex = WadeSpace::PreProcessor::isHex(s);
    const bool oct = WadeSpace::PreProcessor::isOct(s);
    istringstream istr(hex ? s.substr(2) : oct ? s.substr(1) : s);
    if (hex)
        istr >> std::hex;
    else if (oct)
        istr >> std::oct;
    istr >> ret;
    return ret;
}

bool endsWith(const string& s, const string& e)
{
    return (s.size() >= e.size()) && std::equal(e.rbegin(), e.rend(), s.rbegin());
}

bool isAlternativeBinaryOp(const Token* tok, const string& alt)
{
    return (tok->name &&
        tok->str() == alt &&
        tok->previous &&
        tok->next &&
        (tok->previous->number || tok->previous->name || tok->previous->op == ')') &&
        (tok->next->number || tok->next->name || tok->next->op == '('));
}

bool isAlternativeUnaryOp(const Token* tok, const string& alt)
{
    return ((tok->name && tok->str() == alt) &&
        (!tok->previous || tok->previous->op == '(') &&
        (tok->next && (tok->next->name || tok->next->number)));
}

void portabilityBackslash(WadeSpace::PreProcessor::OutputList* outputList, const vector<string>& files, const Location& location)
{
    if (!outputList)
        return;
    Output err(files);
    err.type = WadeSpace::PreProcessor::Output::PORTABILITY_BACKSLASH;
    err.location = location;
    err.msg = "Combination 'backslash space newline' is not portable.";
    outputList->push_back(err);
}

string replaceAll(string s, const string& from, const string& to)
{
    for (size_t pos = s.find(from); pos != string::npos; pos = s.find(from, pos + to.size()))
        s.replace(pos, from.size(), to);
    return s;
}

bool isNameChar(unsigned char ch)
{
    return isalnum(ch) || ch == '_' || ch == '$';
}

string escapeString(const std::string& str)
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

bool isStringLiteralPrefix(const std::string& str)
{
    return str == "u" || str == "U" || str == "L" || str == "u8" ||
        str == "R" || str == "uR" || str == "UR" || str == "LR" || str == "u8R";
}

bool isFloatSuffix(const Token* tok)
{
    if (!tok || tok->str().size() != 1U)
        return false;
    const char c = std::tolower(tok->str()[0]);
    return c == 'f' || c == 'l';
}

