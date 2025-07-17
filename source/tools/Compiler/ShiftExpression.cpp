#include "ShiftExpression.h"

using namespace WadeSpace;
using namespace std;

ShiftExpression::ShiftExpression(AdditiveExpression* ae) :ae(NULL), op(""), se(NULL) {}
ShiftExpression::ShiftExpression(ShiftExpression* se, string op, AdditiveExpression* ae) :ae(ae), op(op), se(se) {}
ShiftExpression::ShiftExpression() :ae(NULL), op(""), se(NULL) {}
ShiftExpression::~ShiftExpression() {}