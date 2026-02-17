#pragma once

#include "BaseStatement.h"
#include "Declaration.h"
#include "Constant.h"
#include "Token.h"
#include "Expression.h"
#include "Pointer.h"
#include "Declaration.h"
#include "DeclarationSpecifiers.h"
#include "Declarator.h"
#include "ParameterDeclaration.h"
#include "StructDeclaration.h"
#include "Token.h"

using namespace std;
using namespace WadeSpace;

Declaration *createDeclaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator);
vector<InitDeclarator*>* createInitDeclaratorList(InitDeclarator* value1, vector<InitDeclarator*>* list);
vector<Expression*>* createArgumentExpressionList(Expression* exp, vector<Expression*>* list);
Expression* createExpression(
	NodeType type,
	TokenPtr token1,
	TokenPtr token2,
	Expression* lexp,
	Expression* exp1,
	Expression* exp2,
	vector<Expression*>* argumentList,
	TokenPtr identifier,
	vector<Initializer*>* initializerList,
	TypeName* typeName,
	TokenPtr token3,

	Expression* left,
	TokenPtr op,
	Expression* right);
Constant* createConstant(const TokenPtr iConst, const TokenPtr fConst, const TokenPtr strConst, const optional<TokenType>& type);
Declarator* createDeclarator(Pointer* pointer, DirectDeclarator* directDeclarator);
DirectDeclarator* createDirectDeclarator(TokenPtr identifier, TokenPtr token1, TokenPtr token2, Declarator* const declarator, DirectDeclarator* const directDeclarator, Expression* const constantExpression, ParameterTypeList* const parameterTypeList, vector<TokenPtr>* const vectorOfStrings);
DeclarationSpecifiers* createDeclarationSpecifiers(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier, DeclarationSpecifiers* const declarationSpecifiers);
StorageClassSpecifier* createStorageClassSpecifier(const TokenPtr token);
Expression* createPrimaryExpression(const TokenPtr identifier, Constant* constant);
vector<Declaration*>* createDeclarationList(Declaration* exp, vector<Declaration*>* list);
InitDeclarator* createInitDeclarator(Declarator* declarator, Initializer* initializer);
vector<StructDeclaration*>* createStructDeclarationList(StructDeclaration* value1, vector<StructDeclaration*>* list);
vector<StructDeclarator*>* createStructDeclaratorList(StructDeclarator* value1, vector<StructDeclarator*>* list);
vector<Enumerator*>* createEnumeratorList(Enumerator* value1, vector<Enumerator*>* list);
vector<TypeQualifier*>* createTypeQualifierList(TypeQualifier* value1, vector<TypeQualifier*>* list);
vector<ParameterDeclaration*>* createParameterList(ParameterDeclaration* value1, vector<ParameterDeclaration*>* list);
vector<TokenPtr>* createIdentifierList(const TokenPtr identifier, vector<TokenPtr>* list);
DirectAbstractDeclarator* createDirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator, vector<DirectAbstractDeclaratorNode*>* list);
DirectAbstractDeclarator* createDirectAbstractDeclarator(DirectAbstractDeclarator* dad, 
                                                         AbstractDeclarator* abstractDeclarator, 
	                                                     ParameterTypeList* parameterTypeList, 
	                                                     Expression* constantExpression, 
	                                                     TokenType type);
vector<Initializer*>* createInitializerList(Initializer* initializer, vector<Initializer*>* list);
vector<BaseStatement*>* createStatementList(BaseStatement* statement, vector<BaseStatement*>* list);

