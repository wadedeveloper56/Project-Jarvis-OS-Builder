#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>

namespace WadeSpace {
    class AbstractDeclarator;

	class DirectAbstractDeclarator
	{
	public:
		DirectAbstractDeclarator(AbstractDeclarator& ad);
		DirectAbstractDeclarator();
		~DirectAbstractDeclarator();
	private:
		std::optional < std::reference_wrapper < AbstractDeclarator>> ad;
	};
}
