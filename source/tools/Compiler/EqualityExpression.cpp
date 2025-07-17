#include "EqualityExpression.h"

using namespace WadeSpace;
using namespace std;

EqualityExpression::EqualityExpression(RelationalExpression* re) :re(NULL), op(""), ee(NULL) {}
EqualityExpression::EqualityExpression(EqualityExpression* eq, string op, RelationalExpression* re) :re(re), op(op), ee(ee) {}
EqualityExpression::EqualityExpression() :re(NULL), op(""), ee(NULL) {}
EqualityExpression::~EqualityExpression() {}