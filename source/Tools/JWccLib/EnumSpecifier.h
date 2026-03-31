#pragma once

#include <vector>
#include "Enumerator.h"
#include "Token.h"

using namespace std;

namespace WadeSpace
{
	class EnumSpecifier
	{
		CTokenPtr  nameStr;
		vector<Enumerator*>* vectorEnumerator;
	public:
		EnumSpecifier() = default;
		EnumSpecifier(CTokenPtr nameStr, vector<Enumerator*>* vectorEnumerator);
		virtual ~EnumSpecifier() = default;
		EnumSpecifier(const EnumSpecifier& other) = default;
		EnumSpecifier(EnumSpecifier&& other) noexcept = default;
		EnumSpecifier& operator=(const EnumSpecifier& other) = default;
		EnumSpecifier& operator=(EnumSpecifier&& other) noexcept = default;
		[[nodiscard]] CTokenPtr getNameStr() const { return nameStr; }
		[[nodiscard]] vector<Enumerator*>* getVectorEnumerator() const { return vectorEnumerator; }
		[[nodiscard]] bool hasNameStr() const { return nameStr != nullptr; }
		[[nodiscard]] bool hasVectorEnumerator() const { return vectorEnumerator != nullptr; }
		void setNameStr(CTokenPtr nameStr) { this->nameStr = nameStr; }
		void setVectorEnumerator(vector<Enumerator*>* vectorEnumerator) { this->vectorEnumerator = vectorEnumerator; }
		void addEnumerator(Enumerator* enumerator)
		{
			if (vectorEnumerator == nullptr)
			{
				vectorEnumerator = new vector<Enumerator*>();
			}
			vectorEnumerator->push_back(enumerator);
		}
	};
}
