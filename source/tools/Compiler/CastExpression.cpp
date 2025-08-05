#include "CastExpression.h"
#include "TypeName.h"

using namespace WadeSpace;
using namespace std;

CastExpression::CastExpression(UnaryExpression* ue) : unaryExpression(ue), vectorCastExpressionNode(nullptr)
{
}

void CastExpression::add(TypeName* type)
{
	CastExpressionNodePtr temp = new CastExpressionNode;
	temp->type = type;
	if (vectorCastExpressionNode == nullptr)  vectorCastExpressionNode = new vector<CastExpressionNode*>();
	vectorCastExpressionNode->push_back(temp);

}

CastExpression::CastExpression() : unaryExpression(nullptr), vectorCastExpressionNode(nullptr)
{
}

CastExpression::~CastExpression()
{
	delete unaryExpression;
	if (vectorCastExpressionNode != nullptr)
	{
		for (CastExpressionNode* ptr : *vectorCastExpressionNode)
		{
			delete ptr;
		}
	}
	delete vectorCastExpressionNode;
}

UnaryExpression* CastExpression::getUnaryExpression() const
{
	return unaryExpression;
}

vector<CastExpressionNode*>* CastExpression::getVectorCastExpressionNode() const
{
	return vectorCastExpressionNode;
}
