#include "pch.h"
#include "Enumerator.h"
#include "ExpressionTree.h"

using namespace WadeSpace;

Enumerator::Enumerator(CTokenPtr identifier, ExpressionTree* constantExpression) : identifier(identifier), constantExpression(constantExpression)
{
}
