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
		vector<ParameterDeclaration*>* vectorParameterDeclaration;
		bool ellipsis;
	public:
		ParameterTypeList() = default;
		ParameterTypeList(vector<ParameterDeclaration*>* vectorParameterDeclaration, bool ellipsis);
		virtual ~ParameterTypeList() = default;
		ParameterTypeList(const ParameterTypeList& other) = default;
		ParameterTypeList(ParameterTypeList&& other) noexcept = default;
		ParameterTypeList& operator=(const ParameterTypeList& other) = default;
		ParameterTypeList& operator=(ParameterTypeList&& other) noexcept = default;
		void setVectorParameterDeclaration(vector<ParameterDeclaration*>* vectorParameterDeclaration) { this->vectorParameterDeclaration = vectorParameterDeclaration; }
		void setEllipsis(bool ellipsis) { this->ellipsis = ellipsis; }
		[[nodiscard]] vector<ParameterDeclaration*>* getVectorParameterDeclaration() const { return vectorParameterDeclaration; }
		[[nodiscard]] bool hasVectorParameterDeclaration() const { return vectorParameterDeclaration != nullptr; }
		[[nodiscard]] bool hasEllipsis() const { return ellipsis; }
		void addParameterDeclaration(ParameterDeclaration* parameterDeclaration) { if (vectorParameterDeclaration == nullptr) vectorParameterDeclaration = new vector<ParameterDeclaration*>(); vectorParameterDeclaration->push_back(parameterDeclaration); }
	};
}
