#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include "MasmCodeGenerator.h"
#include "GlobalVars.h"
#include "Initializer.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

MasmCodeGenerator::MasmCodeGenerator(vector<VariableData*>* variableTable, vector<FunctionData*>* functionTable)
	: BaseCodeGenerator(variableTable, functionTable)
{
}

MasmCodeGenerator::~MasmCodeGenerator()
{
	for (FunctionData* ptr : *functionTable)
	{
		for (VariableData* data : *ptr->parameters)
		{
			delete data;
		}
		delete ptr->parameters;
		delete ptr;
	}
	delete functionTable;
	for (VariableData* ptr : *variableTable)
	{
		delete ptr;
	}
	delete variableTable;
}

void MasmCodeGenerator::handleIndividualFunction(ofstream& out, FunctionData* ptr)
{
	if (ptr->parameters != nullptr && !ptr->parameters->empty())
	{
		if (bit64) out << "_" << ptr->name << " PROC C, _argc:DWORD, _argv:QWORD" << endl;
		else if (bit32) out << "_" << ptr->name << " PROC C, _argc:DWORD, _argv:DWORD" << endl;
		else out << "_" << ptr->name << " PROC C, _argc:DWORD, _argv:WORD" << endl;
	}
	else
	{
		out << "_" << ptr->name << " PROC C" << endl;
	}
	out << "\t" << "mov eax, [_argc]" << endl;
	out << "\t" << "xor eax,eax" << endl;
	out << "\tret" << endl;
	out << "_" << ptr->name << " endp" << endl;
}

void MasmCodeGenerator::outputVariable(ofstream& out, _VariableData* ptr)
{
	auto type = ptr->type;
	auto variableName = "_" + ptr->name;
	bool isInitialized = ptr->initializer != nullptr;
	bool isPointer = ptr->pointer;
	bool isArray = ptr->arraySize > 1;
	bool isStruct = type == STRUCT;
	string asmType="";
	if (isPointer)
	{
		if (bit16)      asmType = " WORD ";
		else if (bit32) asmType = " DWORD ";
		else            asmType = " QWORD ";
	}
	else if (type == CHAR)        asmType = " SBYTE ";
	else if (type == BOOL)        asmType = " SBYTE ";
	else if (type == SHORT)       asmType = " SWORD ";
	else if (type == INT)         asmType = " SDWORD ";
	else if (type == LONG)        asmType = " SDWORD ";
	else if (type == FLOAT)       asmType = " SDWORD ";
	else if (type == LONG_LONG)   asmType = " SQWORD ";
	else if (type == DOUBLE)      asmType = " SQWORD ";
	else if (type == LONG_DOUBLE) asmType = " TBYTE ";

	if (!isInitialized)
	{
		if (isStruct)
		{
			auto suSpec = ptr->suSpec;
			auto structName = suSpec->getName()->getSymbolName();
			out << variableName << " " << structName << " <>" << endl;
		}
		else if (isArray)
		{
			out << variableName << asmType << ptr->arraySize << " dup(?)" << endl;
		}
		else
		{
			out << variableName << asmType << " ?" << endl;
		}
	}
	else
	{
		if (ptr->initializer->getAssignmentExpression()->getData()->getConstant()->getIConst() != nullptr)
		{
			long long int value = ptr->initializer->getAssignmentExpression()->getData()->getConstant()->getIConst()->getIntegerConst();
			out << variableName << asmType << value << endl;
		}
		if (ptr->initializer->getAssignmentExpression()->getData()->getConstant()->getFConst() != nullptr)
		{
			long double value = ptr->initializer->getAssignmentExpression()->getData()->getConstant()->getFConst()->getDoubleConst();
			out << variableName << asmType << (long double)value << endl;
		}
	}
}

void MasmCodeGenerator::handleInitializedVariable(ofstream& out, vector<_VariableData*>::value_type ptr)
{
	if (ptr->initializer != nullptr)
	{
		outputVariable(out, ptr);
	}
}

void MasmCodeGenerator::handleUUninitializedVariable(ofstream& out, vector<_VariableData*>::value_type ptr)
{
	if (ptr->initializer == nullptr)
	{
		outputVariable(out, ptr);
	}
}

void MasmCodeGenerator::handleVariableTable(ofstream& out)
{
	out << ".data" << endl;
	for (auto ptr : *variableTable)
	{
		handleInitializedVariable(out, ptr);
	}
	out << ".data?" << endl;
	for (auto ptr : *variableTable)
	{
		handleUUninitializedVariable(out, ptr);
	}
}

void MasmCodeGenerator::handleFunctionTable(ofstream& out)
{
	out << endl << ".code" << endl;
	for (FunctionData* ptr : *functionTable)
	{
		handleIndividualFunction(out, ptr);
	}
}

void MasmCodeGenerator::handleStructs(ofstream& out)
{
	for (auto ptr : *variableTable)
	{
		if (ptr->type == STRUCT)
		{
			auto suSpec = ptr->suSpec;
			auto name = suSpec->getName()->getSymbolName();
			auto vars = suSpec->getVectorStructDeclaration();
			out << name << " STRUCT" << endl;
			for (StructDeclaration* var : *vars)
			{
				auto type = var->getSpecifierQualifierList()->getTypeSpecifier()->getType().value();
				auto structDecl  = var->getVectorStructDeclarator();
				for (auto decl : *structDecl)
				{
					auto varName = decl->getDeclarator()->getDirectDeclarator()->getIdentifier()->getSymbolName();
					if (type == CHAR || type == BOOL) out << "\t" << varName << " SBYTE ?"  << endl;
					else if (type == SHORT) out << "\t" << varName << " SWORD ?"  << endl;
					else if (type == INT) out << "\t" << varName << " SDWORD ?" << endl;
					else if (type == LONG) out << "\t" << varName << " SDWORD ?" << endl;
					else if (type == LONG_LONG) out << "\t" << varName << " SQWORD ?" << endl;
					else if (type == FLOAT) out << "\t" << varName << " SDWORD ?" << endl;
					else if (type == DOUBLE) out << "\t" << varName << " SQWORD ?" << endl;
					else if (type == LONG_DOUBLE) out << "\t" << varName << " TBYTE ?" << endl;
					else if (type == IMAGINARY) out << "\t" << varName << " SQWORD ?" << endl;
					else if (type == COMPLEX) out << "\t" << varName << " TBYTE ?" << endl;
				}
			}
			out << name << " ENDS" << endl;
		}
	}
}

void MasmCodeGenerator::generateCode(ofstream& out)
{
	if (bit16)
	{
		out << ".286" << endl;
		out << ".model small;" << endl;
	}
	else if (bit32)
	{
		out << ".386" << endl;
		out << ".model flat, c;" << endl;
	}
	else
	{
		out << ".x64p" << endl;
		out << ".model flat, c;" << endl;
	}
	out << endl;
	handleStructs(out);
	handleVariableTable(out);
	handleFunctionTable(out);
	out << "end" << endl << endl;;
}

MasmCodeGenerator::MasmCodeGenerator(MasmCodeGenerator&& other) noexcept : BaseCodeGenerator(std::move(other))
{
}

MasmCodeGenerator& MasmCodeGenerator::operator=(const MasmCodeGenerator& other)
{
	if (this == &other)
		return *this;
	BaseCodeGenerator::operator =(other);
	return *this;
}

MasmCodeGenerator& MasmCodeGenerator::operator=(MasmCodeGenerator&& other) noexcept
{
	if (this == &other)
		return *this;
	BaseCodeGenerator::operator =(std::move(other));
	return *this;
}
