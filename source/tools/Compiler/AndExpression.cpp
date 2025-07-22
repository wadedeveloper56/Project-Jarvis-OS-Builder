#include "AndExpression.h"

using namespace WadeSpace;
using namespace std;

AndExpression::AndExpression(EqualityExpression* ee) : ae(nullptr), ee(ee)
{
}

AndExpression::AndExpression(AndExpression* ae, EqualityExpression* ee) : ae(ae), ee(ee)
{
}

AndExpression::AndExpression() : ae(nullptr), ee(nullptr)
{
}

AndExpression::~AndExpression()
{
	if (ae != nullptr) delete ae;
	if (ae != nullptr) delete ee;
}

AndExpression* AndExpression::getAndExpression() const { return ae; }
EqualityExpression* AndExpression::getEqualityExpression() const { return ee; }
