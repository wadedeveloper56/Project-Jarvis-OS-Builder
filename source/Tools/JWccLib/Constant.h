#pragma once

#include <optional>
#include "Token.h"
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class Constant
	{
		CTokenPtr iConst;
		CTokenPtr fConst;
		CTokenPtr strConst;
		optional<TokenType> type;
	public:
		Constant() = default;
		Constant(const CTokenPtr iConst, const CTokenPtr fConst, const CTokenPtr strConst, const optional<TokenType>& type);
		Constant(const Constant& other) = default;
		virtual ~Constant() = default;
		Constant(Constant&& other) noexcept = default;
		Constant& operator=(const Constant& other) = default;
		Constant& operator=(Constant&& other) noexcept = default;
		[[nodiscard]] CTokenPtr getIConst() const { return iConst; }
		[[nodiscard]] CTokenPtr getFConst() const { return fConst; }
		[[nodiscard]] CTokenPtr getStrConst() const { return strConst; }
		[[nodiscard]] optional<TokenType> getType() const { return type; }
		void setIConst(const CTokenPtr iConst) { this->iConst = iConst; }
		void setFConst(const CTokenPtr fConst) { this->fConst = fConst; }
		void setStrConst(const CTokenPtr strConst) { this->strConst = strConst; }
		void setType(const optional<TokenType>& type) { this->type = type; }
		[[nodiscard]] bool hasIConst() const { return iConst != nullptr; }
		[[nodiscard]] bool hasFConst() const { return fConst != nullptr; }
		[[nodiscard]] bool hasStrConst() const { return strConst != nullptr; }
		[[nodiscard]] bool hasType() const { return type.has_value(); }
	};
}
