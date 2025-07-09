#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

namespace WadeSpace {
	class StructOrUnion
	{
	public:
		StructOrUnion(TokenType type);
		StructOrUnion();
		~StructOrUnion();
	private:
		TokenType type;
	};
}
