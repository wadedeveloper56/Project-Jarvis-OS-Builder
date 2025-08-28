#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "NasmCodeGenerator.h"
#include "GlobalVars.h"

using namespace WadeSpace;
using namespace std;

NasmCodeGenerator::NasmCodeGenerator() :BaseCodeGenerator() {

}

NasmCodeGenerator::NasmCodeGenerator(vector<VariableData*>* variableTable, vector<FunctionData*>* functionTable, vector<FunctionData*>* functionPrototypeTable)
	: BaseCodeGenerator(variableTable, functionTable, functionPrototypeTable)
{
}

NasmCodeGenerator::~NasmCodeGenerator() {
	for (FunctionData* ptr : *functionPrototypeTable)
	{
		for (VariableData* data : *ptr->parameters)
		{
			delete data;
		}
		delete ptr->parameters;
		delete ptr;
	}
	delete functionPrototypeTable;
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

void NasmCodeGenerator::generateCode(ofstream& out) {
	if (bit16)
		out << "BITS 16" << endl;
	else if (bit32)
		out << "BITS 32" << endl;
	else
		out << "BITS 64" << endl;
	out << "\t" << "SECTION .data" << endl;
	out << "\t" << "SECTION .bss" << endl;
	for (VariableData* ptr : *variableTable)
	{
		if (ptr->size == 1) out << ptr->name << ":  resb 1" << endl;
		if (ptr->size == 2) out << ptr->name << ":  resw 1" << endl;
		if (ptr->size == 4) out << ptr->name << ":  resd 1" << endl;
		if (ptr->size == 8) out << ptr->name << ":  resq 1" << endl;
		if (ptr->size == 10) out << ptr->name << ":  rest 1" << endl;
		if (ptr->size == 16) out << ptr->name << ":  resb 16" << endl;
	}
	out << "\t" << "SECTION .text" << endl;
	for (FunctionData* ptr : *functionTable)
	{
		out << "\t global _" << ptr->name << endl;
		out << "_" << ptr->name << ":" << endl;
		out << "\tret" << endl << endl;
	}
}
