#pragma once

#include "Pointer.h"
#include "DirectAbstractDeclarator.h"

namespace WadeSpace
{
	class AbstractDeclarator
	{
	public:
		AbstractDeclarator(const AbstractDeclarator& copy);
		AbstractDeclarator(Pointer* pointer, DirectAbstractDeclarator* directAbstractDeclarator);
		AbstractDeclarator();
		virtual ~AbstractDeclarator();
		[[nodiscard]]
		Pointer* getPointer() const;
		[[nodiscard]]
		DirectAbstractDeclarator* getDirectAbstractDeclarator() const;
		[[nodiscard]]
		bool isPointer() const;
		[[nodiscard]]
		bool isDirectAbstractDeclarator() const;

	private:
		Pointer* pointer;
		DirectAbstractDeclarator* directAbstractDeclarator;
	};
}
