#include "Expression.h"

using namespace WadeSpace;

Expression::Expression():constant(std::nullopt), identifier(""), exp1(std::nullopt), op1(NONE), exp2(std::nullopt), op2(NONE),exp3(std::nullopt),ao(std::nullopt) {}
Expression::Expression(Constant& value):constant(value), identifier(""), exp1(std::nullopt), op1(NONE), exp2(std::nullopt), op2(NONE), exp3(std::nullopt), ao(std::nullopt) {}
Expression::Expression(std::string& identifier):constant(std::nullopt), identifier(identifier), exp1(std::nullopt), op1(NONE), exp2(std::nullopt), op2(NONE), exp3(std::nullopt), ao(std::nullopt) {}
Expression::Expression(std::string& identifier, Expression& expValue):constant(std::nullopt), identifier(identifier), exp1(expValue), op1(NONE), exp2(std::nullopt), op2(NONE), exp3(std::nullopt), ao(std::nullopt) {}
Expression::Expression(Expression& left, TokenType op, Expression& right):constant(std::nullopt), identifier(""), exp1(left), op1(op), exp2(right), op2(NONE),exp3(std::nullopt), ao(std::nullopt) {}
Expression::Expression(Expression& left, AssignmentOperator& ao, Expression& right) :constant(std::nullopt), identifier(""), exp1(left), op1(op1), exp2(right), op2(op2), exp3(std::nullopt), ao(ao) {}
Expression::Expression(Expression& exp1, TokenType op1, Expression& exp2, TokenType op2, Expression& exp3):constant(std::nullopt), identifier(""), exp1(exp1), op1(op1), exp2(exp2), op2(op2), exp3(std::nullopt), ao(std::nullopt) {}
Expression::~Expression() {}
