#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include "TypeQualifier.h"

namespace WadeSpace {
	class Pointer
	{
	public:
		Pointer(std::string value, std::vector<TypeQualifier>* list);
		Pointer(std::string value, std::vector<TypeQualifier>* list, Pointer* ptr);
		Pointer(std::string value, Pointer* ptr);
		Pointer(std::string value);
		Pointer();
		~Pointer();

		std::string getNameStr() const;
		std::vector<TypeQualifier>* getList() const;
		int getLevel() const;
		void inc();
	private:
		std::string nameStr;
		std::vector<TypeQualifier>* list;
		int level;
		Pointer* ptr;
	};
}
