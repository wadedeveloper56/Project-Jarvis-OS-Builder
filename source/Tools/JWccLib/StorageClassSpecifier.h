#pragma once

#include <string>
#include <vector>
#include <optional>

#include "Token.h"
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class StorageClassSpecifier
	{
	public:
		explicit StorageClassSpecifier(const TokenPtr type);
		StorageClassSpecifier();
		virtual ~StorageClassSpecifier() = default;
		[[nodiscard]] TokenPtr getType() const;
		[[nodiscard]] bool isType() const;

	private:
		TokenPtr type;
	};
}
