#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TypeQualifier.h"

namespace WadeSpace {
	class Pointer
	{
	public:
		Pointer(std::string value, std::vector<TypeQualifier>& list);
		Pointer(std::string value, std::vector<TypeQualifier>& list, Pointer& ptr);
		Pointer(std::string value, Pointer& ptr);
		Pointer(std::string value);
		Pointer();
		~Pointer();
		void inc();
	private:
		std::string nameStr;
		std::optional < std::reference_wrapper < std::vector<TypeQualifier>>> list;
		int level;
		std::optional<std::reference_wrapper < Pointer>> ptr;
	};
}
