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

MasmCodeGenerator::MasmCodeGenerator() :BaseCodeGenerator() {

}

MasmCodeGenerator::MasmCodeGenerator(vector<VariableData*>* variableTable, vector<FunctionData*>* functionTable)
	: BaseCodeGenerator(variableTable, functionTable)
{
}

MasmCodeGenerator::~MasmCodeGenerator() {
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

void MasmCodeGenerator::generateCode(ofstream& out) 
{
	if (bit16)
	{
		out << ".286" << endl;
		out << ".model small" << endl;
	}
	else if (bit32)
	{
		out << ".386" << endl;
		out << ".model flat, fastcall" << endl;
	}
	else
	{
		out << ".x64p" << endl;
		out << ".model flat, fastcall" << endl;
	}
	out << endl;
	out << ".data" << endl;
	for (auto ptr : *variableTable)
	{
		if (ptr->initializer != nullptr)
		{
			if (ptr->arraySize > 1)
			{
				//fix me
				if (ptr->size == 1)  out << "_" << ptr->name << " SBYTE " << ptr->arraySize << " dup(?)" << endl;
				if (ptr->size == 2)  out << "_" << ptr->name << " SWORD " << ptr->arraySize << " dup(?)" << endl;
				if (ptr->size == 4)  out << "_" << ptr->name << " SDWORD " << ptr->arraySize << " dup(?)" << endl;
				if (ptr->size == 8)  out << "_" << ptr->name << " SQWORD " << ptr->arraySize << " dup(?)" << endl;
				if (ptr->size == 10) out << "_" << ptr->name << " TBYTE " << ptr->arraySize << " dup(?)" << endl;
			}
			else
			{
				if (ptr->initializer->getAssignmentExpression()->getData()->getConstant()->getIConst() != nullptr)
				{
					long long int value = ptr->initializer->getAssignmentExpression()->getData()->getConstant()->getIConst()->data->repr.numericConstant.repr.lIntConst;
					if (ptr->size == 1)  out << "_" << ptr->name << " SBYTE " << value << endl;
					if (ptr->size == 2)  out << "_" << ptr->name << " SWORD " << value << endl;
					if (ptr->size == 4)  out << "_" << ptr->name << " SDWORD " << value << endl;
					if (ptr->size == 8)  out << "_" << ptr->name << " SQWORD " << value << endl;
					if (ptr->size == 10) out << "_" << ptr->name << " TBYTE " << value << endl;
				}
				if (ptr->initializer->getAssignmentExpression()->getData()->getConstant()->getFConst() != nullptr)
				{
					long double value = ptr->initializer->getAssignmentExpression()->getData()->getConstant()->getFConst()->data->repr.numericConstant.repr.lDoubleConst;
					if (ptr->size == 1)  out << "_" << ptr->name << " SBYTE " << fixed << (long double)value << endl;
					if (ptr->size == 2)  out << "_" << ptr->name << " SWORD " << fixed << (long double)value << endl;
					if (ptr->size == 4)  out << "_" << ptr->name << " SDWORD " << fixed << (long double)value << endl;
					if (ptr->size == 8)  out << "_" << ptr->name << " SQWORD " << fixed << (long double)value << endl;
					if (ptr->size == 10) out << "_" << ptr->name << " TBYTE " << fixed << (long double)value << endl;
				}
			}
		}
	}
	out << ".data?" << endl;
	for (auto ptr : *variableTable)
	{
		if (ptr->initializer == nullptr)
		{
			if (ptr->arraySize > 1)
			{
				//fix me:
				if (ptr->size == 1)  out << "_" << ptr->name << " SBYTE " << ptr->arraySize << " dup(?)" << endl;
				if (ptr->size == 2)  out << "_" << ptr->name << " SWORD " << ptr->arraySize << " dup(?)" << endl;
				if (ptr->size == 4)  out << "_" << ptr->name << " SDWORD " << ptr->arraySize << " dup(?)" << endl;
				if (ptr->size == 8)  out << "_" << ptr->name << " SQWORD " << ptr->arraySize << " dup(?)" << endl;
				if (ptr->size == 10) out << "_" << ptr->name << " TBYTE " << ptr->arraySize << " dup(?)" << endl;
			}
			else
			{
				if (ptr->size == 1)  out << "_" << ptr->name << " SBYTE ?" << endl;
				if (ptr->size == 2)  out << "_" << ptr->name << " SWORD ?" << endl;
				if (ptr->size == 4)  out << "_" << ptr->name << " SDWORD ?" << endl;
				if (ptr->size == 8)  out << "_" << ptr->name << " SQWORD ?" << endl;
				if (ptr->size == 10) out << "_" << ptr->name << " TBYTE ?" << endl;
			}
		}
	}
	out << endl << ".code" << endl;
	for (FunctionData* ptr : *functionTable)
	{
		out << "_" << ptr->name << " proc  c" << endl;
		if (bit16)
		{
			out << "xor ax,ax" << endl;
		}
		else
		{
			out << "\t" << "xor eax,eax" << endl;
		}
		out << "\tret" << endl;
		out << "_" << ptr->name << " endp" << endl;
	}
	out << "end" << endl << endl;;
}
