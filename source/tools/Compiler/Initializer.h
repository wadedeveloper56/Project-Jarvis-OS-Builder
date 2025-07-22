#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "AssignmentExpression.h"

using namespace std;

namespace WadeSpace
{
	class Initializer
	{
	public:
		Initializer(AssignmentExpression* exp);
		Initializer(vector<Initializer*>* list);
		Initializer();
		virtual ~Initializer();

	private:
		AssignmentExpression* exp;
		vector<Initializer*>* list;
	};
}
