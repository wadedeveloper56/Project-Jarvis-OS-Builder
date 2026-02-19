#pragma once

#include <string>
#include <vector>
#include <optional>
#include "ParameterDeclaration.h"

using namespace std;

namespace WadeSpace
{
	class ParameterTypeList
	{
	public:
		ParameterTypeList(vector<ParameterDeclaration*>* vectorParameterDeclaration, bool ellipsis);
		ParameterTypeList();
		virtual ~ParameterTypeList();
		vector<ParameterDeclaration*>* getVectorParameterDeclaration() const;
		bool getEllipsis() const;
	private:
		vector<ParameterDeclaration*>* vectorParameterDeclaration;
		bool ellipsis;
	};
}
