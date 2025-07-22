#include "ParameterTypeList.h"

using namespace WadeSpace;

ParameterTypeList::ParameterTypeList(vector<ParameterDeclaration*>* pdl, string ellipsis) : pdl(pdl), ellipsis(ellipsis)
{
}

ParameterTypeList::ParameterTypeList() : pdl(nullptr), ellipsis("")
{
}

ParameterTypeList::~ParameterTypeList()
{
}
