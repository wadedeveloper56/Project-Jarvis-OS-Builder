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

		EnumSpecifier(const EnumSpecifier& other)
			: nameStr(new Token(*other.nameStr)),
			  vectorEnumerator(new vector<Enumerator*>(*other.vectorEnumerator))
		{
		}

		EnumSpecifier(EnumSpecifier&& other) noexcept
			: nameStr(new Token(*other.nameStr)),
			  vectorEnumerator(new vector<Enumerator*>(*other.vectorEnumerator))
		{
		}

		EnumSpecifier& operator=(const EnumSpecifier& other)
		{
			if (this == &other)
				return *this;
			nameStr = new Token(*other.nameStr);
			vectorEnumerator = new vector<Enumerator*>(*other.vectorEnumerator);
			return *this;
		}

		EnumSpecifier& operator=(EnumSpecifier&& other) noexcept
		{
			if (this == &other)
				return *this;
			nameStr = new Token(*other.nameStr);
			vectorEnumerator = new vector<Enumerator*>(*other.vectorEnumerator);
			return *this;
		}

		[[nodiscard]] TokenPtr getNameStr() const;
		[[nodiscard]] vector<Enumerator*>* getVectorEnumerator() const;
		[[nodiscard]] bool isNameStr() const;
		[[nodiscard]] bool isVectorEnumerator() const;

	private:
		TokenPtr  nameStr;
		vector<Enumerator*>* vectorEnumerator;
	};
}
