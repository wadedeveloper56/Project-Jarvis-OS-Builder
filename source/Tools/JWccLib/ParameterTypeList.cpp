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
	delete vectorParameterDeclaration;
}

vector<ParameterDeclaration*>* ParameterTypeList::getVectorParameterDeclaration() const
{
	return vectorParameterDeclaration;
}

bool ParameterTypeList::getEllipsis() const
{
	return ellipsis;
}
