#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TypeQualifier.h"

using namespace std;

namespace WadeSpace {
	class Pointer
	{
	public:
		Pointer(string value, vector<TypeQualifier *>* list);
		Pointer(string value, vector<TypeQualifier *>* list, Pointer* ptr);
		Pointer(string value, Pointer* ptr);
		Pointer(string value);
		Pointer();
		virtual ~Pointer();
		void inc();
	private:
		string nameStr;
		vector<TypeQualifier *>* list;
		int level;
		Pointer* ptr;
	};
}
