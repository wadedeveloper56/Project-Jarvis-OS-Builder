#include "CastExpression.h"

using namespace WadeSpace;
using namespace std;

CastExpression::CastExpression(UnaryExpression& ue) :ue(ue), type(nullopt), ce(nullopt) {}
CastExpression::CastExpression(TypeName& type, CastExpression& ce) :ue(nullopt), type(type), ce(ce) {}
CastExpression::CastExpression() :ue(nullopt), type(nullopt), ce(nullopt) {}
CastExpression::~CastExpression() {}