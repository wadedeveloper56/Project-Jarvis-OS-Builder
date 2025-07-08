#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>

namespace WadeSpace {
	class DirectDeclarator
	{
	public:
		DirectDeclarator(std::string id);
		DirectDeclarator();
		~DirectDeclarator();
	private:
		std::string id;
	};
}
