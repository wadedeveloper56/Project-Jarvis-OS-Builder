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

		ParameterTypeList(const ParameterTypeList& other)
			: vectorParameterDeclaration(new vector<ParameterDeclaration*>(*other.vectorParameterDeclaration)),
			  ellipsis(other.ellipsis)
		{
		}

		ParameterTypeList(ParameterTypeList&& other) noexcept
			: vectorParameterDeclaration(new vector<ParameterDeclaration*>(*other.vectorParameterDeclaration)),
			  ellipsis(other.ellipsis)
		{
		}

		ParameterTypeList& operator=(const ParameterTypeList& other)
		{
			if (this == &other)
				return *this;
			delete vectorParameterDeclaration;
			vectorParameterDeclaration = new vector<ParameterDeclaration*>(*other.vectorParameterDeclaration);
			ellipsis = other.ellipsis;
			return *this;
		}

		ParameterTypeList& operator=(ParameterTypeList&& other) noexcept
		{
			if (this == &other)
				return *this;
			delete vectorParameterDeclaration;
			vectorParameterDeclaration = new vector<ParameterDeclaration*>(*other.vectorParameterDeclaration);
			ellipsis = other.ellipsis;
			return *this;
		}

		vector<ParameterDeclaration*>* getVectorParameterDeclaration() const;
		bool getEllipsis() const;
	private:
		vector<ParameterDeclaration*>* vectorParameterDeclaration;
		bool ellipsis;
	};
}
