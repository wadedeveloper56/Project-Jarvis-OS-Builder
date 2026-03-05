#include "pch.h"
#include "debug.h"
#include "Expression.h"
#include "ProgramData.h"
#include "GlobalVars.h"
#include "StructOrUnionSpecifier.h"

using namespace std;
using namespace WadeSpace;

void handleStructDefinition(Declaration* declaration)
{
	auto declaration_specifiers = declaration->getDeclarationSpecifiers();
	if (declaration_specifiers != nullptr && declaration_specifiers->hasDeclarationSpecifiersNodeList())
	{
		for (auto node : *declaration_specifiers->getDeclarationSpecifiersNodeList())
		{
			auto type_specifier = node->typeSpecifier;
			if (type_specifier != nullptr && type_specifier->getType().has_value())
			{
				auto token = type_specifier->getType().value();
				if ((token == STRUCT || token == UNION) && type_specifier->getStructOrUnionSpecifier() != nullptr)
				{
					if (structList == nullptr) structList = new map<string, StructOrUnionSpecifier*>();
					StructOrUnionSpecifier* temp = type_specifier->getStructOrUnionSpecifier();
					if (temp->getVectorStructDeclaration() != nullptr)
					{
						string name = temp->getName()->getSymbolName();
						structList->insert({ name, temp });
					}
				}
			}
		}
	}
}

void handleDeclaration(ExternalDeclaration* externalDeclaration)
{
	bool isTypedef = externalDeclaration->isTypedef();
	Declaration* declaration = externalDeclaration->getDeclaration();
	if (declaration != nullptr)
	{
	    handleStructDefinition(declaration);
		if (declaration->getVectorInitDeclarator() != nullptr)
		{
			for (InitDeclarator* initDecl : *declaration->getVectorInitDeclarator())
			{
				DirectDeclarator* dd = initDecl->getDeclarator()->getDirectDeclarator();
				if (dd != nullptr)
				{
					string name;
					if (dd->getIdentifier() != nullptr)
					{
						name = dd->getIdentifier()->getSymbolName();
					}
					else
					{
						name = dd->getDirectDeclarator()->getIdentifier()->getSymbolName();
					}
					if (isTypedef)
					{
						typedefList->insert({ name, externalDeclaration });
					}
				}
			}
		}
	}
	if (!isTypedef) programData->add(externalDeclaration);
}

void createTranslationUnit(ExternalDeclaration* externalDeclaration)
{
	if (programData == nullptr)
	{
		programData = new ProgramData();
	}
	if (typedefList == nullptr)
	{
		typedefList = new map<string, ExternalDeclaration*>();
	}
	if (structList == nullptr)
	{
		structList = new map<string, StructOrUnionSpecifier*>();
	}
	if (externalDeclaration != nullptr && externalDeclaration->hasDeclaration())
	{
		handleDeclaration(externalDeclaration);
	}
	if (externalDeclaration != nullptr && externalDeclaration->hasFunction())
	{
		programData->add(externalDeclaration);
	}
}

vector<BaseStatement*>* createStatementList(BaseStatement* statement, vector<BaseStatement*>* list)
{
	if (list == nullptr)
	{
		list = new vector<BaseStatement*>();
	}
	list->push_back(statement);
	return list;
}

vector<Initializer*>* createInitializerList(Initializer* initializer, vector<Initializer*>* list)
{
	if (list == nullptr)
	{
		list = new vector<Initializer*>();
	}
	list->push_back(initializer);
	return list;
}

DirectAbstractDeclarator* createDirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator,
                                                         vector<DirectAbstractDeclaratorNode*>* list)
{
	return new DirectAbstractDeclarator(abstractDeclarator, list);
}

DirectAbstractDeclarator* createDirectAbstractDeclarator(DirectAbstractDeclarator* dad,
                                                         AbstractDeclarator* abstractDeclarator,
                                                         ParameterTypeList* parameterTypeList,
                                                         Expression* constantExpression, TokenType type)
{
	if (dad != nullptr)
	{
		vector<DirectAbstractDeclaratorNode*>* list = dad->getList();
		DirectAbstractDeclaratorNode* node = new DirectAbstractDeclaratorNode(
			parameterTypeList, constantExpression, type);
		list->push_back(node);
		return new DirectAbstractDeclarator(dad->getAbstractDeclarator(), list);
	}
	else
	{
		vector<DirectAbstractDeclaratorNode*>* list = new vector<DirectAbstractDeclaratorNode*>();
		DirectAbstractDeclaratorNode* node = new DirectAbstractDeclaratorNode(
			parameterTypeList, constantExpression, type);
		list->push_back(node);
		return new DirectAbstractDeclarator(abstractDeclarator, list);
	}
}

vector<TokenPtr>* createIdentifierList(const TokenPtr identifier, vector<TokenPtr>* list)
{
	if (list == nullptr)
	{
		list = new vector<TokenPtr>();
	}
	list->push_back(identifier);
	return list;
}

vector<ParameterDeclaration*>* createParameterList(ParameterDeclaration* value1, vector<ParameterDeclaration*>* list)
{
	if (list == nullptr)
	{
		list = new vector<ParameterDeclaration*>();
	}
	list->push_back(value1);
	return list;
}

vector<TypeQualifier*>* createTypeQualifierList(TypeQualifier* value1, vector<TypeQualifier*>* list)
{
	if (list == nullptr)
	{
		list = new vector<TypeQualifier*>();
	}
	list->push_back(value1);
	return list;
}

vector<Enumerator*>* createEnumeratorList(Enumerator* value1, vector<Enumerator*>* list)
{
	if (list == nullptr)
	{
		list = new vector<Enumerator*>();
	}
	list->push_back(value1);
	return list;
}

vector<StructDeclarator*>* createStructDeclaratorList(StructDeclarator* value1, vector<StructDeclarator*>* list)
{
	if (list == nullptr)
	{
		list = new vector<StructDeclarator*>();
	}
	list->push_back(value1);
	return list;
}

vector<StructDeclaration*>* createStructDeclarationList(StructDeclaration* value1, vector<StructDeclaration*>* list)
{
	if (list == nullptr)
	{
		list = new vector<StructDeclaration*>();
	}
	list->push_back(value1);
	return list;
}

InitDeclarator* createInitDeclarator(Declarator* declarator, Initializer* initializer)
{
	return new InitDeclarator(declarator, initializer);
}

Declaration* createDeclaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator)
{
	return new Declaration(declarationSpecifiers, vectorInitDeclarator);
}

vector<InitDeclarator*>* createInitDeclaratorList(InitDeclarator* value1, vector<InitDeclarator*>* list)
{
	if (list == nullptr)
	{
		list = new vector<InitDeclarator*>();
	}
	list->push_back(value1);
	return list;
}

vector<Expression*>* createArgumentExpressionList(Expression* exp, vector<Expression*>* list)
{
	if (list == nullptr)
	{
		list = new vector<Expression*>();
	}
	list->push_back(exp);
	return list;
}

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
	Constant* constant,
	Expression* left,
	TokenPtr op,
	Expression* right
	)
{
	return new Expression(new NodeData(type, token1, token2, lexp, exp1, exp2, argumentList, identifier,
	                                   initializerList, typeName, token3, constant), left, op, right);
}

Constant* createConstant(const TokenPtr iConst, const TokenPtr fConst, const TokenPtr strConst,
                         const optional<TokenType>& type)
{
	return new Constant(iConst, fConst, strConst, type);
}

Declarator* createDeclarator(Pointer* pointer, DirectDeclarator* directDeclarator)
{
	return new Declarator(pointer, directDeclarator);
}

DirectDeclarator* createDirectDeclarator(TokenPtr identifier, TokenPtr token1, TokenPtr token2,
                                         Declarator* const declarator, DirectDeclarator* const directDeclarator,
                                         Expression* const constantExpression,
                                         ParameterTypeList* const parameterTypeList,
                                         vector<TokenPtr>* const vectorOfStrings)
{
	return new DirectDeclarator(identifier, token1, token2, declarator, directDeclarator, constantExpression,
	                            parameterTypeList, vectorOfStrings);
}

DeclarationSpecifiers* createDeclarationSpecifiers(StorageClassSpecifier* const storageClassSpecifier,
                                                   TypeSpecifier* const typeSpecifier,
                                                   TypeQualifier* const typeQualifier,
                                                   DeclarationSpecifiers* declarationSpecifiers)
{
	auto node = new DeclarationSpecifiersNode(storageClassSpecifier, typeSpecifier, typeQualifier);
	if (declarationSpecifiers != nullptr)
	{
		declarationSpecifiers->addDeclarationSpecifiersNode(storageClassSpecifier, typeSpecifier, typeQualifier);
		return declarationSpecifiers;
	}
	else
	{
		DeclarationSpecifiers* declarationSpecifiers = new DeclarationSpecifiers();
		declarationSpecifiers->addDeclarationSpecifiersNode(storageClassSpecifier, typeSpecifier, typeQualifier);
		return declarationSpecifiers;
	}
}

StorageClassSpecifier* createStorageClassSpecifier(const TokenPtr token)
{
	return new StorageClassSpecifier(token);
}

Expression* createPrimaryExpression(const TokenPtr identifier, Constant* constant)
{
	return createExpression(NT_NONE, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, identifier, constant, nullptr, nullptr, nullptr);
}

vector<Declaration*>* createDeclarationList(Declaration* exp, vector<Declaration*>* list)
{
	if (list == nullptr)
	{
		list = new vector<Declaration*>();
	}
	list->push_back(exp);
	return list;
}
