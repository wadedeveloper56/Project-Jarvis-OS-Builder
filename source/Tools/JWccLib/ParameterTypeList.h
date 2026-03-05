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
		ParameterTypeList();
		ParameterTypeList(vector<ParameterDeclaration*>* vectorParameterDeclaration, bool ellipsis);
		virtual ~ParameterTypeList();

		ParameterTypeList(const ParameterTypeList& other);
		ParameterTypeList(ParameterTypeList&& other) noexcept;
		ParameterTypeList& operator=(const ParameterTypeList& other);
		ParameterTypeList& operator=(ParameterTypeList&& other) noexcept;

		[[nodiscard]] vector<ParameterDeclaration*>* getVectorParameterDeclaration() const;
		[[nodiscard]] bool getEllipsis() const;

		[[nodiscard]] bool hasVectorParameterDeclaration() const;
		

	private:
		vector<ParameterDeclaration*>* vectorParameterDeclaration;
		bool ellipsis;
	};
}
