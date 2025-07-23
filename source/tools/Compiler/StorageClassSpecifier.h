#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class StorageClassSpecifier
	{
	public:
		StorageClassSpecifier(const string&  value, TokenType type);
		StorageClassSpecifier();
		virtual ~StorageClassSpecifier();

	private:
		string operatorStr;
		TokenType type;
	};
}
