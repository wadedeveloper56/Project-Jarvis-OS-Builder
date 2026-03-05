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
		Pointer(const TokenPtr name, vector<TypeQualifier*>* typeQualifierList);
		Pointer(const TokenPtr name, vector<TypeQualifier*>* typeQualifierList, Pointer* pointer);
		Pointer(const TokenPtr name, Pointer* pointer);
		Pointer(const TokenPtr name);
		virtual ~Pointer();

		Pointer(const Pointer& other);
		Pointer(Pointer&& other) noexcept;
		Pointer& operator=(const Pointer& other);
		Pointer& operator=(Pointer&& other) noexcept;

		[[nodiscard]] TokenPtr getName() const;
		[[nodiscard]] vector<TypeQualifier*>* getTypeQualifierList() const;
		[[nodiscard]] int getLevel() const;
		[[nodiscard]] Pointer* getPointer() const;

		void inc();

		[[nodiscard]] bool hasName() const;
		[[nodiscard]] bool hasTypeQualifierList() const;
		[[nodiscard]] bool hasLevel() const;
		[[nodiscard]] bool hasPointer() const;


	private:
		TokenPtr name;
		vector<TypeQualifier*>* typeQualifierList;
		int level;
		Pointer* pointer;
	};
}
