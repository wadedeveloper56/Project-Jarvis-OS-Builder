#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "ParameterDeclaration.h"

using namespace std;

namespace WadeSpace {
	class ParameterTypeList
	{
	public:
		ParameterTypeList(vector<ParameterDeclaration*>* pdl, string ellipsis);
		ParameterTypeList();
		~ParameterTypeList();
	private:
		vector<ParameterDeclaration*>* pdl;
		string ellipsis;
	};
}
