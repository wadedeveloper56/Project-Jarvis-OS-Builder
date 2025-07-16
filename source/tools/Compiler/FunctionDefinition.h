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

namespace WadeSpace {
	class FunctionDefinition
	{
	public:
		FunctionDefinition(DeclarationSpecifiers& ds,Declarator& dec,vector<Declaration>& dl,BaseStatement& bs);
		FunctionDefinition(DeclarationSpecifiers& ds, Declarator& dec, BaseStatement& bs);
		FunctionDefinition(Declarator& dec, vector<Declaration>& dl, BaseStatement& bs);
		FunctionDefinition(Declarator& dec, BaseStatement& bs);
		FunctionDefinition();
		~FunctionDefinition();
	private:
		optional < reference_wrapper < DeclarationSpecifiers>> ds;
		optional < reference_wrapper < Declarator>> dec;
		optional < reference_wrapper < vector<Declaration>>> dl;
		optional < reference_wrapper < BaseStatement>> bs;
	};
}
