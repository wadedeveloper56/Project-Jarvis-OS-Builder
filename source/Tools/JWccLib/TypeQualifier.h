#pragma once

#include "Token.h"
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class TypeQualifier
	{
	public:
		TypeQualifier();
		TypeQualifier(CTokenPtr type);
		~TypeQualifier();

		[[nodiscard]] CTokenPtr getType() const;
		[[nodiscard]] bool hasType() const;

		TypeQualifier(const TypeQualifier& other);
		TypeQualifier(TypeQualifier&& other) noexcept;
		TypeQualifier& operator=(const TypeQualifier& other);
		TypeQualifier& operator=(TypeQualifier&& other) noexcept;

	private:
		CTokenPtr type;
	};
}
