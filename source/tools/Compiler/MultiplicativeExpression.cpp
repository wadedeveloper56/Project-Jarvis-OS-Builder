#include "MultiplicativeExpression.h"

using namespace WadeSpace;
using namespace std;

MultiplicativeExpression::MultiplicativeExpression(CastExpression* ce) :ce(NULL), op(""), me(NULL) {}
MultiplicativeExpression::MultiplicativeExpression(MultiplicativeExpression* me, string op, CastExpression* ce): me(me), op(op), ce(ce) {}
MultiplicativeExpression::MultiplicativeExpression() :me(NULL), op(""), ce(NULL) {}
MultiplicativeExpression::~MultiplicativeExpression() {}