#include "LogicalOrExpression.h"

using namespace WadeSpace;
using namespace std;

LogicalOrExpression::LogicalOrExpression(LogicalAndExpression& lae) :loe(nullopt), lae(lae) {}
LogicalOrExpression::LogicalOrExpression(LogicalOrExpression& loe, LogicalAndExpression& lae) :loe(loe), lae(lae) {}
LogicalOrExpression::LogicalOrExpression():loe(nullopt),lae(nullopt) {}
LogicalOrExpression::~LogicalOrExpression() {}