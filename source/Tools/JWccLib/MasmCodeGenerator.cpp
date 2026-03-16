#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include "MasmCodeGenerator.h"
#include "GlobalVars.h"
#include "Initializer.h"
#include "ExpressionTree.h"

using namespace WadeSpace;
using namespace std;

MasmCodeGenerator::MasmCodeGenerator(vector<VariableData*>* variableTable, vector<FunctionData*>* functionTable)
	: BaseCodeGenerator(variableTable, functionTable)
{}

MasmCodeGenerator::~MasmCodeGenerator()
{
	if (functionTable != nullptr)
	{
		for (FunctionData* ptr : *functionTable)
		{
			if (ptr->parameters != nullptr)
			{
				for (VariableData* data : *ptr->parameters)
				{
					delete data;
				}
				delete ptr->parameters;
			}
			delete ptr;
		}
		delete functionTable;
	}
	if (variableTable != nullptr)
	{
		for (VariableData* ptr : *variableTable)
		{
			delete ptr;
		}
		delete variableTable;
	}
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

void jumpProcess(ostream& out, TreeNodeData* left, TreeNodeData* right, TreeNodeData* current)
{
	if (current != nullptr)
	{
		if (current->getConstant() != nullptr)
		{
			if (current->getConstant()->hasIConst())
			{
				out << "\t" << "mov eax," << current->getConstant()->getIConst()->getIntegerConst() << endl;
			}
		}
	}
}

void MasmCodeGenerator::handleIndividualFunctionStatements(ofstream& out, BaseStatement const* statements)
{
	for (BaseStatement* node : *statements->getStatementList())
	{
		if (node->getOp() == expression_statement)
		{
			BaseStatement* base_statement = node->getStatement();
			ExpressionTree* exp = base_statement->getExp();
			NodeType nt = exp->getData()->getType();
			if (nt == NT_FUNCTION_CALL)
			{
				vector<ExpressionTree*>* parameters = exp->getData()->getArgumentList();
				string functionName = exp->getLeft()->getData()->getToken3()->getSymbolName();
				vector<string> list;
				if (parameters != nullptr)
				{
					for (ExpressionTree* node2 : *parameters)
					{
						string str = to_string(node2->getData()->getConstant()->getIConst()->getIntegerConst());
						list.push_back(str);
					}
					out << "\t" << "invoke _" << functionName << ", " << vectorToCommaSeparatedList(list) << endl;
				}
				else
				{
					out << "\t" << "invoke _" << functionName << endl;
				}
			}
		}
		else if (node->getOp() == jump_statement)
		{
			BaseStatement* base_statement = node->getStatement();
			TokenType op = base_statement->getOp();
			switch (op)
			{
				case RETURN:
					base_statement->getExp()->evaluate(out, jumpProcess);
					out << "\tret" << endl;
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

string MasmCodeGenerator::convertToAsmType(bool isUnsigned, bool isPointer, TokenType type)
{
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
	return asmType;
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

	string asmType = convertToAsmType(isUnsigned, isPointer, type);

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

void MasmCodeGenerator::handleFunctionTablePrototypes(ofstream& out)
{
	for (FunctionData* ptr : *functionTable)
	{
		auto returnType = ptr->type;
		auto parameters = ptr->parameters;
		auto name = "_" + ptr->name;
		vector<string> paramList;
		if (parameters != nullptr)
		{
			for (auto ptr : *parameters)
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
			out << name << " PROTO C " << paramListStr << ";" << endl;
		}
		else
		{
			out << name << " PROTO C;" << endl;
		}
	}
}

void MasmCodeGenerator::handleFunctionTable(ofstream& out)
{
	out << endl << ".code" << endl;
	handleFunctionTablePrototypes(out);
	for (FunctionData* ptr : *functionTable)
	{
		out << endl;
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
			vector<string> paramList;
			for (ParameterDeclaration* node : *ptr->plist->getVectorParameterDeclaration())
			{
				DeclarationSpecifiers* temp1 = node->getDeclarationSpecifiers();
				Declarator* temp2 = node->getDeclarator();
				vector<DeclarationSpecifiersNode*>* temp3 = temp1->getDeclarationSpecifiersNodeList();

				auto name = temp2->getDirectDeclarator()->getIdentifier()->getSymbolName();
				bool isUnsigned = false;
				TokenType type = UNKNOWN;
				bool isPointer = temp2->hasPointer();

				for (DeclarationSpecifiersNode* node2 : *temp3)
				{
					TokenType temp = node2->typeSpecifier->getType().value();
					if (temp == CHAR || temp == BOOL) type = temp;
					else if (temp == SHORT) type = temp;
					else if (temp == INT) type = temp;
					else if (temp == LONG) type = temp;
					else if (temp == LONG_LONG) type = temp;
					else if (temp == FLOAT) type = temp;
					else if (temp == DOUBLE) type = temp;
					else if (temp == LONG_DOUBLE)  type = temp;
					else if (temp == UNSIGNED) isUnsigned = true;
					else if (temp == SIGNED) isUnsigned = false;
				}
				if (type != UNKNOWN)
				{
					string asmType = convertToAsmType(isUnsigned, isPointer, type);
					paramList.push_back(name + ":" + asmType);
				}
			}
			auto name = "_" + ptr->name;
			string paramListStr = vectorToCommaSeparatedList(paramList);
			vector<string>::iterator it = find(functionList->begin(), functionList->end(), name);
			if (it == functionList->end()) out << "EXTERN " << name << " :PROTO " << paramListStr << ";" << endl;
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
	out << "option casemap : none" << endl;
	out << endl;
	handlePrototype(out);
	out << endl;
	handleStructs(out);
	out << endl;
	handleVariableTable(out);
	handleFunctionTable(out);
	out << "end" << endl << endl;;
}

MasmCodeGenerator::MasmCodeGenerator(MasmCodeGenerator&& other) noexcept : BaseCodeGenerator(std::move(other))
{}

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