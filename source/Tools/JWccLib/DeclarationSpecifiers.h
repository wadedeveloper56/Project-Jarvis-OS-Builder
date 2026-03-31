#pragma once

#include "StorageClassSpecifier.h"
#include "TypeSpecifier.h"
#include "TypeQualifier.h"

namespace WadeSpace
{
	class DeclarationSpecifiersNode
	{
	public:
		StorageClassSpecifier* storageClassSpecifier;
		TypeSpecifier* typeSpecifier;
		TypeQualifier* typeQualifier;

		DeclarationSpecifiersNode() = default;
		DeclarationSpecifiersNode(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier);
		~DeclarationSpecifiersNode() = default;
		DeclarationSpecifiersNode(const DeclarationSpecifiersNode& other) = default;
		DeclarationSpecifiersNode(DeclarationSpecifiersNode&& other) noexcept = default;
		DeclarationSpecifiersNode& operator=(const DeclarationSpecifiersNode& other) = default;
		DeclarationSpecifiersNode& operator=(DeclarationSpecifiersNode&& other) noexcept = default;
	};

	class DeclarationSpecifiers
	{
		vector<DeclarationSpecifiersNode*>* declarationSpecifiersNodeList;
	public:
		DeclarationSpecifiers() = default;
		virtual ~DeclarationSpecifiers() = default;
		void addDeclarationSpecifiersNode(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier);
		[[nodiscard]] vector<DeclarationSpecifiersNode*>* getDeclarationSpecifiersNodeList() const { return declarationSpecifiersNodeList; }
		DeclarationSpecifiers(const DeclarationSpecifiers& other) = default;
		DeclarationSpecifiers(DeclarationSpecifiers&& other) noexcept = default;
		DeclarationSpecifiers& operator=(const DeclarationSpecifiers& other) = default;
		DeclarationSpecifiers& operator=(DeclarationSpecifiers&& other) noexcept = default;
		void setDeclarationSpecifiersNodeList(vector<DeclarationSpecifiersNode*>* const declarationSpecifiersNodeList) { this->declarationSpecifiersNodeList = declarationSpecifiersNodeList; }
		[[nodiscard]] bool hasDeclarationSpecifiersNodeList() const { return declarationSpecifiersNodeList != nullptr; }
	};
}
