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
		DeclarationSpecifiers* declarationSpecifiers;
		Declarator* declarator;
		vector<Declaration*>* vectorDeclaration;
		BaseStatement* baseStatement;
	public:
		FunctionDefinition(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator, vector<Declaration*>* vectorDeclaration, BaseStatement* baseStatement);
		FunctionDefinition(DeclarationSpecifiers* declarationSpecifiers, Declarator* declarator, BaseStatement* baseStatement);
		FunctionDefinition(Declarator* declarator, vector<Declaration*>* vectorDeclaration,BaseStatement* baseStatement);
		FunctionDefinition(Declarator* declarator, BaseStatement* baseStatement);
		FunctionDefinition() = default;
		virtual ~FunctionDefinition() = default;
		FunctionDefinition(const FunctionDefinition& other) = default;
		FunctionDefinition(FunctionDefinition&& other) noexcept = default;
		FunctionDefinition& operator=(const FunctionDefinition& other) = default;
		FunctionDefinition& operator=(FunctionDefinition&& other) noexcept = default;
		[[nodiscard]] DeclarationSpecifiers* getDeclarationSpecifiers() const { return declarationSpecifiers; }
		[[nodiscard]] Declarator* getDeclarator() const { return declarator; }
		[[nodiscard]] vector<Declaration*>* getVectorDeclaration() const { return vectorDeclaration; }
		[[nodiscard]] BaseStatement* getBaseStatement() const { return baseStatement; }
		[[nodiscard]] bool hasDeclarationSpecifiers() const { return declarationSpecifiers != nullptr; }
		[[nodiscard]] bool hasDeclarator() const { return declarator != nullptr; }
		[[nodiscard]] bool hasVectorDeclaration() const { return vectorDeclaration != nullptr; }
		[[nodiscard]] bool hasBaseStatement() const { return baseStatement != nullptr; }
		void setDeclarationSpecifiers(DeclarationSpecifiers* declarationSpecifiers) { this->declarationSpecifiers = declarationSpecifiers; }
		void setDeclarator(Declarator* declarator) { this->declarator = declarator; }
		void setVectorDeclaration(vector<Declaration*>* vectorDeclaration) { this->vectorDeclaration = vectorDeclaration; }
		void setBaseStatement(BaseStatement* baseStatement) { this->baseStatement = baseStatement; }
		void addDeclaration(Declaration* declaration) { vectorDeclaration->push_back(declaration); }
	};
}
