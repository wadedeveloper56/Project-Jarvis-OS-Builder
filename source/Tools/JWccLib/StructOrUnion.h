#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"

namespace WadeSpace
{
	class StructOrUnion
	{
	public:
		StructOrUnion(TokenType type);
		StructOrUnion();
		virtual ~StructOrUnion();
		TokenType getType() const;
		StructOrUnion(const StructOrUnion& other) = default;
		StructOrUnion(StructOrUnion&& other) noexcept = default;
		StructOrUnion& operator=(const StructOrUnion& other) = default;
		StructOrUnion& operator=(StructOrUnion&& other) noexcept = default;

	private:
		TokenType type;
	};
}
