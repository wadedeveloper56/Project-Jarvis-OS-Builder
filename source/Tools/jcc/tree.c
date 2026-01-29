#include "jcc.h"

static void _zapTokData(TokDataPtr elem) 
{
	if (elem == NULL)
	{
		return;
	}
	if (elem->code == YC_NUMERIC)
	{
		// Nothing to free
	}
	else if (elem->code == YC_STRING)
	{
		FreeMemory(elem->repr.stringConstant.s);
	}
	else if (elem->code == YC_KEYWORD)
	{
		FreeMemory(elem->repr.keyword.string);
	}
	else if (elem->code == YC_SYMBOL)
	{
		FreeMemory(elem->repr.symbol.string);
	}
	FreeMemory(elem);
}

static void _zapToken(void* _elem)
{
	TokenPtr elem = _elem;

	if (elem == NULL)
	{
		return;
	}
	_zapTokData(elem->data);
	FreeMemory(elem);
}

void zapToken(void* elem)  CALL_INTERNAL_zap(Token)

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

DeclarationPtr createDeclaration(DeclarationSpecifiersPtr declSpecifiers, LinkedListPtr initDeclaratorList, StaticAssertDeclarationPtr staticAssertDecl)
{
	DeclarationPtr newDecl = AllocateMemory(sizeof(Declaration));
	newDecl->declSpecifiers = declSpecifiers;
	newDecl->initDeclaratorList = initDeclaratorList;
	newDecl->staticAssertDecl = staticAssertDecl;
	return newDecl;
}

void addListElem(LinkedListPtr pList, void* elem)
{
	LinkedListNodePtr node = AllocateMemory(sizeof(LinkedListNode));
	node->userData = elem;
	node->next = NULL;
	LinkedListNodePtr ptr = pList->list;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = node;
}

LinkedListPtr createList(void) 
{
	LinkedListPtr newList = AllocateMemory(sizeof(LinkedList));
	newList->list = AllocateMemory(sizeof(LinkedListNode));
	return newList;
}

DeclarationSpecifiersPtr createDeclarationSpecifiers1(TokenPtr token, DeclarationSpecifiersPtr tokenList)
{
	if (tokenList == NULL) {
		tokenList = AllocateMemory(sizeof(DeclarationSpecifiers));
		tokenList->tokenList = createList();
	}
	DeclarationSpecifiersNodePtr node = AllocateMemory(sizeof(DeclarationSpecifiersNode));
	node->token = token;
	addListElem(tokenList->tokenList, node);
	return tokenList;
}

DeclarationSpecifiersPtr createDeclarationSpecifiers2(TypeSpecifierPtr typeSpecifier, DeclarationSpecifiersPtr tokenList)
{
	if (tokenList == NULL)
	{
		tokenList = AllocateMemory(sizeof(DeclarationSpecifiers));
		tokenList->tokenList = createList();
	}
	DeclarationSpecifiersNodePtr node = AllocateMemory(sizeof(DeclarationSpecifiersNode));
	node->typeSpecifier = typeSpecifier;
	addListElem(tokenList->tokenList, node);
	return tokenList;
}

TypeSpecifierPtr createTypeSpecifier(TokenPtr token)
{
	TypeSpecifierPtr newTypeSpec = AllocateMemory(sizeof(TypeSpecifier));
	newTypeSpec->specifierToken = token;
	return newTypeSpec;
}

TypeSpecifierPtr createTypeSpecifier2(AtomicTypeSpecifierPtr token)
{
	TypeSpecifierPtr newTypeSpec = AllocateMemory(sizeof(TypeSpecifier));
	newTypeSpec->atomicTypeSpecifier = token;
	return newTypeSpec;
}

TypeSpecifierPtr createTypeSpecifier3(StructOrUnionSpecifierPtr token)
{
	TypeSpecifierPtr newTypeSpec = AllocateMemory(sizeof(TypeSpecifier));
	newTypeSpec->structOrUnionSpecifier = token;
	return newTypeSpec;
}

TypeSpecifierPtr createTypeSpecifier4(EnumSpecifierPtr token)
{
	TypeSpecifierPtr newTypeSpec = AllocateMemory(sizeof(TypeSpecifier));
	newTypeSpec->enumSpecifier = token;
	return newTypeSpec;
}

AtomicTypeSpecifierPtr createAtomicTypeSpecifier(TokenPtr atomicToken, TokenPtr typeNameToken)
{
	AtomicTypeSpecifierPtr newAtomicTypeSpec = AllocateMemory(sizeof(AtomicTypeSpecifier));
	newAtomicTypeSpec->atomicToken = atomicToken;
	newAtomicTypeSpec->typeSpecifier = createTypeSpecifier(typeNameToken);
	return newAtomicTypeSpec;
}

LinkedListPtr createStructDeclarationList(StructDeclarationPtr node, LinkedListPtr list)
{
	if (list == NULL)
	{
		list = createList();
	}
	addListElem(list, node);
	return list;
}

StructDeclarationPtr createStructDeclaration(LinkedListPtr specifierQualifierList, LinkedListPtr structDeclaratorList, StaticAssertDeclarationPtr staticAssertDeclaration)
{
	StructDeclarationPtr newStructDecl = AllocateMemory(sizeof(StructDeclaration));
	newStructDecl->specifierQualifierList = specifierQualifierList;
	newStructDecl->structDeclaratorList = structDeclaratorList;
	newStructDecl->staticAssertDeclarationPtr = staticAssertDeclaration;
	return newStructDecl;
}

LinkedListPtr createSecifierQualifierList(TypeSpecifierPtr typeSpecifier, TokenPtr typeQualifier, LinkedListPtr list)
{
	if (list == NULL)
	{
		list = createList();
	}
	SpecifierQualifierListNodePtr node = AllocateMemory(sizeof(SpecifierQualifierListNode));
	node->typeQualifier = typeQualifier;
	node->typeSpecifier = typeSpecifier;
	addListElem(list, node);
	return list;
}

LinkedListPtr createStructDeclaratorList(StructDeclaratorPtr structDeclarator, LinkedListPtr list)
{
	if (list == NULL)
	{
		list = createList();
	}
	addListElem(list, structDeclarator);
	return list;
}

StructDeclaratorPtr createStructDeclarator(DeclaratorPtr declarator, CTreePtr constExpression)
{
	StructDeclaratorPtr newStructDeclarator = AllocateMemory(sizeof(StructDeclarator));
	newStructDeclarator->declarator = declarator;
	newStructDeclarator->constantExpr = constExpression;
	return newStructDeclarator;
}

StructOrUnionSpecifierPtr createStructOrUnionSpecifier(TokenPtr structOrUnion, TokenPtr identifier, LinkedListPtr list)
{
	StructOrUnionSpecifierPtr newStructOrUnionSpecifier = AllocateMemory(sizeof(StructOrUnionSpecifier));
	newStructOrUnionSpecifier->structOrUnionToken = structOrUnion;
	newStructOrUnionSpecifier->structOrUnionName = identifier;
	newStructOrUnionSpecifier->structDeclarationList = list;
	return newStructOrUnionSpecifier;
}

LinkedListPtr createEnumeratorList(EnumeratorPtr enumerator, LinkedListPtr list)
{
	if (list == NULL)
	{
		list = createList();
	}
	addListElem(list, enumerator);
	return list;
}

EnumeratorPtr createEnumerator(TokenPtr enumeratorName, CTreePtr constExpr)
{
	EnumeratorPtr newEnumerator = AllocateMemory(sizeof(Enumerator));
	newEnumerator->enumeratorName = enumeratorName;
	newEnumerator->constExpr = constExpr;
	return newEnumerator;
}

EnumSpecifierPtr createEnumSpecifier(TokenPtr enumName, LinkedListPtr enumeratorList)
{
	EnumSpecifierPtr newEnumSpecifier = AllocateMemory(sizeof(EnumSpecifier));
	newEnumSpecifier->enumName = enumName;
	newEnumSpecifier->enumeratorList = enumeratorList;
	return newEnumSpecifier;
}

DirectDeclaratorPtr createDirectDeclarator1(TokenPtr identifier)
{
	DirectDeclaratorPtr newDirectDeclarator = AllocateMemory(sizeof(DirectDeclarator));
	newDirectDeclarator->identifier = identifier;
	newDirectDeclarator->directDeclarator = NULL;
	newDirectDeclarator->declarator = NULL;
	newDirectDeclarator->identifierList = NULL;
	newDirectDeclarator->delimStart = NULL;
	newDirectDeclarator->delimEnd = NULL;
	return newDirectDeclarator;
}

DirectDeclaratorPtr createDirectDeclarator2(DirectDeclaratorPtr directDeclarator, DeclaratorPtr declarator)
{
	DirectDeclaratorPtr newDirectDeclarator = AllocateMemory(sizeof(DirectDeclarator));
	newDirectDeclarator->directDeclarator = directDeclarator;
	newDirectDeclarator->declarator = declarator;
	newDirectDeclarator->identifier = NULL;
	newDirectDeclarator->identifierList = NULL;
	newDirectDeclarator->delimStart = NULL;
	newDirectDeclarator->delimEnd = NULL;
	return newDirectDeclarator;
}

