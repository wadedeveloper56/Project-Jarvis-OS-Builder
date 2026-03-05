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

FunctionDefinition::FunctionDefinition() : declarationSpecifiers(nullptr), declarator(nullptr),
                                           vectorDeclaration(nullptr), baseStatement(nullptr)
{
}

FunctionDefinition::~FunctionDefinition()
{
	delete declarationSpecifiers;
	delete declarator;
	if (vectorDeclaration != NULL)
	{
		for (Declaration* ptr : *vectorDeclaration)
		{
			delete ptr;
		}
	}
	delete vectorDeclaration;
	delete baseStatement;
}

DeclarationSpecifiers* FunctionDefinition::getDeclarationSpecifiers() const
{
	return declarationSpecifiers;
}

Declarator* FunctionDefinition::getDeclarator() const
{
	return declarator;
}

vector<Declaration*>* FunctionDefinition::getVectorDeclaration() const
{
	return vectorDeclaration;
}

BaseStatement* FunctionDefinition::getBaseStatement() const
{
	return baseStatement;
}

FunctionDefinition::FunctionDefinition(const FunctionDefinition& other)
{
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	vectorDeclaration = other.vectorDeclaration ? new vector<Declaration*>(*other.vectorDeclaration) : nullptr;
	baseStatement = other.baseStatement ? new BaseStatement(*other.baseStatement) : nullptr;
}

FunctionDefinition::FunctionDefinition(FunctionDefinition&& other) noexcept
{
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	vectorDeclaration = other.vectorDeclaration ? new vector<Declaration*>(*other.vectorDeclaration) : nullptr;
	baseStatement = other.baseStatement ? new BaseStatement(*other.baseStatement) : nullptr;
}

FunctionDefinition& FunctionDefinition::operator=(const FunctionDefinition& other)
{
	if (this == &other)
		return *this;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	vectorDeclaration = other.vectorDeclaration ? new vector<Declaration*>(*other.vectorDeclaration) : nullptr;
	baseStatement = other.baseStatement ? new BaseStatement(*other.baseStatement) : nullptr;
	return *this;
}

FunctionDefinition& FunctionDefinition::operator=(FunctionDefinition&& other) noexcept
{
	if (this == &other)
		return *this;
	declarationSpecifiers = other.declarationSpecifiers ? new DeclarationSpecifiers(*other.declarationSpecifiers) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	vectorDeclaration = other.vectorDeclaration ? new vector<Declaration*>(*other.vectorDeclaration) : nullptr;
	baseStatement = other.baseStatement ? new BaseStatement(*other.baseStatement) : nullptr;
	return *this;
}

bool FunctionDefinition::hasDeclarationSpecifiers() const
{
	return declarationSpecifiers != nullptr;
}

bool FunctionDefinition::hasDeclarator() const
{
	return declarator != nullptr;
}

bool FunctionDefinition::hasVectorDeclaration() const
{
	return vectorDeclaration != nullptr;
}

bool FunctionDefinition::hasBaseStatement() const
{
	return baseStatement != nullptr;
}
