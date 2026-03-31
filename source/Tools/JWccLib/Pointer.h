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
		CTokenPtr name;
		vector<TypeQualifier*>* typeQualifierList;
		int level;
		Pointer* pointer;
	public:
		Pointer() = default;
		Pointer(const CTokenPtr name, vector<TypeQualifier*>* typeQualifierList);
		Pointer(const CTokenPtr name, vector<TypeQualifier*>* typeQualifierList, Pointer* pointer);
		Pointer(const CTokenPtr name, Pointer* pointer);
		Pointer(const CTokenPtr name);
		virtual ~Pointer() = default;
		Pointer(const Pointer& other) = default;
		Pointer(Pointer&& other) noexcept = default;
		Pointer& operator=(const Pointer& other) = default;
		Pointer& operator=(Pointer&& other) noexcept = default;
		void inc();
		[[nodiscard]] CTokenPtr getName() const { return name; }
		[[nodiscard]] vector<TypeQualifier*>* getTypeQualifierList() const { return typeQualifierList; }
		[[nodiscard]] int getLevel() const { return level; }
		[[nodiscard]] Pointer* getPointer() const { return pointer; }
		void setName(const CTokenPtr name) { this->name = name; }
		void setTypeQualifierList(vector<TypeQualifier*>* typeQualifierList) { this->typeQualifierList = typeQualifierList; }
		void setLevel(int level) { this->level = level; }
		void setPointer(Pointer* pointer) { this->pointer = pointer; }
		[[nodiscard]] bool hasName() const { return name != nullptr; }
		[[nodiscard]] bool hasTypeQualifierList() const { return typeQualifierList != nullptr; }
		[[nodiscard]] bool hasPointer() const { return pointer != nullptr; }
		void addTypeQualifier(TypeQualifier* typeQualifier)
		{
			if (typeQualifierList == nullptr)
			{
				typeQualifierList = new vector<TypeQualifier*>();
			}
			typeQualifierList->push_back(typeQualifier);
		}
	};
}
