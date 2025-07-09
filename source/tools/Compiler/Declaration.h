#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "DeclarationSpecifiers.h"
#include "InitDeclarator.h"

namespace WadeSpace {
	class Declaration
	{
	public:
		Declaration(DeclarationSpecifiers& ds);
		Declaration(DeclarationSpecifiers& ds,std::vector<InitDeclarator> idl);
		Declaration();
		~Declaration();
	private:
		std::optional < std::reference_wrapper < DeclarationSpecifiers>> ds;
		std::optional < std::reference_wrapper < std::vector<InitDeclarator>>> idl;
	};
}
