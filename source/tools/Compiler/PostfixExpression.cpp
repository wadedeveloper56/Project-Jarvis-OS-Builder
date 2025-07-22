#include "PostfixExpression.h"

using namespace WadeSpace;
using namespace std;

PostfixExpression::PostfixExpression(PrimaryExpression* pe) : pe(pe), pfe(nullptr), exp(nullptr), aev(nullptr),
                                                              iv(nullptr), tn(nullptr), str1(""), str2("")
{
}

PostfixExpression::PostfixExpression(PostfixExpression* fpe, string str, string str2) : pe(nullptr), pfe(pfe),
	aev(nullptr), exp(nullptr), iv(nullptr), tn(nullptr), str1(str1), str2(str2)
{
}

PostfixExpression::PostfixExpression(PostfixExpression* pfe, Expression* exp) : pe(nullptr), pfe(pfe), exp(exp),
	aev(nullptr), iv(nullptr), tn(nullptr), str1(""), str2("")
{
}

PostfixExpression::PostfixExpression(PostfixExpression* pfe, vector<AssignmentExpression*>* aev) : pe(nullptr),
	pfe(pfe), exp(nullptr), aev(aev), iv(nullptr), tn(nullptr), str1(""), str2("")
{
}

PostfixExpression::PostfixExpression(TypeName* tn, vector<Initializer*>* iv) : pe(nullptr), pfe(pfe), exp(nullptr),
                                                                               aev(nullptr), iv(iv), tn(tn), str1(""),
                                                                               str2("")
{
}

PostfixExpression::PostfixExpression() : pe(nullptr), pfe(nullptr), exp(nullptr), aev(nullptr), iv(nullptr),
                                         tn(nullptr), str1(""), str2("")
{
}

PostfixExpression::~PostfixExpression()
{
}
