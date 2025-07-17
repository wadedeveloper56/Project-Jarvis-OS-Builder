#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Declarator.h"
#include "Initializer.h"

namespace WadeSpace {
	class InitDeclarator
	{
	public:
		InitDeclarator(Declarator* dec);
		InitDeclarator(Declarator* dec, Initializer* init);
		InitDeclarator();
		~InitDeclarator();
	private:
		Declarator* dec;
		Initializer* init;
	};
}
