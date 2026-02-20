#pragma once

#include <string>
#include <vector>
#include <optional>
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

		ExternalDeclaration(const ExternalDeclaration& other)
			: functionDefinition(new FunctionDefinition(*other.functionDefinition)),
			  declaration(new Declaration(*other.declaration))
		{
		}

		ExternalDeclaration(ExternalDeclaration&& other) noexcept
			: functionDefinition(new FunctionDefinition(*other.functionDefinition)),
			  declaration(new Declaration(*other.declaration))
		{
		}

		ExternalDeclaration& operator=(const ExternalDeclaration& other)
		{
			if (this == &other)
				return *this;
			functionDefinition = new FunctionDefinition(*other.functionDefinition);
			declaration = new Declaration(*other.declaration);
			return *this;
		}

		ExternalDeclaration& operator=(ExternalDeclaration&& other) noexcept
		{
			if (this == &other)
				return *this;
			functionDefinition = new FunctionDefinition(*other.functionDefinition);
			declaration = new Declaration(*other.declaration);
			return *this;
		}

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
