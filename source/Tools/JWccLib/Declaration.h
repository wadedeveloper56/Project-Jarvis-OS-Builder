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
		DeclarationSpecifiers* declarationSpecifiers;
		vector<InitDeclarator*>* vectorInitDeclarator;
	public:
		Declaration() = default;
		Declaration(DeclarationSpecifiers* declarationSpecifiers);
		Declaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator);
		virtual ~Declaration() = default;
		[[nodiscard]] DeclarationSpecifiers* getDeclarationSpecifiers() const { return declarationSpecifiers; }
		[[nodiscard]] vector<InitDeclarator*>* getVectorInitDeclarator() const { return vectorInitDeclarator; }
		void addInitDeclarator(InitDeclarator* initDeclarator) { vectorInitDeclarator->push_back(initDeclarator); }
		[[nodiscard]] bool hasDeclarationSpecifiers() const { return declarationSpecifiers != nullptr; }
		[[nodiscard]] bool hasVectorInitDeclarator() const { return vectorInitDeclarator != nullptr; }
		void setDeclarationSpecifiers(DeclarationSpecifiers* declarationSpecifiers) { this->declarationSpecifiers = declarationSpecifiers; }
		void setVectorInitDeclarator(vector<InitDeclarator*>* vectorInitDeclarator) { this->vectorInitDeclarator = vectorInitDeclarator; }
	};
}
