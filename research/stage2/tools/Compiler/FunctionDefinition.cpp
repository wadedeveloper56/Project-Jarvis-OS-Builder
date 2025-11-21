#include "FunctionDefinition.h"

using namespace WadeSpace;
using namespace std;

FunctionDefinition::FunctionDefinition(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator, vector<Declaration*>* vectorDeclaration, BaseStatement* baseStatement) : declarationSpecifiers(declarationSpecifiers), declarator(declarator), vectorDeclaration(vectorDeclaration), baseStatement(baseStatement)
{
}

FunctionDefinition::FunctionDefinition(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator, BaseStatement* baseStatement) : declarationSpecifiers(declarationSpecifiers), declarator(declarator), vectorDeclaration(nullptr), baseStatement(baseStatement)
{
}

FunctionDefinition::FunctionDefinition(Declarator* declarator, vector<Declaration*>* vectorDeclaration, BaseStatement* baseStatement) : declarationSpecifiers(nullptr),	declarator(declarator), vectorDeclaration(vectorDeclaration), baseStatement(baseStatement)
{
}

FunctionDefinition::FunctionDefinition(Declarator* declarator, BaseStatement* baseStatement) : declarationSpecifiers(nullptr), declarator(declarator), vectorDeclaration(nullptr), baseStatement(baseStatement)
{
}

FunctionDefinition::FunctionDefinition() : declarationSpecifiers(nullptr), declarator(nullptr), vectorDeclaration(nullptr), baseStatement(nullptr)
{
}

FunctionDefinition::~FunctionDefinition()
{
    delete declarationSpecifiers;
    delete declarator;
    for (Declaration* ptr : *vectorDeclaration)
    {
        delete ptr;
    }
    delete vectorDeclaration;
    delete baseStatement;
}

DeclarationSpecifiers* FunctionDefinition::getDeclarationSpecifiers() const { return declarationSpecifiers; }
Declarator* FunctionDefinition::getDeclarator() const { return declarator; }
vector<Declaration*>* FunctionDefinition::getVectorDeclaration() const { return vectorDeclaration; }
BaseStatement* FunctionDefinition::getBaseStatement() const { return baseStatement; }
