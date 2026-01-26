#include "jcc.h"

CTreePtr createCTreeRoot(LabelPtr label)
{
	return NULL;
}

CTreePtr createNULLCTree(void)
{
	return NULL;
}

CTreePtr createCTree1(LabelPtr label, CTreePtr child)
{
	return NULL;
}

CTreePtr createCTree2(LabelPtr label, CTreePtr child1, CTreePtr child2)
{
	return NULL;
}

static LabelPtr _createLabel(LabelType type, void* data) 
{
	return NULL;
}

LabelPtr createTokenLabel(TokenPtr token) 
{
	return NULL;
}

LabelPtr createConstr0Label(LabelConstrType type) 
{
	return NULL;
}

LabelPtr createConstr1Label(LabelConstrType type, TokenPtr t0) 
{
	return NULL;
}

LabelPtr createConstr2Label(LabelConstrType type, TokenPtr t0, TokenPtr t1) 
{
	return NULL;
}

LabelPtr createConstr3Label(LabelConstrType type, TokenPtr t0, TokenPtr t1,TokenPtr t2) 
{
	return NULL;
}

LabelPtr createConstr4Label(LabelConstrType type, TokenPtr t0, TokenPtr t1,TokenPtr t2, TokenPtr t3) 
{
	return NULL;
}

LabelPtr createConstr5Label(LabelConstrType type, TokenPtr t0, TokenPtr t1, TokenPtr t2, TokenPtr t3, TokenPtr t4)
{
	return NULL;
}

SLListPtr transformDecl(DeclInfoPtr decl)
{
	return NULL;
}

DeclInfoPtr addDeclInfoDclrList(DeclInfoPtr decl, SLListPtr list)
{
	return NULL;
}

void zapToken(void* elem)
{
}

SLListPtr createDclrList(DclrPtr elem)
{
	return NULL;
}

SLListPtr addDclrList(SLListPtr list, DclrPtr elem)
{
	return NULL;
}

DeclInfoPtr createStgClassDeclInfo(StgClass stgClass, TokenPtr pos)
{
	return NULL;
}

DclrPtr addDclrInitializer(DclrPtr dclr, TokenPtr equalTok, CTreePtr initializer)
{
	return NULL;
}

DeclInfoPtr createDeclInfoSCALAR(YScalarType tokCode)
{
	return NULL;
}

DeclInfoPtr combine2DeclInfo(DeclInfoPtr d1, DeclInfoPtr d2)
{
	return NULL;
}

DeclInfoPtr createQualifierDeclInfo(TypeQualifier qualifier)
{
	return NULL;
}

