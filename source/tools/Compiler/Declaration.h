#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "DeclarationSpecifiers.h"
#include "InitDeclarator.h"

using namespace std;

namespace WadeSpace
{
	class Declaration
	{
	public:
		Declaration(DeclarationSpecifiers* declarationSpecifiers);
		Declaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator);
		Declaration();
		virtual ~Declaration();
		DeclarationSpecifiers* getDeclarationSpecifiers() const;
		vector<InitDeclarator*>* getVectorInitDeclarator() const;

	private:
		DeclarationSpecifiers* declarationSpecifiers;
		vector<InitDeclarator*>* vectorInitDeclarator;
	};
}
