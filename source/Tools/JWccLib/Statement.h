#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace
{
	class Statement : public BaseStatement
	{
	public:
		Statement();
		Statement(TokenType op, BaseStatement* statement);
		virtual ~Statement();

		Statement(const Statement& other);
		Statement(Statement&& other) noexcept;
		Statement& operator=(const Statement& other);
		Statement& operator=(Statement&& other) noexcept;
	};
}
