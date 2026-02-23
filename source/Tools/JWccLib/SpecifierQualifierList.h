#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TypeSpecifier.h"
#include "TypeQualifier.h"

namespace WadeSpace
{
	class SpecifierQualifierList
	{
	public:
		SpecifierQualifierList(SpecifierQualifierList* specifierQualifierList, TypeSpecifier* typeSpecifier);
		SpecifierQualifierList(TypeSpecifier* typeSpecifier);
		SpecifierQualifierList(SpecifierQualifierList* specifierQualifierList, TypeQualifier* typeQualifier);
		SpecifierQualifierList(TypeQualifier* typeQualifier);
		SpecifierQualifierList();
		virtual ~SpecifierQualifierList();

		SpecifierQualifierList(const SpecifierQualifierList& other)
			: specifierQualifierList(other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr),
			  typeSpecifier(other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr),
			  typeQualifier(other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr)
		{
		}

		SpecifierQualifierList(SpecifierQualifierList&& other) noexcept
			: specifierQualifierList(other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr),
			typeSpecifier(other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr),
			typeQualifier(other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr)
		{
		}

		SpecifierQualifierList& operator=(const SpecifierQualifierList& other)
		{
			if (this == &other)
				return *this;
			delete specifierQualifierList;
			delete typeSpecifier;
			delete typeQualifier;
			specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
			typeSpecifier = other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr;
			typeQualifier = other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr;
			return *this;
		}

		SpecifierQualifierList& operator=(SpecifierQualifierList&& other) noexcept
		{
			if (this == &other)
				return *this;
			delete specifierQualifierList;
			delete typeSpecifier;
			delete typeQualifier;
			specifierQualifierList = other.specifierQualifierList ? new SpecifierQualifierList(*other.specifierQualifierList) : nullptr;
			typeSpecifier = other.typeSpecifier ? new TypeSpecifier(*other.typeSpecifier) : nullptr;
			typeQualifier = other.typeQualifier ? new TypeQualifier(*other.typeQualifier) : nullptr;;
			return *this;
		}

		SpecifierQualifierList* getSpecifierQualifierList() const;
		TypeSpecifier* getTypeSpecifier() const;
		TypeQualifier* getTypeQualifier() const;

	private:
		SpecifierQualifierList* specifierQualifierList;
		TypeSpecifier* typeSpecifier;
		TypeQualifier* typeQualifier;
	};
}
