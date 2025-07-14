#include "UnaryExpression.h"

using namespace WadeSpace;
using namespace std;

UnaryExpression::UnaryExpression(PostfixExpression& pe) :pe(pe), ce(nullopt), ue(nullopt), tn(nullopt), op("") {}
UnaryExpression::UnaryExpression(string op, UnaryExpression& ue) :pe(nullopt), ce(nullopt), ue(ue), tn(nullopt), op(op) {}
UnaryExpression::UnaryExpression(string op, CastExpression& ce) :pe(nullopt), ce(ce), ue(nullopt), tn(nullopt), op(op) {}
UnaryExpression::UnaryExpression(string op, TypeName& tn) :pe(nullopt), ce(nullopt), ue(nullopt), tn(tn), op(op) {}
UnaryExpression::UnaryExpression() :pe(nullopt), ce(nullopt), ue(nullopt), tn(nullopt), op("") {}
UnaryExpression::~UnaryExpression() {}
