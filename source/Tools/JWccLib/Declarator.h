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
		DirectDeclarator* directDeclarator;
		Pointer* pointer;
	public:
		Declarator() = default;
		Declarator(Pointer* pointer, DirectDeclarator* directDeclarator);
		virtual ~Declarator() = default;
		[[nodiscard]] DirectDeclarator* getDirectDeclarator() const { return directDeclarator; }
		[[nodiscard]] Pointer* getPointer() const { return pointer; }
		void setDirectDeclarator(DirectDeclarator* const directDeclarator) { this->directDeclarator = directDeclarator; }
		void setPointer(Pointer* const pointer) { this->pointer = pointer; }
		bool hasDirectDeclarator() const { return directDeclarator != nullptr; }
		bool hasPointer() const { return pointer != nullptr; }
	};
}
