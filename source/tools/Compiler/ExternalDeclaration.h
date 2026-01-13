#pragma once

#include <string>
#include <vector>
#include <stdint.h>
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
		bool isFunction() const;
		bool isDeclaration() const;
		FunctionDefinition* getFunction() const;
		Declaration* getDeclaration() const;

	private:
		FunctionDefinition* functionDefinition;
		Declaration* declaration;
	};
}
