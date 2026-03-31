#include "pch.h"
#include "Declaration.h"
#include "ExternalDeclaration.h"

using namespace WadeSpace;
using namespace std;

Declaration::Declaration(DeclarationSpecifiers* declarationSpecifiers) : declarationSpecifiers(declarationSpecifiers), vectorInitDeclarator(nullptr)
{
}

Declaration::Declaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator) : 
declarationSpecifiers(declarationSpecifiers), vectorInitDeclarator(vectorInitDeclarator)
{
}
