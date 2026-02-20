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

		Declaration(const Declaration& other)
			: declarationSpecifiers(new DeclarationSpecifiers(*other.declarationSpecifiers)),
			  vectorInitDeclarator(new vector<InitDeclarator*>(*other.vectorInitDeclarator))
		{
		}

		Declaration(Declaration&& other) noexcept
			: declarationSpecifiers(new DeclarationSpecifiers(*other.declarationSpecifiers)),
			vectorInitDeclarator(new vector<InitDeclarator*>(*other.vectorInitDeclarator))
		{
		}

		Declaration& operator=(const Declaration& other)
		{
			if (this == &other)
				return *this;
			declarationSpecifiers = new DeclarationSpecifiers(*other.declarationSpecifiers);
			vectorInitDeclarator = new vector<InitDeclarator*>(*other.vectorInitDeclarator);
			return *this;
		}

		Declaration& operator=(Declaration&& other) noexcept
		{
			if (this == &other)
				return *this;
			declarationSpecifiers = new DeclarationSpecifiers(*other.declarationSpecifiers);
			vectorInitDeclarator = new vector<InitDeclarator*>(*other.vectorInitDeclarator);
			return *this;
		}

		[[nodiscard]] DeclarationSpecifiers* getDeclarationSpecifiers() const;
		[[nodiscard]] vector<InitDeclarator*>* getVectorInitDeclarator() const;
		[[nodiscard]] StorageClassSpecifier* getStorageClassSpecifier() const { return getDeclarationSpecifiers()->getStorageClassSpecifier(); }
		
		[[nodiscard]] bool isDeclarationSpecifiers() const;
		[[nodiscard]] bool isVectorInitDeclarator() const;
		[[nodiscard]] bool isStorageClassSpecifier() const;
		[[nodiscard]] bool isTypedef() const;

	private:
		DeclarationSpecifiers* declarationSpecifiers;
		vector<InitDeclarator*>* vectorInitDeclarator;
	};
}
