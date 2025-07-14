#include "InclusiveOrExpression.h"

using namespace WadeSpace;
using namespace std;

InclusiveOrExpression::InclusiveOrExpression(ExclusiveOrExpression& eoe) :eoe(nullopt), ioe(nullopt) {}
InclusiveOrExpression::InclusiveOrExpression(InclusiveOrExpression& ioe, ExclusiveOrExpression& eoe) :eoe(nullopt), ioe(nullopt) {}
InclusiveOrExpression::InclusiveOrExpression() :eoe(nullopt), ioe(nullopt) {}
InclusiveOrExpression::~InclusiveOrExpression() {}