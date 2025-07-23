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
		TypeQualifier(const string&  value, TokenType type);
		TypeQualifier();
		virtual ~TypeQualifier();

	private:
		string operatorStr;
		TokenType type;
	};
}
