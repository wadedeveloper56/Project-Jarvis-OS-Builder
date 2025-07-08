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
		AbstractDeclarator(Pointer& ptr);
		AbstractDeclarator(DirectAbstractDeclarator& dad);
		AbstractDeclarator(Pointer& ptr, DirectAbstractDeclarator& dad);
		AbstractDeclarator();
		~AbstractDeclarator();
		Pointer& getPointer() const;
		DirectAbstractDeclarator& getDad() const;
	private:
		std::optional<std::reference_wrapper < Pointer>> ptr;
		std::optional < std::reference_wrapper < DirectAbstractDeclarator>> dad;
	};
}


