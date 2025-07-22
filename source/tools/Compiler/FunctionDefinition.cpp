#include "FunctionDefinition.h"

using namespace WadeSpace;
using namespace std;

FunctionDefinition::FunctionDefinition(DeclarationSpecifiers* ds, Declarator* dec, vector<Declaration*>* dl,
                                       BaseStatement* bs) : ds(ds), dec(dec), dl(dl), bs(bs)
{
}

FunctionDefinition::FunctionDefinition(DeclarationSpecifiers* ds, Declarator* dec,
                                       BaseStatement* bs) : ds(ds), dec(dec), dl(nullptr), bs(bs)
{
}

FunctionDefinition::FunctionDefinition(Declarator* dec, vector<Declaration*>* dl, BaseStatement* bs) : ds(nullptr),
	dec(dec), dl(dl), bs(bs)
{
}

FunctionDefinition::FunctionDefinition(Declarator* dec, BaseStatement* bs) : ds(nullptr), dec(dec), dl(nullptr), bs(bs)
{
}

FunctionDefinition::FunctionDefinition() : ds(nullptr), dec(nullptr), dl(nullptr), bs(nullptr)
{
}

FunctionDefinition::~FunctionDefinition()
{
}

bool FunctionDefinition::hasDeclarationSpecifiers() const { return ds != NULL; }
bool FunctionDefinition::hasDeclarator() const { return dec != NULL; }
bool FunctionDefinition::hasVectorDeclaration() const { return dl != NULL; }
bool FunctionDefinition::hasBaseStatement() const { return bs != NULL; }
DeclarationSpecifiers* FunctionDefinition::getDeclarationSpecifiers() const { return ds; }
Declarator* FunctionDefinition::getDeclarator() const { return dec; }
vector<Declaration*>* FunctionDefinition::getVectorDeclaration() const { return dl; }
BaseStatement* FunctionDefinition::getBaseStatement() const { return bs; }
