#include "pch.h"
#include "ProgramData.h"

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
	this->program = new vector<ExternalDeclaration*>();
	this->generator = nullptr;
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
	/* FIX ME: Handle typedefs 
	data->type = declaration->getDeclarationSpecifiers()->getTypeSpecifier()->getType().value();
	auto direct_declarator = declaration->getDeclarator()->getDirectDeclarator();
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
			TokenType type = parameterDeclaration->getDeclarationSpecifiers()->getTypeSpecifier()->getType().value();
			functionData->pointer = parameterDeclaration->getDeclarator()->isPointer();
			functionData->type = type;
			data->parameters->push_back(functionData);
		}
	}
	functionTable->push_back(data);
	*/
}

void ProgramData::handleDeclaration(Declaration* declaration, vector<VariableData*>* variableTable)
{
	if (declaration != nullptr)
	{
		/* FIX ME: Handle typedefs
		TokenType type = declaration->getType();
		bool unsign = false;
		string structName;
		StructOrUnionSpecifier* suSpec = nullptr;
		if (type == UNSIGNED)
		{
			auto declaration_specifiers = declaration->getDeclarationSpecifiers()->getDeclarationSpecifiers();
			type = declaration_specifiers->getTypeSpecifier()->getType().value();
			unsign = true;
		}
		else if (type == STRUCT)
		{
			auto declaration_specifiers = declaration->getDeclarationSpecifiers();
			if (declaration_specifiers != nullptr)
			{
				auto type_specifier = declaration_specifiers->getTypeSpecifier();
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
		if (declaration->getVectorInitDeclarator() != nullptr)
		{
			for (InitDeclarator* initDecl : *declaration->getVectorInitDeclarator())
			{
				auto declarator = initDecl->getDeclarator();
				DirectDeclarator* dd = declarator->getDirectDeclarator();

				VariableData* data = new VariableData();
				data->initializer = nullptr;
				data->arraySize = 1;
				data->type = type;
				data->pointer = declarator->isPointer();
				data->name = initDecl->getVariableName();
				data->unsign = unsign;

				if (type == STRUCT)
				{
					data->structName = structName;
					data->suSpec = suSpec ? new StructOrUnionSpecifier(*suSpec) : nullptr;
				}
				if (initDecl->isInitializer()) data->initializer = new Initializer(*initDecl->getInitializer());
				if (dd->isConstantExpression()) data->arraySize = dd->getConstantExpression()->getData()->getConstant()->getIConst()->data->repr.numericConstant.repr.lIntConst;
				variableTable->push_back(data);
			}
		}
		*/
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
			if (ptr->isDeclaration())
			{
				handleDeclaration(ptr->getDeclaration(), variableTable);
			}
			else if (ptr->isFunction())
			{
				handleFunction(ptr->getFunction(), functionTable);
			}
		}
	}
	generator = new MasmCodeGenerator(variableTable, functionTable);
	return generator;
}
