#pragma once

#include "Pointer.h"
#include "DirectAbstractDeclarator.h"

namespace WadeSpace
{
	class AbstractDeclarator
	{ 
		shared_ptr<Pointer> pointer;
		shared_ptr<DirectAbstractDeclarator> directAbstractDeclarator;
	public:
		AbstractDeclarator() = default;
		AbstractDeclarator(shared_ptr<Pointer> pointer, shared_ptr<DirectAbstractDeclarator> directAbstractDeclarator);
		virtual ~AbstractDeclarator() = default;
		AbstractDeclarator(const AbstractDeclarator& other) = default;
		AbstractDeclarator(AbstractDeclarator&& other) noexcept = default;
		AbstractDeclarator& operator=(const AbstractDeclarator& other) = default;
		AbstractDeclarator& operator=(AbstractDeclarator&& other) noexcept = default;
		[[nodiscard]] shared_ptr<Pointer> getPointer() const { return pointer; }
		[[nodiscard]] shared_ptr<DirectAbstractDeclarator> getDirectAbstractDeclarator() const { return directAbstractDeclarator; }
		void setPointer(shared_ptr<Pointer> pointer) { this->pointer = pointer; }
		void setDirectAbstractDeclarator(shared_ptr<DirectAbstractDeclarator> directAbstractDeclarator) { this->directAbstractDeclarator = directAbstractDeclarator; }
		[[nodiscard]] bool hasPointer() const { return pointer != nullptr; }
		[[nodiscard]] bool hasDirectAbstractDeclarator() const { return directAbstractDeclarator != nullptr; }
	};
}
