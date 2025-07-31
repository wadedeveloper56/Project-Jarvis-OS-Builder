#include "ParameterTypeList.h"

using namespace WadeSpace;

ParameterTypeList::ParameterTypeList(vector<ParameterDeclaration*>* vectorParameterDeclaration, const string& ellipsis) : vectorParameterDeclaration(vectorParameterDeclaration), ellipsis(ellipsis)
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

optional<string> ParameterTypeList::getEllipsis() const
{
	return ellipsis;
}
