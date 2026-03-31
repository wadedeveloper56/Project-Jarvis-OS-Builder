#pragma once

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
		Constant(const CTokenPtr iConst, const CTokenPtr fConst, const CTokenPtr strConst, const optional<TokenType>& type);
		Constant(const Constant& other);
		virtual ~Constant(); 

		Constant(Constant&& other) noexcept;
		Constant& operator=(const Constant& other);
		Constant& operator=(Constant&& other) noexcept;

		[[nodiscard]] CTokenPtr getIConst() const;
		[[nodiscard]] CTokenPtr getFConst() const;
		[[nodiscard]] CTokenPtr getStrConst() const;
		[[nodiscard]] optional<TokenType> getType() const;

		[[nodiscard]] bool hasIConst() const;
		[[nodiscard]] bool hasFConst() const;
		[[nodiscard]] bool hasStrConst() const;

	private:
		CTokenPtr iConst;
		CTokenPtr fConst;
		CTokenPtr strConst;
		optional<TokenType> type;
	};
}
