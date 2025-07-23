#include "AndExpression.h"

using namespace WadeSpace;
using namespace std;

AndExpression::AndExpression(EqualityExpression* equalityExpression) :andExpression(nullptr), equalityExpression(equalityExpression)
{
}

AndExpression::AndExpression(AndExpression* andExpression, EqualityExpression* equalityExpression) :andExpression(andExpression), equalityExpression(equalityExpression)
{
}

AndExpression::AndExpression() : andExpression(nullptr), equalityExpression(nullptr)
{
}

AndExpression::~AndExpression()
{
	if (andExpression != nullptr) delete andExpression;
	if (equalityExpression != nullptr) delete equalityExpression;
}

AndExpression* AndExpression::getAndExpression() const { return andExpression; }
EqualityExpression* AndExpression::getEqualityExpression() const { return equalityExpression; }
