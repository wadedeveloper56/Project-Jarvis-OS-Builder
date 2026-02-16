#pragma once

#include <string>
#include <vector>
#include <optional>

#include "Token.h"
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class TypeQualifier
	{
	public:
		TypeQualifier(TokenPtr type);
		TypeQualifier() = default;
		virtual ~TypeQualifier()=default;
		TokenPtr getType() const;

	private:
		TokenPtr type;
	};
}
