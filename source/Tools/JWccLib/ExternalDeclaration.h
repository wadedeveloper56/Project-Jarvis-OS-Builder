#pragma once

#include "TokenType.h"
#include "FunctionDefinition.h"
#include "Declaration.h"

using namespace std;

namespace WadeSpace
{
	class ExternalDeclaration
	{
	public:
		ExternalDeclaration(FunctionDefinition* functionDefinition);
		ExternalDeclaration(Declaration* declaration);
		ExternalDeclaration();
		virtual ~ExternalDeclaration();
		string toString();
		ExternalDeclaration(const ExternalDeclaration& other);
		ExternalDeclaration(ExternalDeclaration&& other) noexcept;
		ExternalDeclaration& operator=(const ExternalDeclaration& other);
		ExternalDeclaration& operator=(ExternalDeclaration&& other) noexcept;
		bool isFunction() const;
		bool isDeclaration() const;
		FunctionDefinition* getFunction() const;
		Declaration* getDeclaration() const;
		bool isTypedef() const;

	private:
		FunctionDefinition* functionDefinition;
		Declaration* declaration;
	};
}
