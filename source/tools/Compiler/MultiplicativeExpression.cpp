#include "MultiplicativeExpression.h"

using namespace WadeSpace;
using namespace std;

MultiplicativeExpression::MultiplicativeExpression(CastExpression* castExpression) : castExpression(castExpression), vectorMultiplicativeExpressionNode(nullptr)
{
}

void MultiplicativeExpression::add(const int& op, CastExpression* castExpression)
{
	MultiplicativeExpressionNodePtr temp = new MultiplicativeExpressionNode;
	temp->expression = castExpression;
	temp->op = op;
	if (vectorMultiplicativeExpressionNode == nullptr)  vectorMultiplicativeExpressionNode = new vector<MultiplicativeExpressionNode*>();
	vectorMultiplicativeExpressionNode->push_back(temp);

}

MultiplicativeExpression::MultiplicativeExpression() :vectorMultiplicativeExpressionNode(nullptr), castExpression(nullptr)
{
}

MultiplicativeExpression::~MultiplicativeExpression()
{
	if (vectorMultiplicativeExpressionNode != nullptr) {
		for (MultiplicativeExpressionNode* ptr : *vectorMultiplicativeExpressionNode)
		{
			delete ptr;
		}
	}
    delete vectorMultiplicativeExpressionNode;
    delete castExpression;
}

CastExpression* MultiplicativeExpression::getCastExpression() const
{
	return castExpression;
}
