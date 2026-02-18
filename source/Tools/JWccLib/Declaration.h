#pragma once

#include <string>
#include <vector>
#include <optional>
#include "DeclarationSpecifiers.h"
#include "InitDeclarator.h"

using namespace std;

namespace WadeSpace
{
	class Declaration
	{
	public:
		explicit Declaration(DeclarationSpecifiers* declarationSpecifiers);
		Declaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator);
		Declaration();
		virtual ~Declaration();
		[[nodiscard]] DeclarationSpecifiers* getDeclarationSpecifiers() const;
		[[nodiscard]] vector<InitDeclarator*>* getVectorInitDeclarator() const;
		
		[[nodiscard]] bool isDeclarationSpecifiers() const;
		[[nodiscard]] bool isVectorInitDeclarator() const;

	private:
		DeclarationSpecifiers* declarationSpecifiers;
		vector<InitDeclarator*>* vectorInitDeclarator;
	};
}
