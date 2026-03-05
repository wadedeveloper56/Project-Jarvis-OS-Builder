#include "pch.h"
#include "ProgramData.h"

#include "CompoundStatement.h"
#include "Expression.h"
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
		for (auto ptr : *program)
		{
			delete ptr;
		}
		delete program;
	}
}

void ProgramData::add(ExternalDeclaration* data)
{
	program->push_back(data);
}


void ProgramData::handleFunction(FunctionDefinition* declaration, vector<FunctionData*>* functionTable)
{
	FunctionData* data = new FunctionData();
	data->statements = new BaseStatement(*declaration->getBaseStatement());
	DeclarationSpecifiers* declaration_specifiers = declaration->getDeclarationSpecifiers();
	if (declaration_specifiers != nullptr && declaration_specifiers->getDeclarationSpecifiersNodeList() != nullptr)
	{
		auto type_specifierList = declaration_specifiers->getDeclarationSpecifiersNodeList();
		for (auto ptr : *type_specifierList)
		{
			if (ptr->typeSpecifier != nullptr)
			{
				data->type = ptr->typeSpecifier->getType().value();
			}
		}
		DirectDeclarator* direct_declarator = declaration->getDeclarator()->getDirectDeclarator();
		data->name = direct_declarator->getDirectDeclarator()->getIdentifier()->getSymbolName();
		ParameterTypeList* parameters = direct_declarator->getParameterTypeList();
		if (parameters != nullptr && !parameters->getVectorParameterDeclaration()->empty())
		{
			data->parameters = new vector<VariableData*>();
			for (ParameterDeclaration* parameterDeclaration : *parameters->getVectorParameterDeclaration())
			{
				VariableData* functionData = new VariableData();
				auto direct_declarator = parameterDeclaration->getDeclarator()->getDirectDeclarator();
				if (direct_declarator->getIdentifier() != nullptr)
				{
					functionData->name = direct_declarator->getIdentifier()->getSymbolName();
				}
				else
				{
					functionData->name = direct_declarator->getDirectDeclarator()->getIdentifier()->getSymbolName();
				}
				auto declaration_specifiers_list = parameterDeclaration->getDeclarationSpecifiers()->getDeclarationSpecifiersNodeList();
				TokenType type = UNKNOWN;
				for (auto ptr : *declaration_specifiers_list)
				{
					if (ptr->typeSpecifier != nullptr)
					{
						type = ptr->typeSpecifier->getType().value();
					}
				}
				functionData->pointer = parameterDeclaration->getDeclarator()->hasPointer();
				functionData->type = type;
				data->parameters->push_back(functionData);
			}
		}
		functionTable->push_back(data);
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

void ProgramData::handleDeclaration(Declaration* declaration, vector<VariableData*>* variableTable)
{
	if (declaration != nullptr)
	{
		TokenType type;
		bool unsign = false;
		string structName;
		StructOrUnionSpecifier* suSpec = nullptr;

		DeclarationSpecifiers* declSpecifiers = declaration->getDeclarationSpecifiers();
		vector<InitDeclarator*>* initDeclaratorsList = declaration->getVectorInitDeclarator();
		vector<DeclarationSpecifiersNode*>* list = declSpecifiers->getDeclarationSpecifiersNodeList();
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
						for (auto ptr : *declaration_specifiers_list)
						{
							auto type_specifier = ptr->typeSpecifier;
							if (type_specifier != nullptr)
							{
								structName = type_specifier->getStructOrUnionSpecifier()->getName()->getSymbolName();
								auto typedefEntry = structList->find(structName);
								if (typedefEntry != structList->end())
								{
									suSpec = typedefEntry->second;
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
	}
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
				handleDeclaration(ptr->getDeclaration(), variableTable);
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
