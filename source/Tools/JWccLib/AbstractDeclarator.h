#pragma once

#include "Pointer.h"
#include "DirectAbstractDeclarator.h"

namespace WadeSpace
{
	class AbstractDeclarator
	{ 
		Pointer* pointer;
		DirectAbstractDeclarator* directAbstractDeclarator;
	public:
		AbstractDeclarator() = default;
		AbstractDeclarator(Pointer* pointer, DirectAbstractDeclarator* directAbstractDeclarator);
		virtual ~AbstractDeclarator() = default;
		AbstractDeclarator(const AbstractDeclarator& other) = default;
		AbstractDeclarator(AbstractDeclarator&& other) noexcept = default;
		AbstractDeclarator& operator=(const AbstractDeclarator& other) = default;
		AbstractDeclarator& operator=(AbstractDeclarator&& other) noexcept = default;
		[[nodiscard]] Pointer* getPointer() const { return pointer; }
		[[nodiscard]] DirectAbstractDeclarator* getDirectAbstractDeclarator() const { return directAbstractDeclarator; }
		void setPointer(Pointer* pointer) { this->pointer = pointer; }
		void setDirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator) { this->directAbstractDeclarator = directAbstractDeclarator; }
		[[nodiscard]] bool hasPointer() const { return pointer != nullptr; }
		[[nodiscard]] bool hasDirectAbstractDeclarator() const { return directAbstractDeclarator != nullptr; }
	};
}
