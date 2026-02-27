#pragma once

#include <string>
#include <vector>
#include <optional>
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

		Declarator* getDeclarator() const;
		Initializer* getInitializer() const;
		bool isDeclarator() const;
		bool isInitializer() const;
		string getVariableName() const;

	private:
		Declarator* declarator;
		Initializer* initializer;
	};
}
