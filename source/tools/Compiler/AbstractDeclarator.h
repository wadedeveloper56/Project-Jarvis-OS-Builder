#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Pointer.h"
#include "DirectAbstractDeclarator.h"

namespace WadeSpace {
	class AbstractDeclarator
	{
	public:
		AbstractDeclarator(Pointer* ptr);
		AbstractDeclarator(DirectAbstractDeclarator* dad);
		AbstractDeclarator(Pointer* ptr, DirectAbstractDeclarator* dad);
		AbstractDeclarator();
		virtual ~AbstractDeclarator();
		bool hasPointer() const;
		bool hasDirectAbstractDeclarator() const;
		Pointer* getPointer() const;
		DirectAbstractDeclarator* getDirectAbstractDeclarator() const;
	private:
		Pointer* ptr;
		DirectAbstractDeclarator* dad;
	};
}


