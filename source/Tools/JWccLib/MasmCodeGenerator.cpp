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

string MasmCodeGenerator::vectorToCommaSeparatedList(const vector<string>& vec)
{
	string result;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		result += vec[i];
		if (i < vec.size() - 1)
		{
			result += ", ";
		}
	}
	return result;
}

string MasmCodeGenerator::getAsmType(TokenType type, bool isPointer, bool isUnsigned)
{
	string asmType;
	if (isPointer)
	{
		if (bit16) asmType = "WORD ";
		else if (bit32) asmType = "DWORD ";
		else asmType = "QWORD ";
	}
	else if (!isUnsigned && type == CHAR) asmType = "SBYTE ";
	else if (!isUnsigned && type == BOOL) asmType = "SBYTE ";
	else if (!isUnsigned && type == SHORT) asmType = "SWORD ";
	else if (!isUnsigned && type == INT) asmType = "SDWORD ";
	else if (!isUnsigned && type == LONG) asmType = "SDWORD ";
	else if (!isUnsigned && type == FLOAT) asmType = "SDWORD ";
	else if (!isUnsigned && type == LONG_LONG) asmType = "SQWORD ";
	else if (!isUnsigned && type == DOUBLE) asmType = "SQWORD ";
	else if (!isUnsigned && type == LONG_DOUBLE) asmType = "TBYTE ";
	else if (isUnsigned && type == CHAR) asmType = "BYTE ";
	else if (isUnsigned && type == BOOL) asmType = "BYTE ";
	else if (isUnsigned && type == SHORT) asmType = "WORD ";
	else if (isUnsigned && type == INT) asmType = "DWORD ";
	else if (isUnsigned && type == LONG) asmType = "DWORD ";
	else if (isUnsigned && type == FLOAT) asmType = "DWORD ";
	else if (isUnsigned && type == LONG_LONG) asmType = "QWORD ";
	else if (isUnsigned && type == DOUBLE) asmType = "QWORD ";
	else if (isUnsigned && type == LONG_DOUBLE) asmType = "TBYTE ";
	return asmType;
}

void MasmCodeGenerator::handleFunctionWithParameters(ofstream& out, string name, vector<VariableData*>* list)
{
	vector<string> paramList;
	for (auto ptr : *list)
	{
		auto type = ptr->type;
		auto variableName = "_" + ptr->name;
		bool isInitialized = ptr->initializer != nullptr;
		bool isPointer = ptr->pointer;
		bool isArray = ptr->arraySize > 1;
		bool isStruct = type == STRUCT || type == UNION;
		bool isUnsigned = ptr->unsign == true;

		string asmType = getAsmType(type, isPointer, isUnsigned);
		paramList.push_back(variableName + ":" + asmType);
	}
	string paramListStr = vectorToCommaSeparatedList(paramList);
	out << "_" << name << " PROC C, " << paramListStr << endl;
}

void MasmCodeGenerator::handleIndividualFunctionStatements(ofstream& out, BaseStatement* statements)
{
	for (BaseStatement* node : *statements->getStatementList())
	{
		if (node->getOp() == expression_statement)
		{
			BaseStatement* base_statement = node->getStatement();
			Expression* exp = base_statement->getExp();
			NodeType nt = exp->getData()->getType();
			if (nt == NT_FUNCTION_CALL)
			{
				vector<Expression*>* parameters = exp->getData()->argumentList;
				string functionName = exp->getLeft()->getData()->getToken3()->getSymbolName();
				out << "\t" << "call _" << functionName << endl;

			}
		}
		else if (node->getOp() == jump_statement)
		{
			BaseStatement* base_statement = node->getStatement();
			TokenType op = base_statement->getOp();
			switch (op)
			{
				case RETURN:
					auto exp = base_statement->getExp();
					if (exp != nullptr && exp->getData() != nullptr && exp->getData()->getConstant() != nullptr)
					{
						out << "\t" << "mov eax," << exp->getData()->getConstant()->getIConst()->getIntegerConst() << endl;
						out << "\tret" << endl;
					}
					break;
			}
		}
	}
}

void MasmCodeGenerator::handleIndividualFunction(ofstream& out, FunctionData* ptr)
{
	auto returnType = ptr->type;
	auto parameters = ptr->parameters;
	auto statements = ptr->statements;
	if (ptr->parameters != nullptr && !ptr->parameters->empty())
	{
		handleFunctionWithParameters(out, ptr->name, ptr->parameters);
	}
	else
	{
		out << "_" << ptr->name << " PROC C" << endl;
	}
	handleIndividualFunctionStatements(out, statements);
	out << "_" << ptr->name << " endp" << endl;
}

void MasmCodeGenerator::outputVariable(ofstream& out, _VariableData* ptr)
{
	auto type = ptr->type;
	auto variableName = "_" + ptr->name;
	bool isInitialized = ptr->initializer != nullptr;
	bool isPointer = ptr->pointer;
	bool isArray = ptr->arraySize > 1;
	bool isStruct = type == STRUCT || type == UNION;
	bool isUnsigned = ptr->unsign == true;

	string asmType = "";
	if (isPointer)
	{
		if (bit16) asmType = " WORD ";
		else if (bit32) asmType = " DWORD ";
		else asmType = " QWORD ";
	}
	else if (!isUnsigned && type == CHAR) asmType = " SBYTE ";
	else if (!isUnsigned && type == BOOL) asmType = " SBYTE ";
	else if (!isUnsigned && type == SHORT) asmType = " SWORD ";
	else if (!isUnsigned && type == INT) asmType = " SDWORD ";
	else if (!isUnsigned && type == LONG) asmType = " SDWORD ";
	else if (!isUnsigned && type == FLOAT) asmType = " SDWORD ";
	else if (!isUnsigned && type == LONG_LONG) asmType = " SQWORD ";
	else if (!isUnsigned && type == DOUBLE) asmType = " SQWORD ";
	else if (!isUnsigned && type == LONG_DOUBLE) asmType = " TBYTE ";
	else if (isUnsigned && type == CHAR) asmType = " BYTE ";
	else if (isUnsigned && type == BOOL) asmType = " BYTE ";
	else if (isUnsigned && type == SHORT) asmType = " WORD ";
	else if (isUnsigned && type == INT) asmType = " DWORD ";
	else if (isUnsigned && type == LONG) asmType = " DWORD ";
	else if (isUnsigned && type == FLOAT) asmType = " DWORD ";
	else if (isUnsigned && type == LONG_LONG) asmType = " QWORD ";
	else if (isUnsigned && type == DOUBLE) asmType = " QWORD ";
	else if (isUnsigned && type == LONG_DOUBLE) asmType = " TBYTE ";

	if (!isInitialized)
	{
		if (isStruct && !isArray)
		{
			auto suSpec = ptr->suSpec;
			auto structName = suSpec->getName()->getSymbolName();
			out << variableName << " " << structName << " <>" << endl;
		}
		else if (!isStruct && isArray)
		{
			out << variableName << asmType << ptr->arraySize << " dup(?)" << endl;
		}
		else if (isStruct && isArray)
		{
			auto suSpec = ptr->suSpec;
			auto structName = suSpec->getName()->getSymbolName();
			out << variableName << " " << structName << " " << ptr->arraySize << " dup(<>)" << endl;
		}
		else
		{
			out << variableName << asmType << " ?" << endl;
		}
	}
	else
	{
		auto constant = ptr->initializer->getAssignmentExpression()->getData()->getConstant();
		if (constant->getIConst() != nullptr)
		{
			long long int value = constant->getIConst()->getIntegerConst();
			out << variableName << asmType << value << endl;
		}
		if (constant->getFConst() != nullptr)
		{
			long double value = constant->getFConst()->getDoubleConst();
			out << variableName << asmType << (long double)value << endl;
		}
	}
}

void MasmCodeGenerator::handleInitializedVariable(ofstream& out, _VariableData* ptr)
{
	if (ptr->initializer != nullptr && ptr->plist == nullptr)
	{
		outputVariable(out, ptr);
	}
}

void MasmCodeGenerator::handleUUninitializedVariable(ofstream& out, _VariableData* ptr)
{
	if (ptr->initializer == nullptr && ptr->plist == nullptr)
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
		if (ptr->type == STRUCT || ptr->type == UNION)
		{
			auto suSpec = ptr->suSpec;
			auto name = suSpec->getName()->getSymbolName();
			auto vars = suSpec->getVectorStructDeclaration();
			out << name << (ptr->type == STRUCT ? " STRUCT" : " UNION") << endl;
			for (StructDeclaration* var : *vars)
			{
				auto type = var->getSpecifierQualifierList()->getTypeSpecifier()->getType().value();
				auto structDecl = var->getVectorStructDeclarator();
				for (auto decl : *structDecl)
				{
					auto varName = decl->getDeclarator()->getDirectDeclarator()->getIdentifier()->getSymbolName();
					if (type == CHAR || type == BOOL) out << "\t" << varName << " SBYTE ?" << endl;
					else if (type == SHORT) out << "\t" << varName << " SWORD ?" << endl;
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

void MasmCodeGenerator::handlePrototype(ofstream& out)
{
	for (auto ptr : *variableTable)
	{
		if (ptr->plist != nullptr)
		{
			auto name = ptr->name;
			out << "extrn _" << name << " : PROC" << endl;
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
	handlePrototype(out);
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
