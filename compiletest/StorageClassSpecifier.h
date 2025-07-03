#pragma once

#include <string>
#include <vector>
#include <stdint.h>

namespace WadeSpace {
	typedef enum { NONE2, TYPEDEF, EXTERN, STATIC, AUTO, REGISTER } StorageClassSpecifierType;

	class StorageClassSpecifier
	{
	public:
		StorageClassSpecifier(std::string value, StorageClassSpecifierType type);
		StorageClassSpecifier();
		~StorageClassSpecifier();

		std::string getoperator() const;
		StorageClassSpecifierType getType() const;
	private:
		std::string operatorStr;
		StorageClassSpecifierType type;
	};
}
