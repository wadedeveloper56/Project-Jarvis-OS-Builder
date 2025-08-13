#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Enumerator.h"

using namespace std;

namespace WadeSpace
{
	class EnumSpecifier
	{
	public:
		EnumSpecifier(vector<Enumerator*>* vectorEnumerator);
		EnumSpecifier(string& nameStr, vector<Enumerator*>* vectorEnumerator);
		EnumSpecifier(string& nameStr);
		EnumSpecifier();
		virtual ~EnumSpecifier();
		vector<Enumerator*>* getVectorEnumerator() const;

	private:
		optional<string>  nameStr;
		vector<Enumerator*>* vectorEnumerator;
	};
}
