#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TypeQualifier.h"

using namespace std;

namespace WadeSpace
{
	class Pointer
	{
	public:
		Pointer(const string&  value, vector<TypeQualifier*>* list);
		Pointer(const string&  value, vector<TypeQualifier*>* list, Pointer* ptr);
		Pointer(const string&  value, Pointer* ptr);
		Pointer(const string&  value);
		Pointer();
		virtual ~Pointer();
		void inc();

	private:
		string nameStr;
		vector<TypeQualifier*>* list;
		int level;
		Pointer* ptr;
	};
}
