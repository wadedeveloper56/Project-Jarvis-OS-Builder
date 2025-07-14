#include "AdditiveExpression.h"

using namespace WadeSpace;
using namespace std;

AdditiveExpression::AdditiveExpression(MultiplicativeExpression& me) :ae(nullopt), op(""), me(nullopt) {}
AdditiveExpression::AdditiveExpression(AdditiveExpression& ae, string op, MultiplicativeExpression& me) :ae(ae), op(op), me(me) {}
AdditiveExpression::AdditiveExpression() :ae(nullopt), op(""), me(nullopt) {}
AdditiveExpression::~AdditiveExpression() {}
