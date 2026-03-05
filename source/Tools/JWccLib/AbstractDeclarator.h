#pragma once

#include "Pointer.h"
#include "DirectAbstractDeclarator.h"

namespace WadeSpace
{
	class AbstractDeclarator
	{ 
	public:
		AbstractDeclarator();
		AbstractDeclarator(Pointer* pointer, DirectAbstractDeclarator* directAbstractDeclarator); 
		virtual ~AbstractDeclarator();

		AbstractDeclarator(const AbstractDeclarator& other); 
		AbstractDeclarator(AbstractDeclarator&& other) noexcept;
		AbstractDeclarator& operator=(const AbstractDeclarator& other);
		AbstractDeclarator& operator=(AbstractDeclarator&& other) noexcept;

		[[nodiscard]] Pointer* getPointer() const;
		[[nodiscard]] DirectAbstractDeclarator* getDirectAbstractDeclarator() const;

		[[nodiscard]] bool hasPointer() const;
		[[nodiscard]] bool hasDirectAbstractDeclarator() const;

	private:
		Pointer* pointer;
		DirectAbstractDeclarator* directAbstractDeclarator;
	};
}
