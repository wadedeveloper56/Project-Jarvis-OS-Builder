#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Pointer.h"
#include "DirectAbstractDeclarator.h"

namespace WadeSpace
{
	class AbstractDeclarator
	{
	public:
		AbstractDeclarator(Pointer* pointer);
		AbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator);
		AbstractDeclarator(Pointer* ptr, DirectAbstractDeclarator* directAbstractDeclarator);
		AbstractDeclarator();
		virtual ~AbstractDeclarator();
		Pointer* getPointer() const;
		DirectAbstractDeclarator* getDirectAbstractDeclarator() const;

	private:
		Pointer* pointer;
		DirectAbstractDeclarator* directAbstractDeclarator;
	};
}
