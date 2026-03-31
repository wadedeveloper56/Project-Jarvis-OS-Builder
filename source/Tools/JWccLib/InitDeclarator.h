#pragma once

#include <string>
#include "Declarator.h"
#include "Initializer.h"

namespace WadeSpace
{
	class InitDeclarator
	{
		Declarator* declarator;
		Initializer* initializer;
	public:
		InitDeclarator() = default;
		InitDeclarator(Declarator* declarator);
		InitDeclarator(Declarator* declarator, Initializer* initializer);
		virtual ~InitDeclarator() = default;
		InitDeclarator(const InitDeclarator& other) = default;
		InitDeclarator(InitDeclarator&& other) noexcept = default;
		InitDeclarator& operator=(const InitDeclarator& other) = default;
		InitDeclarator& operator=(InitDeclarator&& other) noexcept = default;
		[[nodiscard]] string getVariableName() const;
		[[nodiscard]] Declarator* getDeclarator() const { return declarator; }
		[[nodiscard]] Initializer* getInitializer() const { return initializer; }
		[[nodiscard]] bool hasDeclarator() const { return declarator != nullptr; }
		[[nodiscard]] bool hasInitializer() const { return initializer != nullptr; }
		void setDeclarator(Declarator* const declarator) { this->declarator = declarator; }
		void setInitializer(Initializer* const initializer) { this->initializer = initializer; }
	};
}
