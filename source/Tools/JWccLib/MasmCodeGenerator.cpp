#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include "MasmCodeGenerator.h"
#include "GlobalVars.h"

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
		out << ".x64" << endl;
		out << ".model flat, fastcall" << endl;
	}
	out << endl;
	out << ".data" << endl;
	out << ".data?" << endl;
	for (VariableData* ptr : *variableTable)
	{
		if (ptr->size == 1)  out << "_" << ptr->name << " db ?" << endl;
		if (ptr->size == 2)  out << "_" << ptr->name << " dw ?" << endl;
		if (ptr->size == 4)  out << "_" << ptr->name << " dd ?" << endl;
		if (ptr->size == 8)  out << "_" << ptr->name << " dq ?" << endl;
		if (ptr->size == 10) out << "_" << ptr->name << " dt ?" << endl;
		if (ptr->size == 16) out << "_" << ptr->name << " db 16 dup(?)" << endl;
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
