#include "LogicalAndExpression.h"

using namespace WadeSpace;

LogicalAndExpression::LogicalAndExpression(InclusiveOrExpression* ioe) :ioe(ioe), lae(NULL) {}
LogicalAndExpression::LogicalAndExpression(LogicalAndExpression* lae, InclusiveOrExpression* ioe) :ioe(ioe), lae(lae) {}
LogicalAndExpression::LogicalAndExpression() :ioe(NULL), lae(NULL) {}
LogicalAndExpression::~LogicalAndExpression() {}
