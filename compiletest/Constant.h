#pragma once

#include <string>
#include <vector>
#include <stdint.h>

namespace WadeSpace {
	class Constant
	{
    public:
        Constant(std::uint64_t value);
        Constant(long double value);
        Constant(std::string value);
        Constant();
        ~Constant();

        std::uint64_t integerConstant() const;
        long double floatConstant() const;
        std::string stringConstant() const;

    private:
        std::uint64_t iConst;
        long double fConst;
        std::string strConst;
	};
}
