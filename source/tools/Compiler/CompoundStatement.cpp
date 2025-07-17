#include "CompoundStatement.h"

using namespace WadeSpace;
using namespace std;

CompoundStatement::CompoundStatement(vector<BaseStatement*>* statementList) :BaseStatement(statementList) {}
CompoundStatement::CompoundStatement(vector<Declaration*>* declarationList) :BaseStatement(declarationList) {}
CompoundStatement::CompoundStatement(vector<BaseStatement*>* statementList, vector<Declaration*>* declarationList) :BaseStatement(statementList, declarationList) {}
CompoundStatement::CompoundStatement() :BaseStatement() {}
CompoundStatement::~CompoundStatement() {}
