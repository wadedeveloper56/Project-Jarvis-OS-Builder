#include "ExclusiveOrExpression.h"

using namespace WadeSpace;
using namespace std;

ExclusiveOrExpression::ExclusiveOrExpression(AndExpression* ae) :ae(NULL), eoe(NULL) {}
ExclusiveOrExpression::ExclusiveOrExpression(ExclusiveOrExpression* eoe, AndExpression* ae) :ae(NULL), eoe(NULL) {}
ExclusiveOrExpression::ExclusiveOrExpression() :ae(NULL), eoe(NULL) {}
ExclusiveOrExpression::~ExclusiveOrExpression() {}