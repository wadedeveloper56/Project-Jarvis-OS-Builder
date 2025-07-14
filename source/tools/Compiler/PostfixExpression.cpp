#include "PostfixExpression.h"

using namespace WadeSpace;
using namespace std;

PostfixExpression::PostfixExpression(PrimaryExpression& pe) :pe(pe), pfe(nullopt), exp(nullopt), aev(nullopt), iv(nullopt), tn(nullopt), str1(""), str2("") {}
PostfixExpression::PostfixExpression(PostfixExpression& fpe, string str, string str2) :pe(nullopt), pfe(pfe), aev(nullopt), exp(nullopt), iv(nullopt), tn(nullopt), str1(str1), str2(str2) {}
PostfixExpression::PostfixExpression(PostfixExpression& pfe, Expression& exp) :pe(nullopt), pfe(pfe), exp(exp), aev(nullopt), iv(nullopt), tn(nullopt), str1(""), str2("") {}
PostfixExpression::PostfixExpression(PostfixExpression& pfe, vector<AssignmentExpression>& aev) :pe(nullopt), pfe(pfe), exp(nullopt), aev(aev), iv(nullopt), tn(nullopt), str1(""), str2("") {}
PostfixExpression::PostfixExpression(TypeName& tn, vector<Initializer>& iv) :pe(nullopt), pfe(pfe), exp(nullopt), aev(nullopt), iv(iv), tn(tn), str1(""), str2("") {}
PostfixExpression::PostfixExpression() :pe(nullopt), pfe(nullopt), exp(nullopt), aev(nullopt), iv(nullopt), tn(nullopt), str1(""), str2("") {}
PostfixExpression::~PostfixExpression() {}
