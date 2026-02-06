#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class StorageClassSpecifier
	{
	public:
		StorageClassSpecifier(const optional<int>& value, const optional<TokenType> type);
		StorageClassSpecifier();
		virtual ~StorageClassSpecifier() = default;
		[[nodiscard]] optional<int> getOperatorStr() const;
		[[nodiscard]] optional<TokenType> getType() const;
		[[nodiscard]] bool isOperatorStr() const;
		[[nodiscard]] bool isType() const;

	private:
		optional<int> operatorStr;
		optional<TokenType> type;
	};
}
