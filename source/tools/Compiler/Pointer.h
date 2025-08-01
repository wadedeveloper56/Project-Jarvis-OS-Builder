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
		Pointer(const string& name, vector<TypeQualifier*>* typeQualifierList);
		Pointer(const string& name, vector<TypeQualifier*>* typeQualifierList, Pointer* pointer);
		Pointer(const string& name, Pointer* pointer);
		Pointer(const string& name);
		Pointer();
		virtual ~Pointer();
		void inc();

	private:
		optional<string> name;
		vector<TypeQualifier*>* typeQualifierList;
		int level;
		Pointer* pointer;
	};
}
