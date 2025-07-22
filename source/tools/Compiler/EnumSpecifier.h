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
		EnumSpecifier(vector<Enumerator*>* list);
		EnumSpecifier(string value, vector<Enumerator*>* list);
		EnumSpecifier(string value);
		EnumSpecifier();
		virtual ~EnumSpecifier();

	private:
		string nameStr;
		vector<Enumerator*>* list;
	};
}
