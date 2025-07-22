#include "ProgramData.h"
#include "ExternalDeclaration.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData()
{
	programData = new vector<ExternalDeclaration*>();
	variableTable = new vector<VariableData*>();
}

ProgramData::~ProgramData()
{
}

void ProgramData::add(ExternalDeclaration* data)
{
	programData->push_back(data);
}

void ProgramData::processGlobalVariables()
{
	for (ExternalDeclaration* ptr : *programData)
	{
		if (ptr->isDeclaration())
		{
			Declaration* declaration = ptr->getDeclaration();
			TokenType type = declaration->getDeclarationSpecifiers()->getTypeSpecifier()->getType();
			for (InitDeclarator* initDecl : *declaration->getVectorInitDeclarator())
			{
				VariableData* data = new VariableData();
				data->name = initDecl->getVariableName();
				data->type = type;
				variableTable->push_back(data);
			}
		}
		else if (ptr->isFunction())
		{
		}
	}
}

void ProgramData::test()
{
	cout << "Number of entries in programData table: " << programData->size() << endl;
	for (VariableData* ptr : *variableTable)
	{
		cout << "  variable = " << ptr->name << " " << ptr->type << endl;
	}
}
