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
		StorageClassSpecifier();
		explicit StorageClassSpecifier(const CTokenPtr type);
		virtual ~StorageClassSpecifier() = default;

		StorageClassSpecifier(const StorageClassSpecifier& other);
		StorageClassSpecifier(StorageClassSpecifier&& other) noexcept;
		StorageClassSpecifier& operator=(const StorageClassSpecifier& other);
		StorageClassSpecifier& operator=(StorageClassSpecifier&& other) noexcept;

		[[nodiscard]] CTokenPtr getType() const;
		[[nodiscard]] bool hasType() const;

	private:
		CTokenPtr type;
	};
}
