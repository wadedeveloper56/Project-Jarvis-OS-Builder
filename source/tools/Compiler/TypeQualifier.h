#pragma once

#include <string>
#include <vector>
#include <stdint.h>

namespace WadeSpace {
	typedef enum { NONE4, CONST, VOLATILE } TypeQualifierType;

	class TypeQualifier
	{
	public:
		TypeQualifier(std::string value, TypeQualifierType type);
		TypeQualifier();
		~TypeQualifier();

		std::string getoperator() const;
		TypeQualifierType getType() const;
	private:
		std::string operatorStr;
		TypeQualifierType type;
	};
}
