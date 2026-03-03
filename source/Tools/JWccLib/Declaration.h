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
		Declaration();
		Declaration(DeclarationSpecifiers* declarationSpecifiers);
		Declaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator);
		virtual ~Declaration();

		Declaration(const Declaration& other);
		Declaration(Declaration&& other) noexcept;
		Declaration& operator=(const Declaration& other);
		Declaration& operator=(Declaration&& other) noexcept;

		[[nodiscard]] DeclarationSpecifiers* getDeclarationSpecifiers() const;
		[[nodiscard]] vector<InitDeclarator*>* getVectorInitDeclarator() const;
		
		[[nodiscard]] bool isDeclarationSpecifiers() const;
		[[nodiscard]] bool isVectorInitDeclarator() const;
		
	private:
		DeclarationSpecifiers* declarationSpecifiers;
		vector<InitDeclarator*>* vectorInitDeclarator;
	};
}
