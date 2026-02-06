#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class Constant
	{
	public:
		Constant(const optional<uint64_t>& iConst, const optional<long double>& fConst,	const optional<string>& strConst, const optional<TokenType>& type);
		Constant();
		virtual ~Constant() = default;
		[[nodiscard]] optional<uint64_t> getIConst() const;
		[[nodiscard]] optional<long double> getFConst() const;
		[[nodiscard]] optional<string> getStrConst() const;
		[[nodiscard]] optional<TokenType> getType() const;

	private:
		optional<uint64_t> iConst;
		optional<long double> fConst;
		optional<string> strConst;
		optional<TokenType> type;
	};
}
