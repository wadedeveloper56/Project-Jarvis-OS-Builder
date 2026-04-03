#include "pch.h"
#include "ProgramData.h"
#include "CompoundStatement.h"
#include "ExpressionTree.h"
#include "ExternalDeclaration.h"
#include "GlobalVars.h"
#include "ParameterTypeList.h"
#include "MasmCodeGenerator.h"
#include "StructOrUnionSpecifier.h"
#include "Compiler.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData()
{
	program = make_shared<vector<shared_ptr<ExternalDeclaration>>>();
	generator = nullptr;
}

void ProgramData::addExternalDeclaration(shared_ptr<ExternalDeclaration> data)
{
	program->push_back(data);
}

TokenType ProgramData::getFunctionParameterType(shared_ptr<ParameterDeclaration> parameterDeclaration)
{
	TokenType type = UNKNOWN;
	auto declaration_specifiers_list = parameterDeclaration->getDeclarationSpecifiers()->getDeclarationSpecifiersNodeList();
	if (declaration_specifiers_list != nullptr)
	{
		for (auto ptr : *declaration_specifiers_list)
		{
			if (ptr->getTypeSpecifier() != nullptr)
			{
				type = ptr->getTypeSpecifier()->getType().value();
			}
		}
	}
	return type;
}

string ProgramData::getParameterDeclarationName(shared_ptr<ParameterDeclaration> parameterDeclaration)
{
	auto direct_declarator = parameterDeclaration->getDeclarator()->getDirectDeclarator();
	if (direct_declarator != nullptr)
	{
		if (direct_declarator->getIdentifier() != nullptr)
		{
			return direct_declarator->getIdentifier()->getSymbolName();
		}
		else if (direct_declarator->getDirectDeclarator() != nullptr && direct_declarator->getDirectDeclarator()->getIdentifier() != nullptr)
		{
			return direct_declarator->getDirectDeclarator()->getIdentifier()->getSymbolName();
		}
	}
	return "";
}

TokenType ProgramData::getDeclarationSpecifiersType(shared_ptr<DeclarationSpecifiers> declaration_specifiers)
{
	TokenType type = UNKNOWN;
	auto type_specifierList = declaration_specifiers->getDeclarationSpecifiersNodeList();
	if (type_specifierList != nullptr)
	{
		for (auto ptr : *type_specifierList)
		{
			if (ptr->getTypeSpecifier() != nullptr)
			{
				type = ptr->getTypeSpecifier()->getType().value();
			}
		}
	}
	return type;
}

void ProgramData::handleFunction(shared_ptr<FunctionDefinition> declaration, shared_ptr<vector<shared_ptr<FunctionData>>> functionTable)
{
	shared_ptr<FunctionData> data = make_shared<FunctionData>();
	auto stmt = declaration->getBaseStatement();
	data->statements = make_shared<BaseStatement>(*stmt);
	shared_ptr<DeclarationSpecifiers> declaration_specifiers = declaration->getDeclarationSpecifiers();
	if (declaration_specifiers != nullptr && declaration_specifiers->getDeclarationSpecifiersNodeList() != nullptr)
	{
		data->type = getDeclarationSpecifiersType(declaration_specifiers);
		shared_ptr<DirectDeclarator> direct_declarator = declaration->getDeclarator()->getDirectDeclarator();
		data->name = direct_declarator->getDirectDeclarator()->getIdentifier()->getSymbolName();
		shared_ptr<ParameterTypeList> parameters = direct_declarator->getParameterTypeList();
		if (parameters != nullptr && !parameters->getVectorParameterDeclaration()->empty())
		{
			data->parameters = make_shared<vector<shared_ptr<VariableData>>>();
			for (shared_ptr<ParameterDeclaration> parameterDeclaration : *parameters->getVectorParameterDeclaration())
			{
				shared_ptr<VariableData> functionData = make_shared<VariableData>();
				functionData->name = getParameterDeclarationName(parameterDeclaration);
				functionData->pointer = parameterDeclaration->getDeclarator()->hasPointer();
				functionData->type = getFunctionParameterType(parameterDeclaration);
				data->parameters->push_back(functionData);
			}
		}
		functionTable->push_back(data);
		//compiler->getFunctionList()->push_back("_"+data->name);
	}
}

shared_ptr<ParameterTypeList> ProgramData::getDeclarationParameterList(shared_ptr<vector<shared_ptr<InitDeclarator>>> initDeclaratorsList)
{
	shared_ptr<ParameterTypeList> plist = nullptr;
	if (initDeclaratorsList != nullptr)
	{
		for (auto node : *initDeclaratorsList)
		{
			auto init_decl = node->getDeclarator()->getDirectDeclarator();
			plist = init_decl->getParameterTypeList();
		}
	}
	return plist;
}

void ProgramData::handleDeclaration(shared_ptr<ExternalDeclaration> declaration, shared_ptr<vector<shared_ptr<VariableData>>> variableTable)
{
/*	TokenType type;
	bool unsign = false;
	string structName;
	shared_ptr<StructOrUnionSpecifier> suSpec = nullptr;
	shared_ptr<ParameterTypeList> plist = nullptr;

	shared_ptr<DeclarationSpecifiers> declSpecifiers = declaration->getDeclarationSpecifiers();
	shared_ptr<vector<shared_ptr<InitDeclarator>>> initDeclaratorsList = declaration->getVectorInitDeclarator();
	plist = getDeclarationParameterList(initDeclaratorsList);
	vector<DeclarationSpecifiersNode*>* list = declSpecifiers->getDeclarationSpecifiersNodeList();
	if (list != nullptr)
	{
		for (auto ptr : *list)
		{
			if (ptr->typeSpecifier)
			{
				TokenType temp = ptr->typeSpecifier->getType().value();
				if (temp == UNSIGNED)
				{
					unsign = true;
				}
				else if (temp == STRUCT || temp == UNION)
				{
					auto declaration_specifiers = declaration->getDeclarationSpecifiers();
					if (declaration_specifiers != nullptr)
					{
						auto declaration_specifiers_list = declaration_specifiers->getDeclarationSpecifiersNodeList();
						if (declaration_specifiers_list != nullptr)
						{
							for (auto ptr : *declaration_specifiers_list)
							{
								auto type_specifier = ptr->typeSpecifier;
								if (type_specifier != nullptr)
								{
									structName = type_specifier->getStructOrUnionSpecifier()->getName()->getSymbolName();
									//map<string, StructOrUnionSpecifier*>* temp = compiler->getStructList();
									//auto typedefEntry = temp->find(structName);
									//if (typedefEntry != temp->end())
									//{
									//	suSpec = typedefEntry->second;
									//}
								}
							}
						}
					}
					type = temp;
				}
				else if (temp == TYPE_NAME)
				{
					vector<DeclarationSpecifiersNode*>* temp2 = ptr->typeSpecifier->getTypedefInfo()->getDeclaration()->getDeclarationSpecifiers()->getDeclarationSpecifiersNodeList();
					for (DeclarationSpecifiersNode* node : *temp2)
					{
						if (node->typeSpecifier != nullptr)
						{
							type = node->typeSpecifier->getType().value();
						}
					}
				}
				else
				{
					type = temp;
				}
			}
		}
	}
	if (initDeclaratorsList != nullptr)
	{
		for (InitDeclarator* initDecl : *initDeclaratorsList)
		{
			Declarator* declarator = initDecl->getDeclarator();
			DirectDeclarator* dd = declarator->getDirectDeclarator();

			VariableData* data = new VariableData();
			data->initializer = nullptr;
			data->arraySize = 1;
			data->type = type;
			data->pointer = declarator->hasPointer();
			data->name = initDecl->getVariableName();
			data->unsign = unsign;
			data->plist = plist;

			if (type == STRUCT || type == UNION)
			{
				data->structName = structName;
				data->suSpec = suSpec ? new StructOrUnionSpecifier(*suSpec) : nullptr;
			}
			if (initDecl->hasInitializer()) data->initializer = new Initializer(*initDecl->getInitializer());
			if (dd->hasConstantExpression()) data->arraySize = dd->getConstantExpression()->getData()->getConstant()->getIConst()->getIntegerConst();
			variableTable->push_back(data);
		}
	}*/
}

shared_ptr<TypeSpecifier> ProgramData::findType(shared_ptr<Declaration> decl)
{
	auto specifiers = decl->getDeclarationSpecifiers();
	auto list = specifiers->getDeclarationSpecifiersNodeList();
	for (auto node : *list)
	{
		if (node->getTypeSpecifier() != nullptr)
		{
			return node->getTypeSpecifier();
		}
	}
	return nullptr;
}

shared_ptr<BaseCodeGenerator> ProgramData::processGlobalVariables()
{
	shared_ptr<vector<shared_ptr<VariableData>>> variableTable = make_shared<vector<shared_ptr<VariableData>>>();
	shared_ptr<vector<shared_ptr<FunctionData>>> functionTable = make_shared<vector<shared_ptr<FunctionData>>>();

	if (program != nullptr)
	{
		for (auto ptr : *program)
		{
			if (ptr->hasDeclaration())
			{
				//handleDeclaration(ptr->getDeclaration(), variableTable);
			}
			else if (ptr->hasFunction())
			{
				handleFunction(ptr->getFunctionDefinition(), functionTable);
			}
		}
	}

	generator = make_shared<MasmCodeGenerator>(variableTable, functionTable);
	return generator;
}
