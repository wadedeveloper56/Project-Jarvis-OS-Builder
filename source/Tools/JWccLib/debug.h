#pragma once

#include "BaseStatement.h"
#include "Declaration.h"
#include "Constant.h"
#include "Token.h"
#include "ExpressionTree.h"
#include "Pointer.h"
#include "DeclarationSpecifiers.h"
#include "Declarator.h"
#include "ExternalDeclaration.h"
#include "ParameterDeclaration.h"
#include "StructDeclaration.h"

using namespace std;
using namespace WadeSpace;

Declaration *createDeclaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator);
vector<InitDeclarator*>* createInitDeclaratorList(InitDeclarator* value1, vector<InitDeclarator*>* list);
vector<ExpressionTree*>* createArgumentExpressionList(ExpressionTree* exp, vector<ExpressionTree*>* list);
ExpressionTree* createExpression(
	NodeType type,
	CTokenPtr token1,
	CTokenPtr token2,
	ExpressionTree* lexp,
	ExpressionTree* exp1,
	ExpressionTree* exp2,
	vector<ExpressionTree*>* argumentList,
	CTokenPtr identifier,
	vector<Initializer*>* initializerList,
	TypeName* typeName,
	CTokenPtr token3,
	Constant* constant,
	ExpressionTree* left,
	CTokenPtr op,
	ExpressionTree* right
);
Constant* createConstant(const CTokenPtr iConst, const CTokenPtr fConst, const CTokenPtr strConst, const optional<TokenType>& type);
Declarator* createDeclarator(Pointer* pointer, DirectDeclarator* directDeclarator);
DirectDeclarator* createDirectDeclarator(CTokenPtr identifier, CTokenPtr token1, CTokenPtr token2, Declarator* const declarator, DirectDeclarator* const directDeclarator, ExpressionTree* const constantExpression, ParameterTypeList* const parameterTypeList, vector<CTokenPtr>* const vectorOfStrings);
DeclarationSpecifiers* createDeclarationSpecifiers(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier, DeclarationSpecifiers* declarationSpecifiers);
StorageClassSpecifier* createStorageClassSpecifier(const CTokenPtr token);
ExpressionTree* createPrimaryExpression(const CTokenPtr identifier, Constant* constant);
vector<Declaration*>* createDeclarationList(Declaration* exp, vector<Declaration*>* list);
InitDeclarator* createInitDeclarator(Declarator* declarator, Initializer* initializer);
vector<StructDeclaration*>* createStructDeclarationList(StructDeclaration* value1, vector<StructDeclaration*>* list);
vector<StructDeclarator*>* createStructDeclaratorList(StructDeclarator* value1, vector<StructDeclarator*>* list);
vector<Enumerator*>* createEnumeratorList(Enumerator* value1, vector<Enumerator*>* list);
vector<TypeQualifier*>* createTypeQualifierList(TypeQualifier* value1, vector<TypeQualifier*>* list);
vector<ParameterDeclaration*>* createParameterList(ParameterDeclaration* value1, vector<ParameterDeclaration*>* list);
vector<CTokenPtr>* createIdentifierList(const CTokenPtr identifier, vector<CTokenPtr>* list);
DirectAbstractDeclarator* createDirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator, vector<DirectAbstractDeclaratorNode*>* list);
DirectAbstractDeclarator* createDirectAbstractDeclarator(DirectAbstractDeclarator* dad, 
                                                         AbstractDeclarator* abstractDeclarator, 
	                                                     ParameterTypeList* parameterTypeList, 
	                                                     ExpressionTree* constantExpression, 
	                                                     TokenType type);
vector<Initializer*>* createInitializerList(Initializer* initializer, vector<Initializer*>* list);
vector<BaseStatement*>* createStatementList(BaseStatement* statement, vector<BaseStatement*>* list);
void createTranslationUnit(ExternalDeclaration* externalDeclaration);
