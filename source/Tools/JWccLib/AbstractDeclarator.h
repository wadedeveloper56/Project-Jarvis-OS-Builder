#pragma once

#include "Pointer.h"
#include "DirectAbstractDeclarator.h"

namespace WadeSpace
{
	class AbstractDeclarator
	{
	public:
		AbstractDeclarator();
		AbstractDeclarator(const AbstractDeclarator& other) = default;
		AbstractDeclarator(AbstractDeclarator&& other) = default;
		AbstractDeclarator& operator=(const AbstractDeclarator& other) = default;
		AbstractDeclarator& operator=(AbstractDeclarator&& other) = default;
		AbstractDeclarator(Pointer* pointer, DirectAbstractDeclarator* directAbstractDeclarator);
		virtual ~AbstractDeclarator();
		[[nodiscard]] Pointer* getPointer() const;
		[[nodiscard]] DirectAbstractDeclarator* getDirectAbstractDeclarator() const;
		[[nodiscard]] bool isPointer() const;
		[[nodiscard]] bool isDirectAbstractDeclarator() const;

	private:
		Pointer* pointer;
		DirectAbstractDeclarator* directAbstractDeclarator;
	};
}
