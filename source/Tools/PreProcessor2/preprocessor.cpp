#include "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

TokenString WadeSpace::PreProcessor::DEFINE("define");
TokenString WadeSpace::PreProcessor::UNDEF("undef");
TokenString WadeSpace::PreProcessor::INCLUDE("include");
TokenString WadeSpace::PreProcessor::ERROR("error");
TokenString WadeSpace::PreProcessor::WARNING("warning");
TokenString WadeSpace::PreProcessor::IF("if");
TokenString WadeSpace::PreProcessor::IFDEF("ifdef");
TokenString WadeSpace::PreProcessor::IFNDEF("ifndef");
TokenString WadeSpace::PreProcessor::DEFINED("defined");
TokenString WadeSpace::PreProcessor::ELSE("else");
TokenString WadeSpace::PreProcessor::ELIF("elif");
TokenString WadeSpace::PreProcessor::ENDIF("endif");
TokenString WadeSpace::PreProcessor::PRAGMA("pragma");
TokenString WadeSpace::PreProcessor::ONCE("once");
TokenString WadeSpace::PreProcessor::HAS_INCLUDE("__has_include");
NonExistingFilesCache WadeSpace::PreProcessor::nonExistingFilesCache;
const char* const altopData[] = { "and","or","bitand","bitor","compl","not","not_eq","xor" };
const set<string> WadeSpace::PreProcessor::altop(&altopData[0], &altopData[8]);

bool WadeSpace::PreProcessor::sameline(const Token* tok1, const Token* tok2)
{
    return tok1 && tok2 && tok1->location.sameline(tok2->location);
}

bool WadeSpace::PreProcessor::isHex(const string& s)
{
    return s.size() > 2 && (s.compare(0, 2, "0x") == 0 || s.compare(0, 2, "0X") == 0);
}

bool WadeSpace::PreProcessor::isOct(const string& s)
{
    return s.size() > 1 && (s[0] == '0') && (s[1] >= '0') && (s[1] < '8');
}

long long WadeSpace::PreProcessor::stringToLL(const string& s)
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

unsigned long long WadeSpace::PreProcessor::stringToULL(const string& s)
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

bool WadeSpace::PreProcessor::endsWith(const string& s, const string& e)
{
    return (s.size() >= e.size()) && equal(e.rbegin(), e.rend(), s.rbegin());
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

void WadeSpace::PreProcessor::portabilityBackslash(WadeSpace::PreProcessor::OutputList* outputList, const vector<string>& files, const Location& location)
{
    if (!outputList)
        return;
    Output err(files);
    err.type = WadeSpace::PreProcessor::Output::PORTABILITY_BACKSLASH;
    err.location = location;
    err.msg = "Combination 'backslash space newline' is not portable.";
    outputList->push_back(err);
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

bool WadeSpace::PreProcessor::isStringLiteralPrefix(const string& str)
{
    return str == "u" || str == "U" || str == "L" || str == "u8" ||
        str == "R" || str == "uR" || str == "UR" || str == "LR" || str == "u8R";
}

bool WadeSpace::PreProcessor::isFloatSuffix(const Token* tok)
{
    if (!tok || tok->str().size() != 1U)
        return false;
    const char c = tolower(tok->str()[0]);
    return c == 'f' || c == 'l';
}

#ifdef SIMPLECPP_WINDOWS
bool WadeSpace::PreProcessor::isAbsolutePath(const string& path)
{
    if (path.length() >= 3 && path[0] > 0 && isalpha(path[0]) && path[1] == ':' && (path[2] == '\\' || path[2] == '/'))
        return true;
    return path.length() > 1U && (path[0] == '/' || path[0] == '\\');
}
#else
bool WadeSpace::PreProcessor::isAbsolutePath(const string& path)
{
    return path.length() > 1U && path[0] == '/';
}
#endif

string WadeSpace::PreProcessor::simplifyPath(string path)
{
    if (path.empty())
        return path;

    string::size_type pos;

    // replace backslash separators
    replace(path.begin(), path.end(), '\\', '/');

    const bool unc(path.compare(0, 2, "//") == 0);

    // replace "//" with "/"
    pos = 0;
    while ((pos = path.find("//", pos)) != string::npos)
    {
        path.erase(pos, 1);
    }

    // remove "./"
    pos = 0;
    while ((pos = path.find("./", pos)) != string::npos)
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
    while ((pos = path.find("/..", pos)) != string::npos)
    {
        // not end of path, then string must be "/../"
        if (pos + 3 < path.size() && path[pos + 3] != '/')
        {
            ++pos;
            continue;
        }
        // get previous subpath
        string::size_type pos1 = path.rfind('/', pos - 1U);
        if (pos1 == string::npos)
        {
            pos1 = 0;
        }
        else
        {
            pos1 += 1U;
        }
        const string previousSubPath = path.substr(pos1, pos - pos1);
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

string WadeSpace::PreProcessor::dirPath(const string& path, bool withTrailingSlash)
{
    const size_t lastSlash = path.find_last_of("\\/");
    if (lastSlash == string::npos)
    {
        return "";
    }
    return path.substr(0, lastSlash + (withTrailingSlash ? 1U : 0U));
}

bool WadeSpace::PreProcessor::isStringLiteral_(const string& s)
{
    return s.size() > 1 && (s[0] == '\"') && (*s.rbegin() == '\"');
}

bool WadeSpace::PreProcessor::isCharLiteral_(const string& s)
{
    return s.size() > 1 && (s[0] == '\'') && (*s.rbegin() == '\'');
}

bool WadeSpace::PreProcessor::preprocessToken(TokenList& output, const Token** tok1, MacroMap& macros, std::vector<std::string>& files, OutputList* outputList)
{
    const Token* const tok = *tok1;
    const MacroMap::const_iterator it = macros.find(tok->str());
    if (it != macros.end())
    {
        TokenList value(files);
        try
        {
            *tok1 = it->second.expand(&value, tok, macros, files);
        }
        catch (Macro::Error& err)
        {
            if (outputList)
            {
                Output out(files);
                out.type = Output::SYNTAX_ERROR;
                out.location = err.location;
                out.msg = "failed to expand \'" + tok->str() + "\', " + err.what;
                outputList->push_back(out);
            }
            return false;
        }
        output.takeTokens(value);
    }
    else
    {
        if (!tok->comment)
            output.push_back(new Token(*tok));
        *tok1 = tok->next;
    }
    return true;
}

void WadeSpace::PreProcessor::preprocess(TokenList& output, const TokenList& rawtokens, vector<string>& files, FileDataCache& cache, const DUI& dui, OutputList* outputList, list<MacroUsage>* macroUsage, list<IfCond>* ifCond)
{
#ifdef SIMPLECPP_WINDOWS
    if (dui.clearIncludeCache)
        WadeSpace::PreProcessor::nonExistingFilesCache.clear();
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
    sizeOfType.insert(make_pair("char *", sizeof(char*)));
    sizeOfType.insert(make_pair("short *", sizeof(short*)));
    sizeOfType.insert(make_pair("short int *", sizeOfType["short *"]));
    sizeOfType.insert(make_pair("int *", sizeof(int*)));
    sizeOfType.insert(make_pair("long *", sizeof(long*)));
    sizeOfType.insert(make_pair("long int *", sizeOfType["long *"]));
    sizeOfType.insert(make_pair("long long *", sizeof(long long*)));
    sizeOfType.insert(make_pair("float *", sizeof(float*)));
    sizeOfType.insert(make_pair("double *", sizeof(double*)));
    sizeOfType.insert(make_pair("long double *", sizeof(long double*)));

    // use a dummy vector for the macros because as this is not part of the file and would add an empty entry - e.g. /usr/include/poll.h
    vector<string> dummy;

    const bool hasInclude = WadeSpace::PreProcessor::isCpp17OrLater(dui) || WadeSpace::PreProcessor::isGnu(dui);
    MacroMap macros;
    bool strictAnsiDefined = false;
    for (list<string>::const_iterator it = dui.defines.begin(); it != dui.defines.end(); ++it)
    {
        const string& macrostr = *it;
        const string::size_type eq = macrostr.find('=');
        const string::size_type par = macrostr.find('(');
        const string macroname = macrostr.substr(0, min(eq, par));
        if (macroname == "__STRICT_ANSI__")
            strictAnsiDefined = true;
        if (dui.undefined.find(macroname) != dui.undefined.end())
            continue;
        const string lhs(macrostr.substr(0, eq));
        const string rhs(eq == string::npos ? string("1") : macrostr.substr(eq + 1));
        const Macro macro(lhs, rhs, dummy);
        macros.insert(pair<TokenString, Macro>(macro.name(), macro));
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

    if (!dui.std.empty())
    {
        const cstd_t c_std = getCStd(dui.std);
        if (c_std != CUnknown)
        {
            const string std_def = getCStdString(c_std);
            if (!std_def.empty())
                macros.insert(make_pair("__STDC_VERSION__", Macro("__STDC_VERSION__", std_def, dummy)));
        }
        else
        {
            const cppstd_t cpp_std = getCppStd(dui.std);
            if (cpp_std == CPPUnknown)
            {
                if (outputList)
                {
                    Output err(files);
                    err.type = Output::DUI_ERROR;
                    err.msg = "unknown standard specified: '" + dui.std + "'";
                    outputList->push_back(err);
                }
                output.clear();
                return;
            }
            const string std_def = getCppStdString(cpp_std);
            if (!std_def.empty())
                macros.insert(make_pair("__cplusplus", Macro("__cplusplus", std_def, dummy)));
        }
    }

    // True => code in current #if block should be kept
    // ElseIsTrue => code in current #if block should be dropped. the code in the #else should be kept.
    // AlwaysFalse => drop all code in #if and #else
    enum IfState { True, ElseIsTrue, AlwaysFalse };
    stack<int> ifstates;
    stack<const Token*> iftokens;
    ifstates.push(True);

    stack<const Token*> includetokenstack;

    set<string> pragmaOnce;

    includetokenstack.push(rawtokens.cfront());
    for (list<string>::const_iterator it = dui.includes.begin(); it != dui.includes.end(); ++it)
    {
        const FileData* const filedata = cache.get("", *it, dui, false, files, outputList).first;
        if (filedata != nullptr && filedata->tokens.cfront() != nullptr)
            includetokenstack.push(filedata->tokens.cfront());
    }

    map<string, list<Location> > maybeUsedMacros;

    for (const Token* rawtok = nullptr; rawtok || !includetokenstack.empty();)
    {
        if (rawtok == nullptr)
        {
            rawtok = includetokenstack.top();
            includetokenstack.pop();
            continue;
        }

        if (rawtok->op == '#' && !sameline(rawtok->previousSkipComments(), rawtok))
        {
            if (!sameline(rawtok, rawtok->next))
            {
                rawtok = rawtok->next;
                continue;
            }
            rawtok = rawtok->next;
            if (!rawtok->name)
            {
                rawtok = gotoNextLine(rawtok);
                continue;
            }

            if (ifstates.size() <= 1U && (rawtok->str() == ELIF || rawtok->str() == ELSE || rawtok->str() == ENDIF))
            {
                if (outputList)
                {
                    Output err(files);
                    err.type = Output::SYNTAX_ERROR;
                    err.location = rawtok->location;
                    err.msg = "#" + rawtok->str() + " without #if";
                    outputList->push_back(err);
                }
                output.clear();
                return;
            }

            if (ifstates.top() == True && (rawtok->str() == ERROR || rawtok->str() == WARNING))
            {
                if (outputList)
                {
                    Output err(rawtok->location.files);
                    err.type = rawtok->str() == ERROR ? Output::ERROR : Output::WARNING;
                    err.location = rawtok->location;
                    for (const Token* tok = rawtok->next; tok && sameline(rawtok, tok); tok = tok->next)
                    {
                        if (!err.msg.empty() && isNameChar(tok->str()[0]))
                            err.msg += ' ';
                        err.msg += tok->str();
                    }
                    err.msg = '#' + rawtok->str() + ' ' + err.msg;
                    outputList->push_back(err);
                }
                if (rawtok->str() == ERROR)
                {
                    output.clear();
                    return;
                }
            }

            if (rawtok->str() == DEFINE)
            {
                if (ifstates.top() != True)
                    continue;
                try
                {
                    const Macro& macro = Macro(rawtok->previous, files);
                    if (dui.undefined.find(macro.name()) == dui.undefined.end())
                    {
                        const MacroMap::iterator it = macros.find(macro.name());
                        if (it == macros.end())
                            macros.insert(pair<TokenString, Macro>(macro.name(), macro));
                        else
                            it->second = macro;
                    }
                }
                catch (const runtime_error&)
                {
                    if (outputList)
                    {
                        Output err(files);
                        err.type = Output::SYNTAX_ERROR;
                        err.location = rawtok->location;
                        err.msg = "Failed to parse #define";
                        outputList->push_back(err);
                    }
                    output.clear();
                    return;
                }
                catch (Macro::Error& err)
                {
                    if (outputList)
                    {
                        Output out(files);
                        out.type = Output::SYNTAX_ERROR;
                        out.location = err.location;
                        out.msg = "Failed to parse #define, " + err.what;
                        outputList->push_back(out);
                    }
                    output.clear();
                    return;
                }
            }
            else if (ifstates.top() == True && rawtok->str() == INCLUDE)
            {
                TokenList inc1(files);
                for (const Token* inctok = rawtok->next; sameline(rawtok, inctok); inctok = inctok->next)
                {
                    if (!inctok->comment)
                        inc1.push_back(new Token(*inctok));
                }
                TokenList inc2(files);
                if (!inc1.empty() && inc1.cfront()->name)
                {
                    const Token* inctok = inc1.cfront();
                    if (!preprocessToken(inc2, &inctok, macros, files, outputList))
                    {
                        output.clear();
                        return;
                    }
                }
                else
                {
                    inc2.takeTokens(inc1);
                }

                if (!inc1.empty() && !inc2.empty() && inc2.cfront()->op == '<' && inc2.cback()->op == '>')
                {
                    TokenString hdr;
                    // TODO: Sometimes spaces must be added in the string
                    // Somehow preprocessToken etc must be told that the location should be source location not destination location
                    for (const Token* tok = inc2.cfront(); tok; tok = tok->next)
                    {
                        hdr += tok->str();
                    }
                    inc2.clear();
                    inc2.push_back(new Token(hdr, inc1.cfront()->location));
                    inc2.front()->op = '<';
                }

                if (inc2.empty() || inc2.cfront()->str().size() <= 2U)
                {
                    if (outputList)
                    {
                        Output err(files);
                        err.type = Output::SYNTAX_ERROR;
                        err.location = rawtok->location;
                        err.msg = "No header in #include";
                        outputList->push_back(err);
                    }
                    output.clear();
                    return;
                }

                const Token* const inctok = inc2.cfront();

                const bool systemheader = (inctok->str()[0] == '<');
                const string header(inctok->str().substr(1U, inctok->str().size() - 2U));
                const FileData* const filedata = cache.get(rawtok->location.file(), header, dui, systemheader, files, outputList).first;
                if (filedata == nullptr)
                {
                    if (outputList)
                    {
                        Output out(files);
                        out.type = Output::MISSING_HEADER;
                        out.location = rawtok->location;
                        out.msg = "Header not found: " + inctok->str();
                        outputList->push_back(out);
                    }
                }
                else if (includetokenstack.size() >= 400)
                {
                    if (outputList)
                    {
                        Output out(files);
                        out.type = Output::INCLUDE_NESTED_TOO_DEEPLY;
                        out.location = rawtok->location;
                        out.msg = "#include nested too deeply";
                        outputList->push_back(out);
                    }
                }
                else if (pragmaOnce.find(filedata->filename) == pragmaOnce.end())
                {
                    includetokenstack.push(gotoNextLine(rawtok));
                    rawtok = filedata->tokens.cfront();
                    continue;
                }
            }
            else if (rawtok->str() == IF || rawtok->str() == IFDEF || rawtok->str() == IFNDEF || rawtok->str() == ELIF)
            {
                if (!sameline(rawtok, rawtok->next))
                {
                    if (outputList)
                    {
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
                else if (rawtok->str() == IFDEF)
                {
                    conditionIsTrue = (macros.find(rawtok->next->str()) != macros.end() || (hasInclude && rawtok->next->str() == HAS_INCLUDE));
                    maybeUsedMacros[rawtok->next->str()].push_back(rawtok->next->location);
                }
                else if (rawtok->str() == IFNDEF)
                {
                    conditionIsTrue = (macros.find(rawtok->next->str()) == macros.end() && !(hasInclude && rawtok->next->str() == HAS_INCLUDE));
                    maybeUsedMacros[rawtok->next->str()].push_back(rawtok->next->location);
                }
                else
                { /*if (rawtok->str() == IF || rawtok->str() == ELIF)*/
                    TokenList expr(files);
                    for (const Token* tok = rawtok->next; tok && tok->location.sameline(rawtok->location); tok = tok->next)
                    {
                        if (!tok->name)
                        {
                            expr.push_back(new Token(*tok));
                            continue;
                        }

                        if (tok->str() == DEFINED)
                        {
                            tok = tok->next;
                            const bool par = (tok && tok->op == '(');
                            if (par)
                                tok = tok->next;
                            maybeUsedMacros[rawtok->next->str()].push_back(rawtok->next->location);
                            if (tok)
                            {
                                if (macros.find(tok->str()) != macros.end())
                                    expr.push_back(new Token("1", tok->location));
                                else if (hasInclude && tok->str() == HAS_INCLUDE)
                                    expr.push_back(new Token("1", tok->location));
                                else
                                    expr.push_back(new Token("0", tok->location));
                            }
                            if (par)
                                tok = tok ? tok->next : nullptr;
                            if (!tok || !sameline(rawtok, tok) || (par && tok->op != ')'))
                            {
                                if (outputList)
                                {
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

                        if (hasInclude && tok->str() == HAS_INCLUDE)
                        {
                            tok = tok->next;
                            const bool par = (tok && tok->op == '(');
                            if (par)
                                tok = tok->next;
                            bool closingAngularBracket = false;
                            if (tok)
                            {
                                const string& sourcefile = rawtok->location.file();
                                const bool systemheader = (tok && tok->op == '<');
                                string header;

                                if (systemheader)
                                {
                                    while ((tok = tok->next) && tok->op != '>')
                                        header += tok->str();
                                    if (tok && tok->op == '>')
                                        closingAngularBracket = true;
                                }
                                else
                                {
                                    header = tok->str().substr(1U, tok->str().size() - 2U);
                                    closingAngularBracket = true;
                                }
                                ifstream f;
                                const string header2 = openHeader(f, dui, sourcefile, header, systemheader);
                                expr.push_back(new Token(header2.empty() ? "0" : "1", tok->location));
                            }
                            if (par)
                                tok = tok ? tok->next : nullptr;
                            if (!tok || !sameline(rawtok, tok) || (par && tok->op != ')') || (!closingAngularBracket))
                            {
                                if (outputList)
                                {
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

                        const Token* tmp = tok;
                        if (!preprocessToken(expr, &tmp, macros, files, outputList))
                        {
                            output.clear();
                            return;
                        }
                        if (!tmp)
                            break;
                        tok = tmp->previous;
                    }
                    try
                    {
                        if (ifCond)
                        {
                            string E;
                            for (const Token* tok = expr.cfront(); tok; tok = tok->next)
                                E += (E.empty() ? "" : " ") + tok->str();
                            const long long result = evaluate(expr, dui, sizeOfType);
                            conditionIsTrue = (result != 0);
                            ifCond->push_back(IfCond(rawtok->location, E, result));
                        }
                        else
                        {
                            const long long result = evaluate(expr, dui, sizeOfType);
                            conditionIsTrue = (result != 0);
                        }
                    }
                    catch (const exception& e)
                    {
                        if (outputList)
                        {
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

                if (rawtok->str() != ELIF)
                {
                    // push a new ifstate..
                    if (ifstates.top() != True)
                        ifstates.push(AlwaysFalse);
                    else
                        ifstates.push(conditionIsTrue ? True : ElseIsTrue);
                    iftokens.push(rawtok);
                }
                else if (ifstates.top() == True)
                {
                    ifstates.top() = AlwaysFalse;
                    iftokens.top()->nextcond = rawtok;
                    iftokens.top() = rawtok;
                }
                else if (ifstates.top() == ElseIsTrue && conditionIsTrue)
                {
                    ifstates.top() = True;
                    iftokens.top()->nextcond = rawtok;
                    iftokens.top() = rawtok;
                }
            }
            else if (rawtok->str() == ELSE)
            {
                ifstates.top() = (ifstates.top() == ElseIsTrue) ? True : AlwaysFalse;
                iftokens.top()->nextcond = rawtok;
                iftokens.top() = rawtok;
            }
            else if (rawtok->str() == ENDIF)
            {
                ifstates.pop();
                iftokens.top()->nextcond = rawtok;
                iftokens.pop();
            }
            else if (rawtok->str() == UNDEF)
            {
                if (ifstates.top() == True)
                {
                    const Token* tok = rawtok->next;
                    while (sameline(rawtok, tok) && tok->comment)
                        tok = tok->next;
                    if (sameline(rawtok, tok))
                        macros.erase(tok->str());
                }
            }
            else if (ifstates.top() == True && rawtok->str() == PRAGMA && rawtok->next && rawtok->next->str() == ONCE && sameline(rawtok, rawtok->next))
            {
                pragmaOnce.insert(rawtok->location.file());
            }
            if (ifstates.top() != True && rawtok->nextcond)
                rawtok = rawtok->nextcond->previous;
            else
                rawtok = gotoNextLine(rawtok);
            continue;
        }

        if (ifstates.top() != True)
        {
            // drop code
            rawtok = gotoNextLine(rawtok);
            continue;
        }

        bool hash = false, hashhash = false;
        if (rawtok->op == '#' && sameline(rawtok, rawtok->next))
        {
            if (rawtok->next->op != '#')
            {
                hash = true;
                rawtok = rawtok->next; // skip '#'
            }
            else if (sameline(rawtok, rawtok->next->next))
            {
                hashhash = true;
                rawtok = rawtok->next->next; // skip '#' '#'
            }
        }

        const Location loc(rawtok->location);
        TokenList tokens(files);

        if (!preprocessToken(tokens, &rawtok, macros, files, outputList))
        {
            output.clear();
            return;
        }

        if (hash || hashhash)
        {
            string s;
            for (const Token* hashtok = tokens.cfront(); hashtok; hashtok = hashtok->next)
                s += hashtok->str();
            if (hash)
                output.push_back(new Token('\"' + s + '\"', loc));
            else if (output.back())
                output.back()->setstr(output.cback()->str() + s);
            else
                output.push_back(new Token(s, loc));
        }
        else
        {
            output.takeTokens(tokens);
        }
    }

    if (macroUsage)
    {
        for (MacroMap::const_iterator macroIt = macros.begin(); macroIt != macros.end(); ++macroIt)
        {
            const Macro& macro = macroIt->second;
            list<Location> usage = macro.usage();
            const list<Location>& temp = maybeUsedMacros[macro.name()];
            usage.insert(usage.end(), temp.begin(), temp.end());
            for (list<Location>::const_iterator usageIt = usage.begin(); usageIt != usage.end(); ++usageIt)
            {
                MacroUsage mu(usageIt->files, macro.valueDefinedInCode());
                mu.macroName = macro.name();
                mu.macroLocation = macro.defineLocation();
                mu.useLocation = *usageIt;
                macroUsage->push_back(mu);
            }
        }
    }
}

void WadeSpace::PreProcessor::cleanup(FileDataCache& cache)
{
    cache.clear();
}

cstd_t WadeSpace::PreProcessor::getCStd(const string& std)
{
    if (std == "c90" || std == "c89" || std == "iso9899:1990" || std == "iso9899:199409" || std == "gnu90" || std == "gnu89")
        return C89;
    if (std == "c99" || std == "c9x" || std == "iso9899:1999" || std == "iso9899:199x" || std == "gnu99" || std == "gnu9x")
        return C99;
    if (std == "c11" || std == "c1x" || std == "iso9899:2011" || std == "gnu11" || std == "gnu1x")
        return C11;
    if (std == "c17" || std == "c18" || std == "iso9899:2017" || std == "iso9899:2018" || std == "gnu17" || std == "gnu18")
        return C17;
    if (std == "c23" || std == "gnu23" || std == "c2x" || std == "gnu2x")
        return C23;
    return CUnknown;
}

string WadeSpace::PreProcessor::getCStdString(cstd_t std)
{
    switch (std)
    {
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

string WadeSpace::PreProcessor::getCStdString(const string& std)
{
    return getCStdString(getCStd(std));
}

cppstd_t WadeSpace::PreProcessor::getCppStd(const string& std)
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

string WadeSpace::PreProcessor::getCppStdString(cppstd_t std)
{
    switch (std)
    {
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

string WadeSpace::PreProcessor::getCppStdString(const string& std)
{
    return getCppStdString(getCppStd(std));
}

bool WadeSpace::PreProcessor::isCpp17OrLater(const DUI& dui)
{
    const string std_ver = getCppStdString(dui.std);
    return !std_ver.empty() && (std_ver >= "201703L");
}

bool WadeSpace::PreProcessor::isGnu(const DUI& dui)
{
    return dui.std.rfind("gnu", 0) != string::npos;
}

void WadeSpace::PreProcessor::getLocaltime(struct tm& ltime)
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

string WadeSpace::PreProcessor::getDateDefine(const struct tm* timep)
{
    char buf[] = "??? ?? ????";
    strftime(buf, sizeof(buf), "%b %d %Y", timep);
    return std::string("\"").append(buf).append("\"");
}

string WadeSpace::PreProcessor::getTimeDefine(const struct tm* timep)
{
    char buf[] = "??:??:??";
    strftime(buf, sizeof(buf), "%H:%M:%S", timep);
    return std::string("\"").append(buf).append("\"");
}

void WadeSpace::PreProcessor::simplifyNumbers(TokenList& expr)
{
    for (Token* tok = expr.front(); tok; tok = tok->next)
    {
        if (tok->str().size() == 1U)
            continue;
        if (tok->str().compare(0, 2, "0x") == 0)
            tok->setstr(toString(stringToULL(tok->str())));
        else if (!tok->number && tok->str().find('\'') != std::string::npos)
            tok->setstr(toString(characterLiteralToLL(tok->str())));
    }
}

void WadeSpace::PreProcessor::simplifyComments(TokenList& expr)
{
    for (Token* tok = expr.front(); tok;)
    {
        Token* const d = tok;
        tok = tok->next;
        if (d->comment)
            expr.deleteToken(d);
    }
}

void WadeSpace::PreProcessor::simplifySizeof(TokenList& expr, const map<string, size_t>& sizeOfType)
{
    for (Token* tok = expr.front(); tok; tok = tok->next)
    {
        if (tok->str() != "sizeof")
            continue;
        Token* tok1 = tok->next;
        if (!tok1)
        {
            throw std::runtime_error("missing sizeof argument");
        }
        Token* tok2 = tok1->next;
        if (!tok2)
        {
            throw std::runtime_error("missing sizeof argument");
        }
        if (tok1->op == '(')
        {
            tok1 = tok1->next;
            while (tok2->op != ')')
            {
                tok2 = tok2->next;
                if (!tok2)
                {
                    throw std::runtime_error("invalid sizeof expression");
                }
            }
        }

        std::string type;
        for (Token* typeToken = tok1; typeToken != tok2; typeToken = typeToken->next)
        {
            if ((typeToken->str() == "unsigned" || typeToken->str() == "signed") && typeToken->next->name)
                continue;
            if (typeToken->str() == "*" && type.find('*') != std::string::npos)
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

void WadeSpace::PreProcessor::simplifyHasInclude(TokenList& expr, const DUI& dui)
{
    if (!isCpp17OrLater(dui) && !isGnu(dui))
        return;

    for (Token* tok = expr.front(); tok; tok = tok->next)
    {
        if (tok->str() != HAS_INCLUDE)
            continue;
        Token* tok1 = tok->next;
        if (!tok1)
        {
            throw std::runtime_error("missing __has_include argument");
        }
        Token* tok2 = tok1->next;
        if (!tok2)
        {
            throw std::runtime_error("missing __has_include argument");
        }
        if (tok1->op == '(')
        {
            tok1 = tok1->next;
            while (tok2->op != ')')
            {
                tok2 = tok2->next;
                if (!tok2)
                {
                    throw std::runtime_error("invalid __has_include expression");
                }
            }
        }

        const std::string& sourcefile = tok->location.file();
        const bool systemheader = (tok1 && tok1->op == '<');
        std::string header;
        if (systemheader)
        {
            Token* tok3 = tok1->next;
            if (!tok3)
            {
                throw std::runtime_error("missing __has_include closing angular bracket");
            }
            while (tok3->op != '>')
            {
                tok3 = tok3->next;
                if (!tok3)
                {
                    throw std::runtime_error("invalid __has_include expression");
                }
            }

            for (Token* headerToken = tok1->next; headerToken != tok3; headerToken = headerToken->next)
                header += headerToken->str();
        }
        else
        {
            header = tok1->str().substr(1U, tok1->str().size() - 2U);
        }
        std::ifstream f;
        const std::string header2 = openHeader(f, dui, sourcefile, header, systemheader);
        tok->setstr(header2.empty() ? "0" : "1");

        tok2 = tok2->next;
        while (tok->next != tok2)
            expr.deleteToken(tok->next);
    }
}

void WadeSpace::PreProcessor::simplifyName(TokenList& expr)
{
    for (Token* tok = expr.front(); tok; tok = tok->next)
    {
        if (tok->name)
        {
            if (altop.find(tok->str()) != altop.end())
            {
                bool alt;
                if (tok->str() == "not" || tok->str() == "compl")
                {
                    alt = isAlternativeUnaryOp(tok, tok->str());
                }
                else
                {
                    alt = isAlternativeBinaryOp(tok, tok->str());
                }
                if (alt)
                    continue;
            }
            if (tok->next && tok->next->str() == "(")
                throw std::runtime_error("undefined function-like macro invocation: " + tok->str() + "( ... )");
            tok->setstr("0");
        }
    }
}

long long WadeSpace::PreProcessor::evaluate(TokenList& expr, const DUI& dui, const map<string, size_t>& sizeOfType)
{
    simplifyComments(expr);
    simplifySizeof(expr, sizeOfType);
    simplifyHasInclude(expr, dui);
    simplifyName(expr);
    simplifyNumbers(expr);
    expr.constFold();
    return expr.cfront() && expr.cfront() == expr.cback() && expr.cfront()->number ? stringToLL(expr.cfront()->str()) : 0LL;
}

const Token* WadeSpace::PreProcessor::gotoNextLine(const Token* tok)
{
    const unsigned int line = tok->location.line;
    const unsigned int file = tok->location.fileIndex;
    while (tok && tok->location.line == line && tok->location.fileIndex == file)
        tok = tok->next;
    return tok;
}

string WadeSpace::PreProcessor::openHeader(ifstream& f, const DUI& dui, const string& sourcefile, const string& header, bool systemheader)
{
    if (isAbsolutePath(header))
        return openHeaderDirect(f, simplifyPath(header));

    // prefer first to search the header relatively to source file if found, when not a system header
    if (!systemheader)
    {
        std::string path = openHeaderDirect(f, simplifyPath(dirPath(sourcefile) + header));
        if (!path.empty())
        {
            return path;
        }
    }

    // search the header on the include paths (provided by the flags "-I...")
    for (const auto& includePath : dui.includePaths)
    {
        std::string path = openHeaderDirect(f, simplifyPath(includePath + "/" + header));
        if (!path.empty())
            return path;
    }
    return "";
}

string WadeSpace::PreProcessor::openHeaderDirect(ifstream& f, const string& path)
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

long long WadeSpace::PreProcessor::characterLiteralToLL(const string& str)
{
    // default is wide/utf32
    bool narrow = false;
    bool utf8 = false;
    bool utf16 = false;

    std::size_t pos;

    if (!str.empty() && str[0] == '\'')
    {
        narrow = true;
        pos = 1;
    }
    else if (str.size() >= 2 && str[0] == 'u' && str[1] == '\'')
    {
        utf16 = true;
        pos = 2;
    }
    else if (str.size() >= 3 && str[0] == 'u' && str[1] == '8' && str[2] == '\'')
    {
        utf8 = true;
        pos = 3;
    }
    else if (str.size() >= 2 && (str[0] == 'L' || str[0] == 'U') && str[1] == '\'')
    {
        pos = 2;
    }
    else
        throw std::runtime_error("expected a character literal");

    unsigned long long multivalue = 0;

    std::size_t nbytes = 0;

    while (pos + 1 < str.size())
    {
        if (str[pos] == '\'' || str[pos] == '\n')
            throw std::runtime_error("raw single quotes and newlines not allowed in character literals");

        if (nbytes >= 1 && !narrow)
            throw std::runtime_error("multiple characters only supported in narrow character literals");

        unsigned long long value;

        if (str[pos] == '\\')
        {
            pos++;
            const char escape = str[pos++];

            if (pos >= str.size())
                throw std::runtime_error("unexpected end of character literal");

            switch (escape)
            {
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
                case 'U':
                {
                    // universal character names have exactly 4 or 8 digits
                    const std::size_t ndigits = (escape == 'u' ? 4 : 8);
                    value = stringToULLbounded(str, pos, 16, ndigits, ndigits);

                    // UTF-8 encodes code points above 0x7f in multiple code units
                    // code points above 0x10ffff are not allowed
                    if (((narrow || utf8) && value > 0x7f) || (utf16 && value > 0xffff) || value > 0x10ffff)
                        throw std::runtime_error("code point too large");

                    if (value >= 0xd800 && value <= 0xdfff)
                        throw std::runtime_error("surrogate code points not allowed in universal character names");

                    break;
                }

                default:
                    throw std::runtime_error("invalid escape sequence");
            }
        }
        else
        {
            value = static_cast<unsigned char>(str[pos++]);

            if (!narrow && value >= 0x80)
            {
                // Assuming this is a UTF-8 encoded code point.
                // This decoder may not completely validate the input.
                // Noncharacters are neither rejected nor replaced.

                int additional_bytes;
                if (value >= 0xf5)  // higher values would result in code points above 0x10ffff
                    throw std::runtime_error("assumed UTF-8 encoded source, but sequence is invalid");
                if (value >= 0xf0)
                    additional_bytes = 3;
                else if (value >= 0xe0)
                    additional_bytes = 2;
                else if (value >= 0xc2) // 0xc0 and 0xc1 are always overlong 2-bytes encodings
                    additional_bytes = 1;
                else
                    throw std::runtime_error("assumed UTF-8 encoded source, but sequence is invalid");

                value &= (1 << (6 - additional_bytes)) - 1;

                while (additional_bytes--)
                {
                    if (pos + 1 >= str.size())
                        throw std::runtime_error("assumed UTF-8 encoded source, but character literal ends unexpectedly");

                    const unsigned char c = str[pos++];

                    if (((c >> 6) != 2)    // ensure c has form 0xb10xxxxxx
                        || (!value && additional_bytes == 1 && c < 0xa0)    // overlong 3-bytes encoding
                        || (!value && additional_bytes == 2 && c < 0x90))   // overlong 4-bytes encoding
                        throw std::runtime_error("assumed UTF-8 encoded source, but sequence is invalid");

                    value = (value << 6) | (c & ((1 << 7) - 1));
                }

                if (value >= 0xd800 && value <= 0xdfff)
                    throw std::runtime_error("assumed UTF-8 encoded source, but sequence is invalid");

                if ((utf8 && value > 0x7f) || (utf16 && value > 0xffff) || value > 0x10ffff)
                    throw std::runtime_error("code point too large");
            }
        }

        if (((narrow || utf8) && value > std::numeric_limits<unsigned char>::max()) || (utf16 && value >> 16) || value >> 32)
            throw std::runtime_error("numeric escape sequence too large");

        multivalue <<= CHAR_BIT;
        multivalue |= value;
        nbytes++;
    }

    if (pos + 1 != str.size() || str[pos] != '\'')
        throw std::runtime_error("missing closing quote in character literal");

    if (!nbytes)
        throw std::runtime_error("empty character literal");

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

unsigned long long WadeSpace::PreProcessor::stringToULLbounded(const string& s, size_t& pos, int base, ptrdiff_t minlen, size_t maxlen)
{
    const string sub = s.substr(pos, maxlen);
    const char* const start = sub.c_str();
    char* end;
    const unsigned long long value = strtoull(start, &end, base);
    pos += end - start;
    if (end - start < minlen)
        throw runtime_error("expected digit");
    return value;
}
