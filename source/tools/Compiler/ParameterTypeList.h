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
		ParameterTypeList(vector<ParameterDeclaration*>* vectorParameterDeclaration, const string& ellipsis);
		ParameterTypeList();
		virtual ~ParameterTypeList();
		vector<ParameterDeclaration*>* getVectorParameterDeclaration() const;
		optional<string> getEllipsis() const;

	private:
		vector<ParameterDeclaration*>* vectorParameterDeclaration;
		optional<string> ellipsis;
	};
}
