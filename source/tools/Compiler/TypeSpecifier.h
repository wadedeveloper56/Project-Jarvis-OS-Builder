#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "EnumSpecifier.h"

namespace WadeSpace {
	class TypeSpecifier
	{
	public:
		TypeSpecifier(std::string value, TokenType type);
		TypeSpecifier(std::string value, EnumSpecifier& type);
		TypeSpecifier();
		~TypeSpecifier();
	private:
		std::string operatorStr;
		std::optional < std::reference_wrapper < EnumSpecifier>> enumSpec;
		TokenType type;
	};
}
