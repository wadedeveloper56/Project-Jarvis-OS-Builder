#include "InclusiveOrExpression.h"

using namespace WadeSpace;
using namespace std;

InclusiveOrExpression::InclusiveOrExpression(ExclusiveOrExpression* eoe) : eoe(nullptr), ioe(nullptr)
{
}

InclusiveOrExpression::InclusiveOrExpression(InclusiveOrExpression* ioe, ExclusiveOrExpression* eoe) : eoe(nullptr),
	ioe(nullptr)
{
}

InclusiveOrExpression::InclusiveOrExpression() : eoe(nullptr), ioe(nullptr)
{
}

InclusiveOrExpression::~InclusiveOrExpression()
{
	delete eoe;
	delete ioe;
}
