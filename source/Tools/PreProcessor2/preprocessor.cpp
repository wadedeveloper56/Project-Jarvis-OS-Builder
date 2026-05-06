#include "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

TokenString DEFINE("define");
TokenString UNDEF("undef");
TokenString INCLUDE("include");
TokenString ERROR("error");
TokenString WARNING("warning");
TokenString IF("if");
TokenString IFDEF("ifdef");
TokenString IFNDEF("ifndef");
TokenString DEFINED("defined");
TokenString ELSE("else");
TokenString ELIF("elif");
TokenString ENDIF("endif");
TokenString PRAGMA("pragma");
TokenString ONCE("once");
TokenString HAS_INCLUDE("__has_include");

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

#ifdef SIMPLECPP_WINDOWS
bool isAbsolutePath(const std::string& path)
{
    if (path.length() >= 3 && path[0] > 0 && std::isalpha(path[0]) && path[1] == ':' && (path[2] == '\\' || path[2] == '/'))
        return true;
    return path.length() > 1U && (path[0] == '/' || path[0] == '\\');
}
#else
bool isAbsolutePath(const std::string& path)
{
    return path.length() > 1U && path[0] == '/';
}
#endif

std::string WadeSpace::PreProcessor::simplifyPath(std::string path)
{
    if (path.empty())
        return path;

    std::string::size_type pos;

    // replace backslash separators
    std::replace(path.begin(), path.end(), '\\', '/');

    const bool unc(path.compare(0, 2, "//") == 0);

    // replace "//" with "/"
    pos = 0;
    while ((pos = path.find("//", pos)) != std::string::npos)
    {
        path.erase(pos, 1);
    }

    // remove "./"
    pos = 0;
    while ((pos = path.find("./", pos)) != std::string::npos)
    {
        if (pos == 0 || path[pos - 1U] == '/')
            path.erase(pos, 2);
        else
            pos += 2;
    }

    // remove trailing dot if path ends with "/."
    if (endsWith(path, "/."))
        path.erase(path.size() - 1);

    // simplify ".."
    pos = 1; // don't simplify ".." if path starts with that
    while ((pos = path.find("/..", pos)) != std::string::npos)
    {
        // not end of path, then string must be "/../"
        if (pos + 3 < path.size() && path[pos + 3] != '/')
        {
            ++pos;
            continue;
        }
        // get previous subpath
        std::string::size_type pos1 = path.rfind('/', pos - 1U);
        if (pos1 == std::string::npos)
        {
            pos1 = 0;
        }
        else
        {
            pos1 += 1U;
        }
        const std::string previousSubPath = path.substr(pos1, pos - pos1);
        if (previousSubPath == "..")
        {
            // don't simplify
            ++pos;
        }
        else
        {
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

std::string dirPath(const std::string& path, bool withTrailingSlash = true)
{
    const std::size_t lastSlash = path.find_last_of("\\/");
    if (lastSlash == std::string::npos)
    {
        return "";
    }
    return path.substr(0, lastSlash + (withTrailingSlash ? 1U : 0U));
}

bool isStringLiteral_(const std::string& s)
{
    return s.size() > 1 && (s[0] == '\"') && (*s.rbegin() == '\"');
}

bool isCharLiteral_(const std::string& s)
{
    return s.size() > 1 && (s[0] == '\'') && (*s.rbegin() == '\'');
}
