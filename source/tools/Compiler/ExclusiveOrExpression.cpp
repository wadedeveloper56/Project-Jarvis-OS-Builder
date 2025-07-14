#include "ExclusiveOrExpression.h"

using namespace WadeSpace;
using namespace std;

ExclusiveOrExpression::ExclusiveOrExpression(AndExpression& ae) :ae(nullopt), eoe(nullopt) {}
ExclusiveOrExpression::ExclusiveOrExpression(ExclusiveOrExpression& eoe, AndExpression& ae) :ae(nullopt), eoe(nullopt) {}
ExclusiveOrExpression::ExclusiveOrExpression():ae(nullopt),eoe(nullopt) {}
ExclusiveOrExpression::~ExclusiveOrExpression() {}