#include "UnaryExpression.h"

using namespace WadeSpace;
using namespace std;

UnaryExpression::UnaryExpression(PostfixExpression* pe) :pe(pe), ce(NULL), ue(NULL), tn(NULL), op("") {}
UnaryExpression::UnaryExpression(string op, UnaryExpression* ue) :pe(NULL), ce(NULL), ue(ue), tn(NULL), op(op) {}
UnaryExpression::UnaryExpression(string op, CastExpression* ce) :pe(NULL), ce(ce), ue(NULL), tn(NULL), op(op) {}
UnaryExpression::UnaryExpression(string op, TypeName* tn) :pe(NULL), ce(NULL), ue(NULL), tn(tn), op(op) {}
UnaryExpression::UnaryExpression() :pe(NULL), ce(NULL), ue(NULL), tn(NULL), op("") {}
UnaryExpression::~UnaryExpression() {}
