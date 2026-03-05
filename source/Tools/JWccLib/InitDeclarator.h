#pragma once

#include <string>
#include "Declarator.h"
#include "Initializer.h"

namespace WadeSpace
{
	class InitDeclarator
	{
	public:
		InitDeclarator();
		InitDeclarator(Declarator* declarator);
		InitDeclarator(Declarator* declarator, Initializer* initializer);
		virtual ~InitDeclarator();

		InitDeclarator(const InitDeclarator& other);
		InitDeclarator(InitDeclarator&& other) noexcept;
		InitDeclarator& operator=(const InitDeclarator& other);
		InitDeclarator& operator=(InitDeclarator&& other) noexcept;

		[[nodiscard]] Declarator* getDeclarator() const;
		[[nodiscard]] Initializer* getInitializer() const;

		[[nodiscard]] bool hasDeclarator() const;
		[[nodiscard]] bool hasInitializer() const;

		[[nodiscard]] string getVariableName() const;

	private:
		Declarator* declarator;
		Initializer* initializer;
	};
}
