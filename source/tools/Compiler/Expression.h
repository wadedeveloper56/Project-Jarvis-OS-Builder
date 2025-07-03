#pragma once

#include "Constant.h"

namespace WadeSpace {
	class Expression
	{
	public:
		Expression();
		Expression(Constant* value);
		Expression(std::string& value);
		Expression(std::string& value, Expression* exp);
		~Expression();
	private:
		Constant* cValue;
		std::string sValue;
		Expression* exp;
	};
}

