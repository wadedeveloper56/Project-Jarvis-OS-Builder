#include "ExclusiveOrExpression.h"

using namespace WadeSpace;
using namespace std;

ExclusiveOrExpression::ExclusiveOrExpression(AndExpression* ae) : ae(ae), eoe(nullptr)
{
}

ExclusiveOrExpression::ExclusiveOrExpression(ExclusiveOrExpression* eoe, AndExpression* ae) : ae(ae), eoe(eoe)
{
}

ExclusiveOrExpression::ExclusiveOrExpression() : ae(nullptr), eoe(nullptr)
{
}

ExclusiveOrExpression::~ExclusiveOrExpression()
{
	delete ae;
	delete eoe;
}
