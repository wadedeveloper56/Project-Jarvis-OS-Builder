#include "ShiftExpression.h"

using namespace WadeSpace;
using namespace std;

ShiftExpression::ShiftExpression(AdditiveExpression& ae) :ae(nullopt), op(""), se(nullopt) {}
ShiftExpression::ShiftExpression(ShiftExpression& se, string op, AdditiveExpression& ae) :ae(ae), op(op), se(se) {}
ShiftExpression::ShiftExpression() :ae(nullopt), op(""), se(nullopt) {}
ShiftExpression::~ShiftExpression() {}