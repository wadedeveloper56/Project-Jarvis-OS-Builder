#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class TypeQualifier
	{
	public:
		TypeQualifier(const int& value, TokenType type);
		TypeQualifier();
		virtual ~TypeQualifier();
		optional<int> getOperatorStr() const;
		TokenType getType() const;

	private:
		optional<int> operatorStr;
		TokenType type;
	};
}
