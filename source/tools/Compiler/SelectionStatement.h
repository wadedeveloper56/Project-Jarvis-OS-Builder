#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace {
	class SelectionStatement : public BaseStatement
	{
	public:
		SelectionStatement();
		~SelectionStatement();
	};
}
