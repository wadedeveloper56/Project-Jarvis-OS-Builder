#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Expression.h"
#include "Enumerator.h"

using namespace std;

namespace WadeSpace
{
	class EnumSpecifier
	{
	public:
		EnumSpecifier(vector<Enumerator*>* vectorEnumerator);
		EnumSpecifier(string&  nameStr, vector<Enumerator*>* vectorEnumerator);
		EnumSpecifier(string&  nameStr);
		EnumSpecifier();
		virtual ~EnumSpecifier();
		bool hasNameStr() const;
		string getNameStr() const;
		vector<Enumerator*>* getVectorEnumerator() const;

	private:
		optional<reference_wrapper<string>>  nameStr;
		vector<Enumerator*>* vectorEnumerator;
	};
}
