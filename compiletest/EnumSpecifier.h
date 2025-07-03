#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include "Expression.h"
#include "Enumerator.h"

namespace WadeSpace {
	class EnumSpecifier {
		EnumSpecifier(std::string value, std::vector<Enumerator>& list);
		EnumSpecifier();
		~EnumSpecifier();

		std::string getNameStr() const;
		std::vector<Enumerator> getList() const;
	private:
		std::string nameStr;
		std::vector<Enumerator> list;
	};
}

