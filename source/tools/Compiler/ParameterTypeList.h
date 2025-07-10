#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "ParameterDeclaration.h"

namespace WadeSpace {
	class ParameterTypeList
	{
	public:
		ParameterTypeList(std::vector<ParameterDeclaration> pdl, std::string ellipsis);
		ParameterTypeList();
		~ParameterTypeList();
	private:
		std::optional < std::reference_wrapper < std::vector<ParameterDeclaration>>> pdl;
		std::string ellipsis;
	};
}
