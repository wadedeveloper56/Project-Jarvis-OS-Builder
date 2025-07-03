#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include "EnumSpecifier.h"

namespace WadeSpace {
	typedef enum { NONE3, VOID, CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, SIGNED, UNSIGNED, struct_or_union_specifier, enum_specifier, TYPE_NAME } TypeSpecifierType;

	class TypeSpecifier
	{
	public:
		TypeSpecifier(std::string value, TypeSpecifierType type);
		TypeSpecifier(std::string value, EnumSpecifier* type);
		TypeSpecifier();
		~TypeSpecifier();

		std::string getoperator() const;
		TypeSpecifierType getType() const;
		EnumSpecifier* getEnumSpecifier() const;
	private:
		std::string operatorStr;
		EnumSpecifier* enumSpec;
		TypeSpecifierType type;
	};
}
