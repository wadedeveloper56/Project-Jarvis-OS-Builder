#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "DirectDeclarator.h"
#include "Pointer.h"

namespace WadeSpace {
	class Declarator
	{
	public:
		Declarator(Pointer& ptr,DirectDeclarator& dd);
		Declarator(DirectDeclarator& dd);
		Declarator();
		~Declarator();
		DirectDeclarator& getDirectDeclarator() const;
		Pointer& getPointer() const;
	private:
		std::optional<std::reference_wrapper < DirectDeclarator>> dd;
		std::optional<std::reference_wrapper < Pointer>> ptr;
	};
}
