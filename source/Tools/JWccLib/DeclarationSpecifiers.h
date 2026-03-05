#pragma once

#include "StorageClassSpecifier.h"
#include "TypeSpecifier.h"
#include "TypeQualifier.h"

namespace WadeSpace
{
	struct DeclarationSpecifiersNode
	{
		StorageClassSpecifier* storageClassSpecifier;
		TypeSpecifier* typeSpecifier;
		TypeQualifier* typeQualifier;
		DeclarationSpecifiersNode(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier);
		~DeclarationSpecifiersNode();

		DeclarationSpecifiersNode(const DeclarationSpecifiersNode& other) = default;
		DeclarationSpecifiersNode(DeclarationSpecifiersNode&& other) noexcept = default;
		DeclarationSpecifiersNode& operator=(const DeclarationSpecifiersNode& other) = default;
		DeclarationSpecifiersNode& operator=(DeclarationSpecifiersNode&& other) noexcept = default;
	};

	class DeclarationSpecifiers
	{
	public:
		DeclarationSpecifiers();
		virtual ~DeclarationSpecifiers(); 
		void addDeclarationSpecifiersNode(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier);
		
		[[nodiscard]] vector<DeclarationSpecifiersNode*>* getDeclarationSpecifiersNodeList() const;
		[[nodiscard]] bool hasDeclarationSpecifiersNodeList() const;

		DeclarationSpecifiers(const DeclarationSpecifiers& other);
		DeclarationSpecifiers(DeclarationSpecifiers&& other) noexcept;
		DeclarationSpecifiers& operator=(const DeclarationSpecifiers& other);
		DeclarationSpecifiers& operator=(DeclarationSpecifiers&& other) noexcept;

	private:
		vector<DeclarationSpecifiersNode*>* declarationSpecifiersNodeList;
	};
}
