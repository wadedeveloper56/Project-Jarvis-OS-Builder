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
