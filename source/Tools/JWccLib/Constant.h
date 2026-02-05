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
		explicit Constant(const uint64_t value);
		explicit Constant(const long double value);
		explicit Constant(const string& value);
		Constant();
		virtual ~Constant() = default;
		[[nodiscard]]
		uint64_t getIConst() const;
		[[nodiscard]]
		long double getFConst() const;
		[[nodiscard]]
		optional<string> getStrConst() const;
		[[nodiscard]]
		TokenType getType() const;

	private:
		uint64_t iConst;
		long double fConst;
		optional<string> strConst;
		TokenType type;
	};
}
