#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include "TokenType.h"

namespace WadeSpace {
	class AssignmentOperator
	{
	public:
		AssignmentOperator(std::string value, TokenType type);
		AssignmentOperator();
		~AssignmentOperator();
	private:
		std::string operatorStr;
		TokenType type;
	};
}
