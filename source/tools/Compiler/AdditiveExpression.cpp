#include "AdditiveExpression.h"

using namespace WadeSpace;
using namespace std;

AdditiveExpression::AdditiveExpression(MultiplicativeExpression* me) :ae(NULL), op(""), me(NULL) {}
AdditiveExpression::AdditiveExpression(AdditiveExpression* ae, string op, MultiplicativeExpression* me) :ae(ae), op(op), me(me) {}
AdditiveExpression::AdditiveExpression() :ae(NULL), op(""), me(NULL) {}
AdditiveExpression::~AdditiveExpression() {}
