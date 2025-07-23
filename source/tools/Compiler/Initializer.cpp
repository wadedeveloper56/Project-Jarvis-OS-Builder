#include "Initializer.h"

using namespace WadeSpace;

Initializer::Initializer(AssignmentExpression* exp) : exp(exp), list(nullptr)
{
}

Initializer::Initializer(vector<Initializer*>* list) : exp(nullptr), list(list)
{
}

Initializer::Initializer() : exp(nullptr), list(nullptr)
{
}

Initializer::~Initializer()
{
	delete exp;
	for (Initializer* ptr : *list)
	{
		delete ptr;
	}
	delete list;
}
