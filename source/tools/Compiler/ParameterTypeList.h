#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "ParameterDeclaration.h"

using namespace std;

namespace WadeSpace
{
	class ParameterTypeList
	{
	public:
		ParameterTypeList(vector<ParameterDeclaration*>* vectorParameterDeclaration, const int& ellipsis);
		ParameterTypeList();
		virtual ~ParameterTypeList();
		vector<ParameterDeclaration*>* getVectorParameterDeclaration() const;
		optional<int> getEllipsis() const;

	private:
		vector<ParameterDeclaration*>* vectorParameterDeclaration;
		optional<int> ellipsis;
	};
}
