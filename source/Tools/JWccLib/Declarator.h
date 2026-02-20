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

		Declarator(const Declarator& other)
			: directDeclarator(new DirectDeclarator(*other.directDeclarator)),
			  pointer(new Pointer(*other.pointer))
		{
		}

		Declarator(Declarator&& other) noexcept
			: directDeclarator(new DirectDeclarator(*other.directDeclarator)),
			  pointer(new Pointer(*other.pointer))
		{
		}

		Declarator& operator=(const Declarator& other)
		{
			if (this == &other)
				return *this;
			directDeclarator = other.directDeclarator;
			pointer = other.pointer;
			return *this;
		}

		Declarator& operator=(Declarator&& other) noexcept
		{
			if (this == &other)
				return *this;
			directDeclarator = other.directDeclarator;
			pointer = other.pointer;
			return *this;
		}

		[[nodiscard]] DirectDeclarator* getDirectDeclarator() const;
		[[nodiscard]] Pointer* getPointer() const;
		[[nodiscard]] bool isDirectDeclarator() const;
		[[nodiscard]] bool isPointer() const;

	private:
		DirectDeclarator* directDeclarator;
		Pointer* pointer;
	};
}
