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
		Pointer();
		Pointer(const CTokenPtr name, vector<TypeQualifier*>* typeQualifierList);
		Pointer(const CTokenPtr name, vector<TypeQualifier*>* typeQualifierList, Pointer* pointer);
		Pointer(const CTokenPtr name, Pointer* pointer);
		Pointer(const CTokenPtr name);
		virtual ~Pointer();

		Pointer(const Pointer& other);
		Pointer(Pointer&& other) noexcept;
		Pointer& operator=(const Pointer& other);
		Pointer& operator=(Pointer&& other) noexcept;

		[[nodiscard]] CTokenPtr getName() const;
		[[nodiscard]] vector<TypeQualifier*>* getTypeQualifierList() const;
		[[nodiscard]] int getLevel() const;
		[[nodiscard]] Pointer* getPointer() const;

		void inc();

		[[nodiscard]] bool hasName() const;
		[[nodiscard]] bool hasTypeQualifierList() const;
		[[nodiscard]] bool hasLevel() const;
		[[nodiscard]] bool hasPointer() const;


	private:
		CTokenPtr name;
		vector<TypeQualifier*>* typeQualifierList;
		int level;
		Pointer* pointer;
	};
}
