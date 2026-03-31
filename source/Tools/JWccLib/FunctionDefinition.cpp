#include "pch.h"
#include "FunctionDefinition.h"
#include  "BaseStatement.h"

using namespace WadeSpace;
using namespace std;

FunctionDefinition::FunctionDefinition(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator,
                                       vector<Declaration*>* vectorDeclaration,
                                       BaseStatement* baseStatement) : declarationSpecifiers(declarationSpecifiers),
                                                                       declarator(declarator),
                                                                       vectorDeclaration(vectorDeclaration),
                                                                       baseStatement(baseStatement)
{
}

FunctionDefinition::FunctionDefinition(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator,
                                       BaseStatement* baseStatement) : declarationSpecifiers(declarationSpecifiers),
                                                                       declarator(declarator),
                                                                       vectorDeclaration(nullptr),
                                                                       baseStatement(baseStatement)
{
}

FunctionDefinition::FunctionDefinition(Declarator* declarator, vector<Declaration*>* vectorDeclaration,
                                       BaseStatement* baseStatement) : declarationSpecifiers(nullptr),
                                                                       declarator(declarator),
                                                                       vectorDeclaration(vectorDeclaration),
                                                                       baseStatement(baseStatement)
{
}

FunctionDefinition::FunctionDefinition(Declarator* declarator, BaseStatement* baseStatement) :
	declarationSpecifiers(nullptr), declarator(declarator), vectorDeclaration(nullptr), baseStatement(baseStatement)
{
}
