#include "AndExpression.h"

using namespace WadeSpace;
using namespace std;

AndExpression::AndExpression(EqualityExpression& ee) :ae(nullopt), ee(ee) {}
AndExpression::AndExpression(AndExpression& ae, EqualityExpression& ee) :ae(ae), ee(ee) {}
AndExpression::AndExpression() :ae(nullopt), ee(nullopt) {}
AndExpression::~AndExpression() {}