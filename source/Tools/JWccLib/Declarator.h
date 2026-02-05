#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Pointer.h"
#include "DirectDeclarator.h"

using namespace std;

namespace WadeSpace
{
	class Declarator
	{
	public:
		Declarator(Pointer* pointer, DirectDeclarator* directDeclarator);
		Declarator(DirectDeclarator* directDeclarator);
		Declarator();
		virtual ~Declarator();
		DirectDeclarator* getDirectDeclarator() const;
		Pointer* getPointer() const;

	private:
		DirectDeclarator* directDeclarator;
		Pointer* pointer;
	};
}
