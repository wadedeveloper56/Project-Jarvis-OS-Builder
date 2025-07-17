#include "PostfixExpression.h"

using namespace WadeSpace;
using namespace std;

PostfixExpression::PostfixExpression(PrimaryExpression* pe) :pe(pe), pfe(NULL), exp(NULL), aev(NULL), iv(NULL), tn(NULL), str1(""), str2("") {}
PostfixExpression::PostfixExpression(PostfixExpression* fpe, string str, string str2) :pe(NULL), pfe(pfe), aev(NULL), exp(NULL), iv(NULL), tn(NULL), str1(str1), str2(str2) {}
PostfixExpression::PostfixExpression(PostfixExpression* pfe, Expression* exp) :pe(NULL), pfe(pfe), exp(exp), aev(NULL), iv(NULL), tn(NULL), str1(""), str2("") {}
PostfixExpression::PostfixExpression(PostfixExpression* pfe, vector<AssignmentExpression *>* aev) :pe(NULL), pfe(pfe), exp(NULL), aev(aev), iv(NULL), tn(NULL), str1(""), str2("") {}
PostfixExpression::PostfixExpression(TypeName* tn, vector<Initializer *>* iv) :pe(NULL), pfe(pfe), exp(NULL), aev(NULL), iv(iv), tn(tn), str1(""), str2("") {}
PostfixExpression::PostfixExpression() :pe(NULL), pfe(NULL), exp(NULL), aev(NULL), iv(NULL), tn(NULL), str1(""), str2("") {}
PostfixExpression::~PostfixExpression() {}
