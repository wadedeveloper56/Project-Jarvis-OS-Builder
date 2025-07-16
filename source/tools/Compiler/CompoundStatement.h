#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace {
	class CompoundStatement : public BaseStatement
	{
	public:
		CompoundStatement(vector<BaseStatement>& statementList);
		CompoundStatement(vector<Declaration>& declarationList);
		CompoundStatement(vector<BaseStatement>& statementList, vector<Declaration> declarationList);
		CompoundStatement();
		~CompoundStatement();
	};
}
