#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"
#include "DeclarationSpecifiers.h"
#include "Declarator.h"
#include "Declaration.h"

using namespace std;

namespace WadeSpace
{
	class BaseStatement;

	class FunctionDefinition
	{
	public:
		FunctionDefinition(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator, vector<Declaration*>* vectorDeclaration, BaseStatement* baseStatement);
		FunctionDefinition(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator, BaseStatement* baseStatement);
		FunctionDefinition(Declarator* declarator, vector<Declaration*>* vectorDeclaration,BaseStatement* baseStatement);
		FunctionDefinition(Declarator* declarator, BaseStatement* baseStatement);
		FunctionDefinition();
		FunctionDefinition(const FunctionDefinition& other);
		FunctionDefinition(FunctionDefinition&& other) noexcept;
		FunctionDefinition& operator=(const FunctionDefinition& other);
		FunctionDefinition& operator=(FunctionDefinition&& other) noexcept;
		virtual ~FunctionDefinition();
		DeclarationSpecifiers* getDeclarationSpecifiers() const;
		Declarator* getDeclarator() const;
		vector<Declaration*>* getVectorDeclaration() const;
		BaseStatement* getBaseStatement() const;

	private:
		DeclarationSpecifiers* declarationSpecifiers;
		Declarator* declarator;
		vector<Declaration*>* vectorDeclaration;
		BaseStatement* baseStatement;
	};
}
