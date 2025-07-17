#include "ConstantExpression.h"

using namespace WadeSpace;

ConstantExpression::ConstantExpression(ConditionalExpression* ce):ce(ce) {}
ConstantExpression::ConstantExpression():ce(NULL) {}
ConstantExpression::~ConstantExpression() {}