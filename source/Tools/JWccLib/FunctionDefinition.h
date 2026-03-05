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
		virtual ~FunctionDefinition();

		FunctionDefinition(const FunctionDefinition& other);
		FunctionDefinition(FunctionDefinition&& other) noexcept;
		FunctionDefinition& operator=(const FunctionDefinition& other);
		FunctionDefinition& operator=(FunctionDefinition&& other) noexcept;

		[[nodiscard]] DeclarationSpecifiers* getDeclarationSpecifiers() const;
		[[nodiscard]] Declarator* getDeclarator() const;
		[[nodiscard]] vector<Declaration*>* getVectorDeclaration() const;
		[[nodiscard]] BaseStatement* getBaseStatement() const;

		[[nodiscard]] bool hasDeclarationSpecifiers() const;
		[[nodiscard]] bool hasDeclarator() const;
		[[nodiscard]] bool hasVectorDeclaration() const;
		[[nodiscard]] bool hasBaseStatement() const;

	private:
		DeclarationSpecifiers* declarationSpecifiers;
		Declarator* declarator;
		vector<Declaration*>* vectorDeclaration;
		BaseStatement* baseStatement;
	};
}
