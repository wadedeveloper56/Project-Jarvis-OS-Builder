#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

namespace WadeSpace {
	class StorageClassSpecifier
	{
	public:
		StorageClassSpecifier(std::string value, TokenType type);
		StorageClassSpecifier();
		~StorageClassSpecifier();
	private:
		std::string operatorStr;
		TokenType type;
	};
}
