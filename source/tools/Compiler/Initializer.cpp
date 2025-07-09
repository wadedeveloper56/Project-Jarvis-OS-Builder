#include "Initializer.h"

using namespace WadeSpace;

Initializer::Initializer(Expression& exp) :exp(exp), list(std::nullopt) {}
Initializer::Initializer(std::vector<Initializer>& list) :exp(std::nullopt), list(list) {}
Initializer::Initializer() :exp(std::nullopt), list(std::nullopt) {}
Initializer::~Initializer() {}
