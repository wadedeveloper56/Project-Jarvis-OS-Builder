#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "DirectDeclarator.h"

using namespace std;

namespace WadeSpace {
	class DirectDeclaratorProxy
	{
	public:
		DirectDeclaratorProxy(DirectDeclarator* directDeclarator);
		~DirectDeclaratorProxy();
		bool hasDirectDeclarator() const;
		DirectDeclarator* getDirectDeclarator() const;
	private:
		DirectDeclarator* directDeclarator;
	};
}
