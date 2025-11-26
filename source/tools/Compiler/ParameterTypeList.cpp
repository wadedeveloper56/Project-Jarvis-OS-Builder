#include "ParameterTypeList.h"

using namespace WadeSpace;

ParameterTypeList::ParameterTypeList(vector<ParameterDeclaration*>* vectorParameterDeclaration, const int& ellipsis) : vectorParameterDeclaration(vectorParameterDeclaration), ellipsis(ellipsis)
{
}

ParameterTypeList::ParameterTypeList() : vectorParameterDeclaration(nullptr), ellipsis(nullopt)
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

optional<int> ParameterTypeList::getEllipsis() const
{
	return ellipsis;
}
