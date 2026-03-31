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
		CTokenPtr type;
	public:
		StorageClassSpecifier() = default;
		StorageClassSpecifier(const CTokenPtr type);
		virtual ~StorageClassSpecifier() = default;
		StorageClassSpecifier(const StorageClassSpecifier& other) = default;
		StorageClassSpecifier(StorageClassSpecifier&& other) noexcept = default;
		StorageClassSpecifier& operator=(const StorageClassSpecifier& other) = default;
		StorageClassSpecifier& operator=(StorageClassSpecifier&& other) noexcept = default;
		[[nodiscard]] CTokenPtr getType() const { return type; }
		void setType(const CTokenPtr type) { this->type = type; }
		bool hasType() const { return type != nullptr; }
	};
}
