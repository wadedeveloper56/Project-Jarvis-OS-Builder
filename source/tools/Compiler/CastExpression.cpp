#include "CastExpression.h"

using namespace WadeSpace;
using namespace std;

CastExpression::CastExpression(UnaryExpression* ue) :ue(ue), type(NULL), ce(NULL) {}
CastExpression::CastExpression(TypeName* type, CastExpression* ce) :ue(NULL), type(type), ce(ce) {}
CastExpression::CastExpression() :ue(NULL), type(NULL), ce(NULL) {}
CastExpression::~CastExpression() {
	if (ue) delete ue;
	if (ce) delete ce;
	if (type) delete type;
}