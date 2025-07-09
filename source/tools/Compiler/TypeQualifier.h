#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

namespace WadeSpace {
	class TypeQualifier
	{
	public:
		TypeQualifier(std::string value, TokenType type);
		TypeQualifier();
		~TypeQualifier();
	private:
		std::string operatorStr;
		TokenType type;
	};
}
