#include "ParameterTypeList.h"

using namespace WadeSpace;

ParameterTypeList::ParameterTypeList(std::vector<ParameterDeclaration> pdl,std::string ellipsis) :pdl(pdl),ellipsis(ellipsis) {}
ParameterTypeList::ParameterTypeList() :pdl(std::nullopt),ellipsis(""){}
ParameterTypeList::~ParameterTypeList() {}
