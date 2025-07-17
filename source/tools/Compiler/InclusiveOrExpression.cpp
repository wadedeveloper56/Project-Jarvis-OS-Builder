#include "InclusiveOrExpression.h"

using namespace WadeSpace;
using namespace std;

InclusiveOrExpression::InclusiveOrExpression(ExclusiveOrExpression* eoe) :eoe(NULL), ioe(NULL) {}
InclusiveOrExpression::InclusiveOrExpression(InclusiveOrExpression* ioe, ExclusiveOrExpression* eoe) :eoe(NULL), ioe(NULL) {}
InclusiveOrExpression::InclusiveOrExpression() :eoe(NULL), ioe(NULL) {}
InclusiveOrExpression::~InclusiveOrExpression() {}