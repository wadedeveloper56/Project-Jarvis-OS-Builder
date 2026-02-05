#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "DeclarationSpecifiers.h"
#include "Declarator.h"
#include "Declaration.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace
{
	class FunctionDefinition
	{
	public:
		FunctionDefinition(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator, vector<Declaration*>* vectorDeclaration, BaseStatement* baseStatement);
		FunctionDefinition(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator, BaseStatement* baseStatement);
		FunctionDefinition(Declarator* declarator, vector<Declaration*>* vectorDeclaration, BaseStatement* baseStatement);
		FunctionDefinition(Declarator* declarator, BaseStatement* baseStatement);
		FunctionDefinition();
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
