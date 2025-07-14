#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include "TokenType.h"

namespace WadeSpace {
	class AssignmentOperator
	{
	public:
		AssignmentOperator(TokenType type);
		AssignmentOperator();
		~AssignmentOperator();
	private:
		TokenType type;
	};
}
