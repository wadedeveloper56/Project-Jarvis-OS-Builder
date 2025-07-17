#include "Initializer.h"

using namespace WadeSpace;

Initializer::Initializer(AssignmentExpression* exp) :exp(exp), list(NULL) {}
Initializer::Initializer(vector<Initializer*>* list) :exp(NULL), list(list) {}
Initializer::Initializer() :exp(NULL), list(NULL) {}
Initializer::~Initializer() {}
