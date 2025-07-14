#include "MultiplicativeExpression.h"

using namespace WadeSpace;
using namespace std;

MultiplicativeExpression::MultiplicativeExpression(CastExpression& ce) :ce(nullopt), op(""), me(nullopt) {}
MultiplicativeExpression::MultiplicativeExpression(MultiplicativeExpression& me, string op, CastExpression& ce): me(me), op(op), ce(ce) {}
MultiplicativeExpression::MultiplicativeExpression() :me(nullopt), op(""), ce(nullopt) {}
MultiplicativeExpression::~MultiplicativeExpression() {}