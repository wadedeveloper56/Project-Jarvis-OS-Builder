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
		Declaration(DeclarationSpecifiers* ds);
		Declaration(DeclarationSpecifiers* ds, vector<InitDeclarator*>* idl);
		Declaration();
		virtual ~Declaration();
		bool hasDeclarationSpecifiers() const;
		bool hasVectorInitDeclarator() const;
		DeclarationSpecifiers* getDeclarationSpecifiers() const;
		vector<InitDeclarator*>* getVectorInitDeclarator() const;

	private:
		DeclarationSpecifiers* ds;
		vector<InitDeclarator*>* idl;
	};
}
