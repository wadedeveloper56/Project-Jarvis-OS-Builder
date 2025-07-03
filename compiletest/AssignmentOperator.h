#pragma once

#include <string>
#include <vector>
#include <stdint.h>

namespace WadeSpace {
	typedef enum { NONE, EQUAL_OP, MUL_ASSIGN, DIV_ASSIGN, MOD_ASSIGN, ADD_ASSIGN, SUB_ASSIGN, LEFT_ASSIGN, RIGHT_ASSIGN, AND_ASSIGN, XOR_ASSIGN, OR_ASSIGN	} AssignmentOperatorType;

	class AssignmentOperator
	{
	public:
		AssignmentOperator(std::string value, AssignmentOperatorType type);
		AssignmentOperator();
		~AssignmentOperator();

		std::string getoperator() const;
		AssignmentOperatorType getType() const;
	private:
		std::string operatorStr;
		AssignmentOperatorType type;
	};
}
