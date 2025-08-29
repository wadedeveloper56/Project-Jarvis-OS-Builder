#include "pch.h"
#include "simplecpp.h"

using namespace simplecpp;
using namespace std;

extern bool sameline(const Token* tok1, const Token* tok2);

Token::Token(const TokenString& s, const Location& loc, bool wsahead) : whitespaceahead(wsahead), location(loc), previous(nullptr), next(nullptr), nextcond(nullptr), string(s) {
    flags();
}

Token::Token(const Token& tok) :
    macro(tok.macro), op(tok.op), comment(tok.comment), name(tok.name), number(tok.number), whitespaceahead(tok.whitespaceahead), location(tok.location), previous(nullptr), next(nullptr), nextcond(nullptr), string(tok.string), mExpandedFrom(tok.mExpandedFrom) {
}

void Token::flags() {
    name = (isalpha(static_cast<unsigned char>(string[0])) || string[0] == '_' || string[0] == '$')
        && (memchr(string.c_str(), '\'', string.size()) == nullptr);
    comment = string.size() > 1U && string[0] == '/' && (string[1] == '/' || string[1] == '*');
    number = isNumberLike(string);
    op = (string.size() == 1U && !name && !comment && !number) ? string[0] : '\0';
}

const TokenString& Token::str() const {
    return string;
}

void Token::setstr(const std::string& s) {
    string = s;
    flags();
}

bool Token::isOneOf(const char ops[]) const
{
    return (op != '\0') && (std::strchr(ops, op) != nullptr);
}

bool Token::startsWithOneOf(const char c[]) const
{
    return std::strchr(c, string[0]) != nullptr;
}

bool Token::endsWithOneOf(const char c[]) const
{
    return std::strchr(c, string[string.size() - 1U]) != nullptr;
}

void Token::printAll() const
{
    const Token* tok = this;
    while (tok->previous)
        tok = tok->previous;
    for (; tok; tok = tok->next) {
        if (tok->previous) {
            std::cout << (sameline(tok, tok->previous) ? ' ' : '\n');
        }
        std::cout << tok->str();
    }
    std::cout << std::endl;
}

void Token::printOut() const
{
    for (const Token* tok = this; tok; tok = tok->next) {
        if (tok != this) {
            std::cout << (sameline(tok, tok->previous) ? ' ' : '\n');
        }
        std::cout << tok->str();
    }
    std::cout << std::endl;
}

bool Token::isNumberLike(const std::string& str) {
    return isdigit(static_cast<unsigned char>(str[0])) ||
        (str.size() > 1U && (str[0] == '-' || str[0] == '+') && isdigit(static_cast<unsigned char>(str[1])));
}

const Token* Token::previousSkipComments() const {
    const Token* tok = this->previous;
    while (tok && tok->comment)
        tok = tok->previous;
    return tok;
}

const Token* Token::nextSkipComments() const {
    const Token* tok = this->next;
    while (tok && tok->comment)
        tok = tok->next;
    return tok;
}

void Token::setExpandedFrom(const Token* tok, const Macro* m) {
    mExpandedFrom = tok->mExpandedFrom;
    mExpandedFrom.insert(m);
    if (tok->whitespaceahead)
        whitespaceahead = true;
}

bool Token::isExpandedFrom(const Macro* m) const {
    return mExpandedFrom.find(m) != mExpandedFrom.end();
}
