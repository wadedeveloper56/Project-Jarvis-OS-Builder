#pragma once

#include "Token.h"
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class TypeQualifier
	{
	public:
		TypeQualifier(TokenPtr type);
		TypeQualifier();
		~TypeQualifier();
		TokenPtr getType() const;
		TypeQualifier(const TypeQualifier& other);
		TypeQualifier(TypeQualifier&& other) noexcept;
		TypeQualifier& operator=(const TypeQualifier& other);
		TypeQualifier& operator=(TypeQualifier&& other) noexcept;

	private:
		TokenPtr type;
	};
}
