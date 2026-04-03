#pragma once

#include "TokenType.h"
#include "FunctionDefinition.h"
#include "Declaration.h"

using namespace std;

namespace WadeSpace
{
	class ExternalDeclaration
	{
		shared_ptr<FunctionDefinition> functionDefinition;
		shared_ptr<Declaration> declaration;
	public:
		ExternalDeclaration() = default;
		ExternalDeclaration(shared_ptr<FunctionDefinition> functionDefinition);
		ExternalDeclaration(shared_ptr<Declaration> declaration);
		virtual ~ExternalDeclaration() = default;
		ExternalDeclaration(const ExternalDeclaration& other) = default;
		ExternalDeclaration(ExternalDeclaration&& other) noexcept = default;
		ExternalDeclaration& operator=(const ExternalDeclaration& other) = default;
		ExternalDeclaration& operator=(ExternalDeclaration&& other) noexcept = default;
		[[nodiscard]] bool isTypedef() const;
		[[nodiscard]] shared_ptr<FunctionDefinition> getFunctionDefinition() const { return functionDefinition; };
		[[nodiscard]] shared_ptr<Declaration> getDeclaration() const { return declaration; };
		[[nodiscard]] bool hasFunction() const { return functionDefinition != nullptr; };
		[[nodiscard]] bool hasDeclaration() const { return declaration != nullptr; };
		void setFunctionDefinition(shared_ptr<FunctionDefinition> functionDefinition) { this->functionDefinition = functionDefinition; };
		void setDeclaration(shared_ptr<Declaration> declaration) { this->declaration = declaration; };
	};
}
