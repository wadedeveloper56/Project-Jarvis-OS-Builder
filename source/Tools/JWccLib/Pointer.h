#pragma once

#include <string>
#include <vector>
#include <optional>

#include "Token.h"
#include "TypeQualifier.h"

using namespace std;

namespace WadeSpace
{
	class Pointer
	{
	public:
		Pointer(const TokenPtr name, vector<TypeQualifier*>* typeQualifierList);
		Pointer(const TokenPtr name, vector<TypeQualifier*>* typeQualifierList, Pointer* pointer);
		Pointer(const TokenPtr name, Pointer* pointer);
		Pointer(const TokenPtr name);
		Pointer();
		virtual ~Pointer();
		void inc();

	private:
		TokenPtr name;
		vector<TypeQualifier*>* typeQualifierList;
		int level;
		Pointer* pointer;
	};
}
