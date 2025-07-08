#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Expression.h"
#include "Enumerator.h"

namespace WadeSpace {
	class EnumSpecifier {
	public:
		EnumSpecifier(std::vector<Enumerator>& list);
		EnumSpecifier(std::string value, std::vector<Enumerator>& list);
		EnumSpecifier(std::string value);
		EnumSpecifier();
		~EnumSpecifier();

		std::string getNameStr() const;
		std::vector<Enumerator>& getList() const;
	private:
		std::string nameStr;
		std::optional <std::reference_wrapper <std::vector<Enumerator>>> list;
	};
}

