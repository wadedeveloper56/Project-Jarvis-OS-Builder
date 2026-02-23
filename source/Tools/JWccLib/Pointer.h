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

		Pointer(const Pointer& other)
			: name(other.name),
			  typeQualifierList(new vector<TypeQualifier*>(*other.typeQualifierList)),
			  level(other.level),
			  pointer(new Pointer(*other.pointer)	)
		{
		}

		Pointer(Pointer&& other) noexcept
			: name(other.name),
			typeQualifierList(new vector<TypeQualifier*>(*other.typeQualifierList)),
			level(other.level),
			pointer(new Pointer(*other.pointer))
		{
		}

		Pointer& operator=(const Pointer& other)
		{
			if (this == &other)
				return *this;
			name = other.name;
			delete typeQualifierList;
			typeQualifierList = new vector<TypeQualifier*>(*other.typeQualifierList);
			level = other.level;
			delete pointer;
			pointer = new Pointer(*other.pointer);
			return *this;
		}

		Pointer& operator=(Pointer&& other) noexcept
		{
			if (this == &other)
				return *this;
			name = other.name;
			delete typeQualifierList;
			typeQualifierList = new vector<TypeQualifier*>(*other.typeQualifierList);
			level = other.level;
			delete pointer;
			pointer = new Pointer(*other.pointer);
			return *this;
		}

		void inc();

	private:
		TokenPtr name;
		vector<TypeQualifier*>* typeQualifierList;
		int level;
		Pointer* pointer;
	};
}
