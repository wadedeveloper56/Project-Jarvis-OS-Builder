#include "pch.h"
#include "ProgramData.h"

#include "CompoundStatement.h"
#include "ExpressionTree.h"
#include "ExternalDeclaration.h"
#include "GlobalVars.h"
#include "ParameterTypeList.h"
#include "MasmCodeGenerator.h"
#include "StructOrUnionSpecifier.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData()
{
	program = new vector<ExternalDeclaration*>();
	generator = nullptr;
}

ProgramData::~ProgramData()
{
	if (program != nullptr)
	{
		program->clear();
		delete program;
	}
	if (generator != nullptr)
	{
		delete generator;
	}
}

void ProgramData::add(ExternalDeclaration* data) const
{
	program->push_back(data);
}

TokenType ProgramData::getFunctionParameterType(ParameterDeclaration* parameterDeclaration)
{
	TokenType type = UNKNOWN;
	auto declaration_specifiers_list = parameterDeclaration->getDeclarationSpecifiers()->getDeclarationSpecifiersNodeList();
	if (declaration_specifiers_list != nullptr)
	{
		for (auto ptr : *declaration_specifiers_list)
		{
			if (ptr->typeSpecifier != nullptr)
			{
				type = ptr->typeSpecifier->getType().value();
			}
		}
	}
	return type;
}

string ProgramData::getParameterDeclarationName(ParameterDeclaration const * parameterDeclaration)
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

TokenType ProgramData::getDeclarationSpecifiersType(DeclarationSpecifiers const* declaration_specifiers)
{
	TokenType type = UNKNOWN;
	auto type_specifierList = declaration_specifiers->getDeclarationSpecifiersNodeList();
	if (type_specifierList != nullptr)
	{
		for (auto ptr : *type_specifierList)
		{
			if (ptr->typeSpecifier != nullptr)
			{
				type = ptr->typeSpecifier->getType().value();
			}
		}
	}
	return type;
}

void ProgramData::handleFunction(FunctionDefinition const * declaration, vector<FunctionData*>* functionTable)
{
	FunctionData* data = new FunctionData();
	data->statements = new BaseStatement(*declaration->getBaseStatement());
	DeclarationSpecifiers* declaration_specifiers = declaration->getDeclarationSpecifiers();
	if (declaration_specifiers != nullptr && declaration_specifiers->getDeclarationSpecifiersNodeList() != nullptr)
	{
		data->type = getDeclarationSpecifiersType(declaration_specifiers);
		DirectDeclarator* direct_declarator = declaration->getDeclarator()->getDirectDeclarator();
		data->name = direct_declarator->getDirectDeclarator()->getIdentifier()->getSymbolName();
		ParameterTypeList* parameters = direct_declarator->getParameterTypeList();
		if (parameters != nullptr && !parameters->getVectorParameterDeclaration()->empty())
		{
			data->parameters = new vector<VariableData*>();
			for (ParameterDeclaration* parameterDeclaration : *parameters->getVectorParameterDeclaration())
			{
				VariableData* functionData = new VariableData();
				functionData->name = getParameterDeclarationName(parameterDeclaration);
				functionData->pointer = parameterDeclaration->getDeclarator()->hasPointer();
				functionData->type = getFunctionParameterType(parameterDeclaration);
				data->parameters->push_back(functionData);
			}
		}
		functionTable->push_back(data);
		compile.getFunctionList()->push_back("_"+data->name);
	}
}

vector<ExternalDeclaration*>* ProgramData::getProgram() const
{
	return program;
}

BaseCodeGenerator* ProgramData::getGenerator() const
{
	return generator;
}

bool ProgramData::hasProgram() const
{
	return program != nullptr;
}

bool ProgramData::hasGenerator() const
{
	return generator != nullptr;
}

ParameterTypeList* ProgramData::getDeclarationParameterList(vector<InitDeclarator*> const * initDeclaratorsList)
{
	ParameterTypeList* plist = nullptr;
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

void ProgramData::handleDeclaration(Declaration const* declaration, vector<VariableData*>* variableTable)
{
	TokenType type;
	bool unsign = false;
	string structName;
	StructOrUnionSpecifier* suSpec = nullptr;
	ParameterTypeList* plist = nullptr;

	DeclarationSpecifiers* declSpecifiers = declaration->getDeclarationSpecifiers();
	vector<InitDeclarator*>* initDeclaratorsList = declaration->getVectorInitDeclarator();
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
									auto typedefEntry = compile.getStructList()->find(structName);
									if (typedefEntry != compile.getStructList()->end())
									{
										suSpec = typedefEntry->second;
									}
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

}

TypeSpecifier* ProgramData::findType(Declaration* decl)
{
	auto specifiers = decl->getDeclarationSpecifiers();
	auto list = specifiers->getDeclarationSpecifiersNodeList();
	for (DeclarationSpecifiersNode* node : *list)
	{
		if (node->typeSpecifier != nullptr)
		{
			return node->typeSpecifier;
		}
	}
	return nullptr;
}

BaseCodeGenerator* ProgramData::processGlobalVariables()
{
	vector<VariableData*>* variableTable = new vector<VariableData*>();
	vector<FunctionData*>* functionTable = new vector<FunctionData*>();

	if (program != nullptr)
	{
		for (ExternalDeclaration* ptr : *program)
		{
			if (ptr->hasDeclaration())
			{
				auto decl = ptr->getDeclaration();
				auto type = findType(decl)->getType().value();
				bool isStruct = type == STRUCT || type == UNION;
				bool hasInitDecl = decl->getVectorInitDeclarator() != nullptr;
				if (!(isStruct && !hasInitDecl))
				{
					handleDeclaration(decl, variableTable);
				}
			}
			else if (ptr->hasFunction())
			{
				handleFunction(ptr->getFunction(), functionTable);
			}
		}
	}

	generator = new MasmCodeGenerator(variableTable, functionTable);
	return generator;
}
