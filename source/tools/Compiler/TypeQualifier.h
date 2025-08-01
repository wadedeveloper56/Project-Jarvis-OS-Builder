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
		TypeQualifier(const string& value, TokenType type);
		TypeQualifier();
		virtual ~TypeQualifier();
		optional<string> getOperatorStr() const;
		TokenType getType() const;

	private:
		optional<string> operatorStr;
		TokenType type;
	};
}
