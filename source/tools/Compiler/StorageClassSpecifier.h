#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class StorageClassSpecifier
	{
	public:
		StorageClassSpecifier(const int& value, TokenType type);
		StorageClassSpecifier();
		virtual ~StorageClassSpecifier();
		optional<int> getOperatorStr() const;
		TokenType getType() const;

	private:
		optional<int> operatorStr;
		TokenType type;
	};
}
