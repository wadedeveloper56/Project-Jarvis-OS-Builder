#include "pch.h"
#include "ParameterTypeList.h"

using namespace WadeSpace;

ParameterTypeList::ParameterTypeList(vector<ParameterDeclaration*>* vectorParameterDeclaration, bool ellipsis) : vectorParameterDeclaration(vectorParameterDeclaration), ellipsis(ellipsis)
{
}

ParameterTypeList::ParameterTypeList() : vectorParameterDeclaration(nullptr), ellipsis(false)
{
}

ParameterTypeList::~ParameterTypeList()
{
	if (vectorParameterDeclaration != nullptr)
	{
		for (auto paramDecl : *vectorParameterDeclaration)
		{
			delete paramDecl;
		}
		delete vectorParameterDeclaration;
	}
}

ParameterTypeList::ParameterTypeList(const ParameterTypeList& other)
{
	vectorParameterDeclaration = other.vectorParameterDeclaration ? new vector<ParameterDeclaration*>(*other.vectorParameterDeclaration) : nullptr;
	ellipsis = other.ellipsis;
}

ParameterTypeList::ParameterTypeList(ParameterTypeList&& other) noexcept
{
	vectorParameterDeclaration = other.vectorParameterDeclaration ? new vector<ParameterDeclaration*>(*other.vectorParameterDeclaration) : nullptr;
	ellipsis = other.ellipsis;
}

ParameterTypeList& ParameterTypeList::operator=(const ParameterTypeList& other)
{
	if (this == &other)
		return *this;
	vectorParameterDeclaration = other.vectorParameterDeclaration ? new vector<ParameterDeclaration*>(*other.vectorParameterDeclaration) : nullptr;
	ellipsis = other.ellipsis;
	return *this;
}

ParameterTypeList& ParameterTypeList::operator=(ParameterTypeList&& other) noexcept
{
	if (this == &other)
		return *this;
	vectorParameterDeclaration = other.vectorParameterDeclaration ? new vector<ParameterDeclaration*>(*other.vectorParameterDeclaration) : nullptr;
	ellipsis = other.ellipsis;
	return *this;
}

vector<ParameterDeclaration*>* ParameterTypeList::getVectorParameterDeclaration() const
{
	return vectorParameterDeclaration;
}

bool ParameterTypeList::getEllipsis() const
{
	return ellipsis;
}
