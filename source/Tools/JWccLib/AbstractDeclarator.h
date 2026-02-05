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
		Pointer* getPointer() const;
		DirectAbstractDeclarator* getDirectAbstractDeclarator() const;
		bool isPointer() const;
		bool isDirectAbstractDeclarator() const;
	private:
		Pointer* pointer;
		DirectAbstractDeclarator* directAbstractDeclarator;
	};
}
