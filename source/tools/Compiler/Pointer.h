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
		Pointer(const int& name, vector<TypeQualifier*>* typeQualifierList);
		Pointer(const int& name, vector<TypeQualifier*>* typeQualifierList, Pointer* pointer);
		Pointer(const int& name, Pointer* pointer);
		Pointer(const int& name);
		Pointer();
		virtual ~Pointer();
		void inc();

	private:
		optional<int> name;
		vector<TypeQualifier*>* typeQualifierList;
		int level;
		Pointer* pointer;
	};
}
