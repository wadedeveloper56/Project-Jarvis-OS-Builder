#include "ConditionalExpression.h"

using namespace WadeSpace;
using namespace std;

ConditionalExpression::ConditionalExpression(LogicalOrExpression& loe) :loe(loe), exp(nullopt), ce(nullopt) {}
ConditionalExpression::ConditionalExpression(LogicalOrExpression& loe, Expression& exp, ConditionalExpression& ce) :loe(loe), exp(exp), ce(ce) {}
ConditionalExpression::ConditionalExpression() :loe(nullopt), exp(nullopt), ce(nullopt) {}
ConditionalExpression::~ConditionalExpression() {}