#include "AdditiveExpression.h"

using namespace WadeSpace;
using namespace std;

AdditiveExpression::AdditiveExpression(MultiplicativeExpression* me) :ae(NULL), op(""), me(NULL) {}
AdditiveExpression::AdditiveExpression(AdditiveExpression* ae, string op, MultiplicativeExpression* me) :ae(ae), op(op), me(me) {}
AdditiveExpression::AdditiveExpression() :ae(NULL), op(""), me(NULL) {}
AdditiveExpression::~AdditiveExpression() {
	if (ae) delete ae;
	if (me) delete me;
}
bool AdditiveExpression::hasMultiplicativeExpression() const { return me != NULL; }
bool AdditiveExpression::hasAdditiveExpression() const { return ae != NULL; }
MultiplicativeExpression* AdditiveExpression::getMultiplicativeExpression() const { return me; }
AdditiveExpression* AdditiveExpression::getAdditiveExpression() const { return ae; }
string AdditiveExpression::getOperation() const { return op; }
