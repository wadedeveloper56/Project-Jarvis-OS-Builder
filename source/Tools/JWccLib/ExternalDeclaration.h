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
		ExternalDeclaration();
		ExternalDeclaration(FunctionDefinition* functionDefinition);
		ExternalDeclaration(Declaration* declaration);
		virtual ~ExternalDeclaration();

		string toString();

		ExternalDeclaration(const ExternalDeclaration& other);
		ExternalDeclaration(ExternalDeclaration&& other) noexcept;
		ExternalDeclaration& operator=(const ExternalDeclaration& other);
		ExternalDeclaration& operator=(ExternalDeclaration&& other) noexcept;

		FunctionDefinition* getFunction() const;
		Declaration* getDeclaration() const;

		bool isFunction() const;
		bool isDeclaration() const;
		bool isTypedef() const;
		
	private:
		FunctionDefinition* functionDefinition;
		Declaration* declaration;
	};
}
