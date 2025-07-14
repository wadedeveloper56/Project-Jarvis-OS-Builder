#include "LogicalAndExpression.h"

using namespace WadeSpace;

LogicalAndExpression::LogicalAndExpression(InclusiveOrExpression& ioe) :ioe(ioe), lae(nullopt) {}
LogicalAndExpression::LogicalAndExpression(LogicalAndExpression& lae, InclusiveOrExpression& ioe) :ioe(ioe), lae(lae) {}
LogicalAndExpression::LogicalAndExpression() :ioe(nullopt), lae(nullopt) {}
LogicalAndExpression::~LogicalAndExpression() {}
