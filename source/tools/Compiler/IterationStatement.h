#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace {
    class IterationStatement : public BaseStatement
	{
	public:
		IterationStatement();
		~IterationStatement();
	};
}
