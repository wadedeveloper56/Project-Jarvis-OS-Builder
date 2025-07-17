#include "AndExpression.h"

using namespace WadeSpace;
using namespace std;

AndExpression::AndExpression(EqualityExpression* ee) :ae(NULL), ee(ee) {}
AndExpression::AndExpression(AndExpression* ae, EqualityExpression* ee) :ae(ae), ee(ee) {}
AndExpression::AndExpression() :ae(NULL), ee(NULL) {}
AndExpression::~AndExpression() {}