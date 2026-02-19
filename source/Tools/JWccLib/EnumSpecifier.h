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
		vector<Enumerator*>* getVectorEnumerator() const;

	private:
		TokenPtr  nameStr;
		vector<Enumerator*>* vectorEnumerator;
	};
}
