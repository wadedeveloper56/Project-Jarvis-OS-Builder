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
		StorageClassSpecifier(const string& value, TokenType type);
		StorageClassSpecifier();
		virtual ~StorageClassSpecifier();
		optional<string> getOperatorStr() const;
		TokenType getType() const;

	private:
		optional<string> operatorStr;
		TokenType type;
	};
}
