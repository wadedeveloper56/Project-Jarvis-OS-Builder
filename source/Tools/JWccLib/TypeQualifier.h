#pragma once

#include "Token.h"
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class TypeQualifier
	{
		CTokenPtr type;
	public:
		TypeQualifier() = default;
		TypeQualifier(CTokenPtr type);
		~TypeQualifier() = default;
		TypeQualifier(const TypeQualifier& other) = default;
		TypeQualifier(TypeQualifier&& other) noexcept = default;
		TypeQualifier& operator=(const TypeQualifier& other) = default;
		TypeQualifier& operator=(TypeQualifier&& other) noexcept = default;
		[[nodiscard]] CTokenPtr getType() const { return type; }
		[[nodiscard]] bool hasType() const { return type != nullptr; }
		void setType(CTokenPtr type) { this->type = type; }
	};
}
