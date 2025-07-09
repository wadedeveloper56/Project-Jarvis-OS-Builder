#pragma once

#include <string>
#include <vector>
#include <stdint.h>

typedef enum { NONE, INTEGER_CONSTANT, FLOAT_CONSTANT, STRING_CONSTANT } ConstantType;

namespace WadeSpace {
	class Constant
	{
	public:
		Constant(std::uint64_t value);
		Constant(long double value);
		Constant(std::string value);
		Constant();
		~Constant();
	private:
		std::uint64_t iConst;
		long double fConst;
		std::string strConst;
		ConstantType type;
	};
}
