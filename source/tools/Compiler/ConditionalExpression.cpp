#include "ConditionalExpression.h"

using namespace WadeSpace;
using namespace std;

ConditionalExpression::ConditionalExpression(LogicalOrExpression* loe) :loe(loe), exp(NULL), ce(NULL) {}
ConditionalExpression::ConditionalExpression(LogicalOrExpression* loe, Expression* exp, ConditionalExpression* ce) :loe(loe), exp(exp), ce(ce) {}
ConditionalExpression::ConditionalExpression() :loe(NULL), exp(NULL), ce(NULL) {}
ConditionalExpression::~ConditionalExpression() {}