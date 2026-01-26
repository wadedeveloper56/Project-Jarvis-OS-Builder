#include "jcc.h"

CTreePtr createCTreeRoot(LabelPtr label)
{
	CTreePtr newTree = AllocateMemory(sizeof(CTree));
	newTree->label = label;
	newTree->child1 = NULL;
	newTree->child2 = NULL;
	return newTree;
}

CTreePtr createNULLCTree(void)
{
	return NULL;
}

CTreePtr createCTree1(LabelPtr label, CTreePtr child)
{
	CTreePtr newTree = createCTreeRoot(label);
	newTree->child1 = child;
	return newTree;
}

CTreePtr createCTree2(LabelPtr label, CTreePtr child1, CTreePtr child2)
{
	CTreePtr newTree = createCTreeRoot(label);
	newTree->child1 = child1;
	newTree->child2 = child2;
	return newTree;
}

static LabelPtr _createLabel(LabelType type, void* data) 
{
	LabelPtr newLabel = AllocateMemory(sizeof(Label));
	newLabel->type = type;
	newLabel->repr.data = data;
	return newLabel;
}

LabelPtr createTokenLabel(TokenPtr token) 
{
	return _createLabel(LABT_TOKEN, token);
}

LabelPtr createConstr0Label(LabelConstrType type) 
{
	LabelPtr newLabel = _createLabel(LABT_CONSTRUCT_ROOT, NULL);
	newLabel->repr.constr.type = type;
	newLabel->repr.constr.numTokens = 0;
	return newLabel;
}

LabelPtr createConstr1Label(LabelConstrType type, TokenPtr t0) 
{
	LabelPtr newLabel = _createLabel(LABT_CONSTRUCT_ROOT, NULL);
	newLabel->repr.constr.type = type;
	newLabel->repr.constr.numTokens = 1;
	newLabel->repr.constr.tokens = AllocateMemory(sizeof(Token) * 1);
	newLabel->repr.constr.tokens[0] = t0;
	return newLabel;

}

LabelPtr createConstr2Label(LabelConstrType type, TokenPtr t0, TokenPtr t1) 
{
	LabelPtr newLabel = _createLabel(LABT_CONSTRUCT_ROOT, NULL);
	newLabel->repr.constr.type = type;
	newLabel->repr.constr.numTokens = 2;
	newLabel->repr.constr.tokens = AllocateMemory(sizeof(Token) * 2);
	newLabel->repr.constr.tokens[0] = t0;
	newLabel->repr.constr.tokens[1] = t1;
	return newLabel;
}

LabelPtr createConstr3Label(LabelConstrType type, TokenPtr t0, TokenPtr t1,TokenPtr t2) 
{
	LabelPtr newLabel = _createLabel(LABT_CONSTRUCT_ROOT, NULL);
	newLabel->repr.constr.type = type;
	newLabel->repr.constr.numTokens = 3;
	newLabel->repr.constr.tokens = AllocateMemory(sizeof(Token) * 3);
	newLabel->repr.constr.tokens[0] = t0;
	newLabel->repr.constr.tokens[1] = t1;
	newLabel->repr.constr.tokens[2] = t2;
	return newLabel;
}

LabelPtr createConstr4Label(LabelConstrType type, TokenPtr t0, TokenPtr t1,TokenPtr t2, TokenPtr t3) 
{
	LabelPtr newLabel = _createLabel(LABT_CONSTRUCT_ROOT, NULL);
	newLabel->repr.constr.type = type;
	newLabel->repr.constr.numTokens = 4;
	newLabel->repr.constr.tokens = AllocateMemory(sizeof(Token) * 4);
	newLabel->repr.constr.tokens[0] = t0;
	newLabel->repr.constr.tokens[1] = t1;
	newLabel->repr.constr.tokens[2] = t2;
	newLabel->repr.constr.tokens[3] = t3;
	return newLabel;
}

LabelPtr createConstr5Label(LabelConstrType type, TokenPtr t0, TokenPtr t1, TokenPtr t2, TokenPtr t3, TokenPtr t4)
{
	LabelPtr newLabel = _createLabel(LABT_CONSTRUCT_ROOT, NULL);
	newLabel->repr.constr.type = type;
	newLabel->repr.constr.numTokens = 5;
	newLabel->repr.constr.tokens = AllocateMemory(sizeof(Token) * 5);
	newLabel->repr.constr.tokens[0] = t0;
	newLabel->repr.constr.tokens[1] = t1;
	newLabel->repr.constr.tokens[2] = t2;
	newLabel->repr.constr.tokens[3] = t3;
	newLabel->repr.constr.tokens[4] = t4;
	return newLabel;
}

