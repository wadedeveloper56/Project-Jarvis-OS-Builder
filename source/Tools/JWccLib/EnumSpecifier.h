#pragma once

#include <string>
#include <vector>
#include <optional>
#include "Enumerator.h"
#include "Token.h"

using namespace std;

namespace WadeSpace
{
	class EnumSpecifier
	{
	public:
		EnumSpecifier(TokenPtr nameStr, vector<Enumerator*>* vectorEnumerator);
		EnumSpecifier();
		virtual ~EnumSpecifier();
		EnumSpecifier(const EnumSpecifier& other);
		EnumSpecifier(EnumSpecifier&& other) noexcept;
		EnumSpecifier& operator=(const EnumSpecifier& other);
		EnumSpecifier& operator=(EnumSpecifier&& other) noexcept;
		[[nodiscard]] TokenPtr getNameStr() const;
		[[nodiscard]] vector<Enumerator*>* getVectorEnumerator() const;
		[[nodiscard]] bool isNameStr() const;
		[[nodiscard]] bool isVectorEnumerator() const;

	private:
		TokenPtr  nameStr;
		vector<Enumerator*>* vectorEnumerator;
	};
}
