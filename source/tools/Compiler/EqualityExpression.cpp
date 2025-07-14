#include "EqualityExpression.h"

using namespace WadeSpace;
using namespace std;

EqualityExpression::EqualityExpression(RelationalExpression& re) :re(nullopt), op(""), ee(nullopt) {}
EqualityExpression::EqualityExpression(EqualityExpression& eq, string op, RelationalExpression& re):re(re), op(op), ee(ee) {}
EqualityExpression::EqualityExpression():re(nullopt),op(""),ee(nullopt) {}
EqualityExpression::~EqualityExpression() {}