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
		FunctionDefinition(DeclarationSpecifiers* ds, Declarator* dec, vector<Declaration*>* dl, BaseStatement* bs);
		FunctionDefinition(DeclarationSpecifiers* ds, Declarator* dec, BaseStatement* bs);
		FunctionDefinition(Declarator* dec, vector<Declaration*>* dl, BaseStatement* bs);
		FunctionDefinition(Declarator* dec, BaseStatement* bs);
		FunctionDefinition();
		virtual ~FunctionDefinition();
		bool hasDeclarationSpecifiers() const;
		bool hasDeclarator() const;
		bool hasVectorDeclaration() const;
		bool hasBaseStatement() const;
		DeclarationSpecifiers* getDeclarationSpecifiers() const;
		Declarator* getDeclarator() const;
		vector<Declaration*>* getVectorDeclaration() const;
		BaseStatement* getBaseStatement() const;

	private:
		DeclarationSpecifiers* ds;
		Declarator* dec;
		vector<Declaration*>* dl;
		BaseStatement* bs;
	};
}
