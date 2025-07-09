#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Constant.h"
#include "TokenType.h"
#include "AssignmentOperator.h"

namespace WadeSpace {
	class Expression
	{
	public:
		Expression();
		Expression(Constant& constant);
		Expression(std::string& identifier);
		Expression(std::string& identifier, Expression& exp);
		Expression(Expression& left, TokenType op1, Expression& right);
		Expression(Expression& left, AssignmentOperator& ao, Expression& right);
		Expression(Expression& exp1, TokenType op1, Expression& exp2,TokenType op2, Expression& exp3);
		~Expression();
	protected:
		std::optional < std::reference_wrapper < Constant>> constant;
		std::string identifier;
		std::optional < std::reference_wrapper < Expression>> exp1;
		TokenType op1,op2;
		std::optional < std::reference_wrapper < Expression>> exp2;
		std::optional < std::reference_wrapper < Expression>> exp3;
		std::optional < std::reference_wrapper < AssignmentOperator>> ao;
	};
}

