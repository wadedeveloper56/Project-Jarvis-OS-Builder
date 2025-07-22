#include "ExclusiveOrExpression.h"

using namespace WadeSpace;
using namespace std;

ExclusiveOrExpression::ExclusiveOrExpression(AndExpression* ae) : ae(nullptr), eoe(nullptr)
{
}

ExclusiveOrExpression::ExclusiveOrExpression(ExclusiveOrExpression* eoe, AndExpression* ae) : ae(nullptr), eoe(nullptr)
{
}

ExclusiveOrExpression::ExclusiveOrExpression() : ae(nullptr), eoe(nullptr)
{
}

ExclusiveOrExpression::~ExclusiveOrExpression()
{
}
