#include "PrimaryExpression.h"

using namespace WadeSpace;
using namespace std;

PrimaryExpression::PrimaryExpression(string identifier) :identifier(identifier), c(NULL), exp(NULL) {}
PrimaryExpression::PrimaryExpression(Constant* c) :identifier(identifier), c(c), exp(NULL) {}
PrimaryExpression::PrimaryExpression(Expression* exp) :identifier(identifier), c(c), exp(exp) {}
PrimaryExpression::PrimaryExpression() :identifier(identifier),c(NULL),exp(NULL) {}
PrimaryExpression::~PrimaryExpression() {}