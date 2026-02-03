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

LabelPtr createConstr3Label(LabelConstrType type, TokenPtr t0, TokenPtr t1, TokenPtr t2)
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

LabelPtr createConstr4Label(LabelConstrType type, TokenPtr t0, TokenPtr t1, TokenPtr t2, TokenPtr t3)
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

LabelPtr createConstr5Label(LabelConstrType type, TokenPtr t0, TokenPtr t1, TokenPtr t2, TokenPtr t3, TypeNamePtr t4)
{
	LabelPtr newLabel = _createLabel(LABT_CONSTRUCT_ROOT, NULL);
	newLabel->repr.constr.type = type;
	newLabel->repr.constr.numTokens = 4;
	newLabel->repr.constr.tokens = AllocateMemory(sizeof(Token) * 4);
	newLabel->repr.constr.tokens[0] = t0;
	newLabel->repr.constr.tokens[1] = t1;
	newLabel->repr.constr.tokens[2] = t2;
	newLabel->repr.constr.tokens[3] = t3;
	newLabel->repr.constr.typeName = t4;
	return newLabel;
}

LabelPtr createConstr6Label(LabelConstrType type, TokenPtr t0, TokenPtr t1, LinkedListPtr list)
{
	LabelPtr newLabel = _createLabel(LABT_CONSTRUCT_ROOT, NULL);
	newLabel->repr.constr.type = type;
	newLabel->repr.constr.numTokens = 2;
	newLabel->repr.constr.tokens = AllocateMemory(sizeof(Token) * 2);
	newLabel->repr.constr.tokens[0] = t0;
	newLabel->repr.constr.tokens[1] = t1;
	newLabel->repr.list = list;
	return newLabel;
}

LabelPtr createConstr7Label(LabelConstrType type, TokenPtr t0, TokenPtr t1, TokenPtr t2, TokenPtr t3, TypeNamePtr t4, LinkedListPtr list)
{
	LabelPtr newLabel = _createLabel(LABT_CONSTRUCT_ROOT, NULL);
	newLabel->repr.constr.type = type;
	newLabel->repr.constr.numTokens = 4;
	newLabel->repr.constr.tokens = AllocateMemory(sizeof(Token) * 4);
	newLabel->repr.constr.tokens[0] = t0;
	newLabel->repr.constr.tokens[1] = t1;
	newLabel->repr.constr.tokens[2] = t2;
	newLabel->repr.constr.tokens[3] = t3;
	newLabel->repr.constr.typeName = t4;
	newLabel->repr.list = list;
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

LinkedListPtr createList(void)
{
	LinkedListPtr newList = AllocateMemory(sizeof(LinkedList));
	return newList;
}

void addListElem(LinkedListPtr pList, void* elem)
{
	LinkedListNodePtr node = AllocateMemory(sizeof(LinkedListNode));
	node->userData = elem;
	node->next = NULL;
	if (pList->list == NULL)
	{
		pList->list = node;
		return;
	}
	else
	{
		LinkedListNodePtr ptr = pList->list;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = node;
	}
}

LinkedListPtr combineLists(LinkedListPtr list1, LinkedListPtr list2)
{
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}
	LinkedListNodePtr ptr = list1->list;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = list2->list;
	return list1;
}

DeclarationSpecifiersPtr createDeclarationSpecifiers1(TokenPtr token, DeclarationSpecifiersPtr tokenList)
{
	if (tokenList == NULL)
	{
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

AtomicTypeSpecifierPtr createAtomicTypeSpecifier(TokenPtr atomicToken, TypeNamePtr typeNameToken)
{
	AtomicTypeSpecifierPtr newAtomicTypeSpec = AllocateMemory(sizeof(AtomicTypeSpecifier));
	newAtomicTypeSpec->atomicToken = atomicToken;
	newAtomicTypeSpec->typeName = typeNameToken;
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
	newDirectDeclarator->list = NULL;
	newDirectDeclarator->delimStart = NULL;
	newDirectDeclarator->delimEnd = NULL;
	return newDirectDeclarator;
}

DirectDeclaratorPtr createDirectDeclarator2(DeclaratorPtr declarator)
{
	DirectDeclaratorPtr newDirectDeclarator = AllocateMemory(sizeof(DirectDeclarator));
	newDirectDeclarator->directDeclarator = NULL;
	newDirectDeclarator->declarator = declarator;
	newDirectDeclarator->identifier = NULL;
	newDirectDeclarator->list = NULL;
	newDirectDeclarator->delimStart = NULL;
	newDirectDeclarator->delimEnd = NULL;
	return newDirectDeclarator;
}

DirectDeclaratorPtr createDirectDeclarator3(DirectDeclaratorPtr directDeclarator, TokenPtr delimStart, TokenPtr times, TokenPtr delimEnd)
{
	DirectDeclaratorPtr newDirectDeclarator = AllocateMemory(sizeof(DirectDeclarator));
	newDirectDeclarator->directDeclarator = directDeclarator;
	newDirectDeclarator->delimStart = delimStart;
	newDirectDeclarator->delimEnd = delimEnd;
	newDirectDeclarator->times = times;
	newDirectDeclarator->declarator = NULL;
	newDirectDeclarator->identifier = NULL;
	newDirectDeclarator->list = NULL;
	return newDirectDeclarator;
}

DirectDeclaratorPtr createDirectDeclarator4(DirectDeclaratorPtr directDeclarator, TokenPtr delimStart, ParameterTypeListPtr list, TokenPtr delimEnd)
{
	DirectDeclaratorPtr newDirectDeclarator = AllocateMemory(sizeof(DirectDeclarator));
	newDirectDeclarator->directDeclarator = directDeclarator;
	newDirectDeclarator->delimStart = delimStart;
	newDirectDeclarator->list = list;
	newDirectDeclarator->delimEnd = delimEnd;
	newDirectDeclarator->declarator = NULL;
	newDirectDeclarator->identifier = NULL;
	return newDirectDeclarator;
}

DirectDeclaratorPtr createDirectDeclarator5(DirectDeclaratorPtr directDeclarator, TokenPtr delimStart, LinkedListPtr tqlist, CTreePtr aaisnExp, TokenPtr delimEnd, TokenPtr times, TokenPtr statics)
{
	DirectDeclaratorPtr newDirectDeclarator = AllocateMemory(sizeof(DirectDeclarator));
	newDirectDeclarator->directDeclarator = directDeclarator;
	newDirectDeclarator->delimStart = delimStart;
	newDirectDeclarator->list2 = tqlist;
	newDirectDeclarator->assignExpr = aaisnExp;
	newDirectDeclarator->delimEnd = delimEnd;
	newDirectDeclarator->times = times;
	newDirectDeclarator->statics = statics;
	newDirectDeclarator->declarator = NULL;
	newDirectDeclarator->identifier = NULL;
	return newDirectDeclarator;
}

DirectDeclaratorPtr createDirectDeclarator6(DirectDeclaratorPtr directDeclarator, LinkedListPtr tqlist)
{
	DirectDeclaratorPtr newDirectDeclarator = AllocateMemory(sizeof(DirectDeclarator));
	newDirectDeclarator->directDeclarator = directDeclarator;
	newDirectDeclarator->list2 = tqlist;
	newDirectDeclarator->declarator = NULL;
	newDirectDeclarator->identifier = NULL;
	return newDirectDeclarator;
}

PointerPtr createPointer(PointerPtr ptr, LinkedListPtr list)
{
	PointerPtr newPointer = AllocateMemory(sizeof(Pointer));
	if (ptr != NULL && list != NULL)
	{
		LinkedListPtr temp = combineLists(newPointer->typeQualifierList, ptr->typeQualifierList);
		newPointer->typeQualifierList = temp;
		newPointer->numberOfStars = ptr->numberOfStars + 1;
	}
	else if (ptr != NULL && list == NULL)
	{
		newPointer->typeQualifierList = ptr->typeQualifierList;
		newPointer->numberOfStars = ptr->numberOfStars + 1;
	}
	else if (ptr == NULL && list != NULL)
	{
		newPointer->typeQualifierList = list;
		newPointer->numberOfStars = 1;
	}
	else if (ptr == NULL && list == NULL)
	{
		newPointer->typeQualifierList = NULL;
		newPointer->numberOfStars = 1;
	}
	return newPointer;
}

LinkedListPtr createTypeQualifierList(TokenPtr typeQualifier, LinkedListPtr list)
{
	if (list == NULL)
	{
		list = createList();
	}
	addListElem(list, typeQualifier);
	return list;
}

AbstractDeclaratorPtr creatorAbstractDeclarator(PointerPtr pntr, DirectAbstractDeclaratorPtr dad)
{
	AbstractDeclaratorPtr newAbsDecl = AllocateMemory(sizeof(AbstractDeclarator));
	newAbsDecl->directAbstractDeclarator = dad;
	newAbsDecl->pointerList = pntr;
	return newAbsDecl;
}

ParameterDeclarationPtr createParameterDeclaration(DeclarationSpecifiersPtr ds, DeclaratorPtr decl, AbstractDeclaratorPtr ad)
{
	ParameterDeclarationPtr newParamDecl = AllocateMemory(sizeof(ParameterDeclaration));
	newParamDecl->declSpecifiers = ds;
	newParamDecl->declarator = decl;
	newParamDecl->abstractDeclarator = ad;
	return newParamDecl;
}

LinkedListPtr createParameterList(ParameterDeclarationPtr pd, LinkedListPtr list)
{
	if (list == NULL)
	{
		list = createList();
	}
	addListElem(list, pd);
	return list;
}

ParameterTypeListPtr createParameterTypeList(LinkedListPtr parameterList, bool isVariadic)
{
	ParameterTypeListPtr newParamTypeList = AllocateMemory(sizeof(ParameterTypeList));
	newParamTypeList->parameterList = parameterList;
	newParamTypeList->isVariadic = isVariadic;
	return newParamTypeList;
}

LinkedListPtr createIdentifierList(TokenPtr token, LinkedListPtr list)
{
	if (list == NULL)
	{
		list = createList();
	}
	addListElem(list, token);
	return list;
}

TypeNamePtr createTypeName(LinkedListPtr sql, AbstractDeclaratorPtr ad)
{
	TypeNamePtr newTypeName = AllocateMemory(sizeof(TypeName));
	newTypeName->qualifierList = sql;
	newTypeName->abstractDeclarator = ad;
	return newTypeName;
}

DirectAbstractDeclaratorPtr createDirectAbstractDeclarator(
	DirectAbstractDeclaratorPtr dad,
	TokenPtr delimStart,
	AbstractDeclaratorPtr ad,
	TokenPtr delimEnd,
	TokenPtr times,
	LinkedListPtr list,
	CTreePtr assignExpr, 
	TokenPtr statics,
	ParameterTypeListPtr parameterTypeList
)
{
	DirectAbstractDeclaratorNodePtr node = AllocateMemory(sizeof(DirectAbstractDeclaratorNode));
	node->delimStart = delimStart;
	node->abstractDeclarator = ad;
	node->delimEnd = delimEnd;
	node->list = list;
	node->assignExpr = assignExpr;
	node->times = times;
	node->statics = statics;
	node->parameterTypeList = parameterTypeList;
	if (dad != NULL)
	{
		addListElem(dad->list, node);
		return dad;
	}
	else
	{
		DirectAbstractDeclaratorPtr newDad = AllocateMemory(sizeof(DirectAbstractDeclarator));
		newDad->list = createList();
		addListElem(newDad->list, node);
		return newDad;
	}
}

DesignatorPtr createDesignator(TokenPtr delimStart, CTreePtr assignExpr, TokenPtr delimEnd, TokenPtr dot, TokenPtr identifier)
{
	DesignatorPtr newDesignator = AllocateMemory(sizeof(Designator));
	newDesignator->delimStart = delimStart;
	newDesignator->assignExpr = assignExpr;
	newDesignator->delimEnd = delimEnd;
	newDesignator->dot = dot;
	newDesignator->identifier = identifier;
	return newDesignator;
}

LinkedListPtr createDesignatorList(DesignatorPtr designator, LinkedListPtr list)
{
	if (list == NULL)
	{
		list = createList();
	}
	addListElem(list, designator);
	return list;
}

DesignationPtr createDesignation(LinkedListPtr list, TokenPtr equal)
{
	DesignationPtr newDesignation = AllocateMemory(sizeof(Designation));
	newDesignation->list = list;
	newDesignation->equal = equal;
	return newDesignation;
}

LinkedListPtr createInitializerList(DesignationPtr designation, CTreePtr initializer, LinkedListPtr list)
{
	if (list == NULL)
	{
		list = createList();
	}
	InitializerListNodePtr node = AllocateMemory(sizeof(InitializerListNode));
	node->designation = designation;
	node->initializer = initializer;
	addListElem(list, node);
	return list;
}

StatementPtr createStatement(StatementType type, LabeledStatemntPtr labeledStatement, LinkedListPtr compoundStatement, ExpressionStatementPtr expressionStatement)
{
	StatementPtr node = AllocateMemory(sizeof(Statement));
	node->type = type;
	node->labeledStatemnt = labeledStatement;
	node->compoundStatement = compoundStatement;
	node->expressionStatement = expressionStatement;
	return node;
}

LabeledStatemntPtr createLabeledStatement(TokenPtr id, StatementPtr statement, CTreePtr expr, TokenPtr defaults)
{
	LabeledStatemntPtr node = AllocateMemory(sizeof(LabeledStatemnt));
	node->id = id;
	node->statement = statement;
	node->expr = expr;
	node->defaults = defaults;
	return node;
}

BlockItemPtr createBlockItem(DeclarationPtr decl, StatementPtr statement)
{
	BlockItemPtr node = AllocateMemory(sizeof(BlockItem));
	node->statement = statement;
	node->decl = decl;
	return node;
}

LinkedListPtr createBlockItemList(BlockItemPtr block, LinkedListPtr list)
{
	if (list == NULL)
	{
		list = createList();
	}
	addListElem(list, block);
	return list;
}

ExpressionStatementPtr createExpressionStatement(CTreePtr expr)
{
	ExpressionStatementPtr node = AllocateMemory(sizeof(ExpressionStatement));
	node->exp = expr;
	return node;
}
