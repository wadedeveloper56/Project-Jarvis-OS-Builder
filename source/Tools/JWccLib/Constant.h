#pragma once

#include <string>
#include <vector>
#include <optional>

#include "Token.h"
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class Constant
	{
	public:
		Constant();
		Constant(const TokenPtr iConst, const TokenPtr fConst, const TokenPtr strConst, const optional<TokenType>& type);
		Constant(const Constant& other);
		Constant(Constant&& other) noexcept;
		virtual ~Constant();
		Constant& operator=(const Constant& other);
		Constant& operator=(Constant&& other) noexcept;
		[[nodiscard]] TokenPtr getIConst() const;
		[[nodiscard]] TokenPtr getFConst() const;
		[[nodiscard]] TokenPtr getStrConst() const;
		[[nodiscard]] optional<TokenType> getType() const;

	private:
		TokenPtr iConst;
		TokenPtr fConst;
		TokenPtr strConst;
		optional<TokenType> type;
	};
}
