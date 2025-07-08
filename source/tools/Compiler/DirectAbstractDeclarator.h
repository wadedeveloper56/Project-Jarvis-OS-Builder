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
		AbstractDeclarator& getAd() const;
	private:
		std::optional < std::reference_wrapper < AbstractDeclarator>> ad;
	};
}
