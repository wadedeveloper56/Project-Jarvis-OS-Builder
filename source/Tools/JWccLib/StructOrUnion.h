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
		StructOrUnion();
		StructOrUnion(TokenType type);
		virtual ~StructOrUnion() = default;

		StructOrUnion(const StructOrUnion& other) = default;
		StructOrUnion(StructOrUnion&& other) noexcept = default;
		StructOrUnion& operator=(const StructOrUnion& other) = default;
		StructOrUnion& operator=(StructOrUnion&& other) noexcept = default;

		[[nodiscard]] TokenType getType() const;
		[[nodiscard]] bool hasType() const;

	private:
		TokenType type;
	};
}
