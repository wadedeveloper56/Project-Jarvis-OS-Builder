#pragma once

#include "TokenType.h"
#include "FunctionDefinition.h"
#include "Declaration.h"

using namespace std;

namespace WadeSpace
{
	class ExternalDeclaration
	{
		FunctionDefinition* functionDefinition;
		Declaration* declaration;
	public:
		ExternalDeclaration() = default;
		ExternalDeclaration(FunctionDefinition* functionDefinition);
		ExternalDeclaration(Declaration* declaration);
		virtual ~ExternalDeclaration() = default;
		ExternalDeclaration(const ExternalDeclaration& other) = default;
		ExternalDeclaration(ExternalDeclaration&& other) noexcept = default;
		ExternalDeclaration& operator=(const ExternalDeclaration& other) = default;
		ExternalDeclaration& operator=(ExternalDeclaration&& other) noexcept = default;
		[[nodiscard]] bool isTypedef() const;
		[[nodiscard]] FunctionDefinition* getFunction() const { return functionDefinition; }
		[[nodiscard]] Declaration* getDeclaration() const { return declaration; }
		[[nodiscard]] bool hasFunction() const { return functionDefinition != nullptr; }
		[[nodiscard]] bool hasDeclaration() const { return declaration != nullptr; }
		void setFunctionDefinition(FunctionDefinition* functionDefinition) { this->functionDefinition = functionDefinition; }
		void setDeclaration(Declaration* declaration) { this->declaration = declaration; }

	};
}
