#include "Declaration.h"

using namespace WadeSpace;
using namespace std;

Declaration::Declaration(DeclarationSpecifiers* declarationSpecifiers) : declarationSpecifiers(declarationSpecifiers), vectorInitDeclarator(nullptr)
{
}

Declaration::Declaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator) : declarationSpecifiers(declarationSpecifiers), vectorInitDeclarator(vectorInitDeclarator)
{
}

Declaration::Declaration() : declarationSpecifiers(nullptr), vectorInitDeclarator(nullptr)
{
}

Declaration::~Declaration()
{
	delete declarationSpecifiers;
	for (InitDeclarator* ptr : *vectorInitDeclarator)
	{
		delete ptr;
	}
	delete vectorInitDeclarator;
}

bool Declaration::hasDeclarationSpecifiers() const { return declarationSpecifiers; }
bool Declaration::hasVectorInitDeclarator() const { return vectorInitDeclarator; }
DeclarationSpecifiers* Declaration::getDeclarationSpecifiers() const { return declarationSpecifiers; }
vector<InitDeclarator*>* Declaration::getVectorInitDeclarator() const { return vectorInitDeclarator; }
