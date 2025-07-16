#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "FunctionDefinition.h"
#include "Declaration.h"

using namespace std;

namespace WadeSpace {
	class ExternalDeclaration
	{
	public:
		ExternalDeclaration(FunctionDefinition& fd);
		ExternalDeclaration(Declaration& dec);
		ExternalDeclaration();
		~ExternalDeclaration();
	private:
		optional < reference_wrapper < FunctionDefinition>> fd;
		optional < reference_wrapper < Declaration>> dec;
	};
}
