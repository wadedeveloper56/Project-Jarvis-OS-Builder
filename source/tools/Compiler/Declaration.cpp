#include "Declaration.h"

using namespace WadeSpace;
using namespace std;

Declaration::Declaration(DeclarationSpecifiers* ds) : ds(ds), idl(nullptr)
{
}

Declaration::Declaration(DeclarationSpecifiers* ds, vector<InitDeclarator*>* idl) : ds(ds), idl(idl)
{
}

Declaration::Declaration() : ds(nullptr), idl(nullptr)
{
}

Declaration::~Declaration()
{
}

bool Declaration::hasDeclarationSpecifiers() const { return ds; }
bool Declaration::hasVectorInitDeclarator() const { return idl; }
DeclarationSpecifiers* Declaration::getDeclarationSpecifiers() const { return ds; }
vector<InitDeclarator*>* Declaration::getVectorInitDeclarator() const { return idl; }
