#include "pch.h"
#include "CompoundStatement.h"

using namespace WadeSpace;
using namespace std;

CompoundStatement::CompoundStatement(vector<BaseStatement*>* const list) : BaseStatement(list)
{
} 

CompoundStatement::CompoundStatement(vector<Declaration*>* list) : BaseStatement(list)
{
}

CompoundStatement::CompoundStatement(vector<BaseStatement*>* sList, vector<Declaration*>* dList) : BaseStatement(sList, dList)
{
}

CompoundStatement::CompoundStatement(const CompoundStatement& other): BaseStatement(other)
{
}

CompoundStatement::CompoundStatement(CompoundStatement&& other) noexcept: BaseStatement(std::move(other))
{
}

CompoundStatement& CompoundStatement::operator=(const CompoundStatement& other)
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(other);
	return *this;
}

CompoundStatement& CompoundStatement::operator=(CompoundStatement&& other) noexcept
{
	if (this == &other)
		return *this;
	BaseStatement::operator =(std::move(other));
	return *this;
}


