#pragma once

#include <string>
#include <vector>
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
		Declarator();
		virtual ~Declarator();
		[[nodiscard]] DirectDeclarator* getDirectDeclarator() const;
		[[nodiscard]] Pointer* getPointer() const;
		[[nodiscard]] bool isDirectDeclarator() const;
		[[nodiscard]] bool isPointer() const;

	private:
		DirectDeclarator* directDeclarator;
		Pointer* pointer;
	};
}
