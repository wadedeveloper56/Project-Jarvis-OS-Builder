#include "ProgramData.h"
#include "ExternalDeclaration.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData() {
	programData = new vector<ExternalDeclaration*>();
	variableTable = new vector<VariableData*>();
}

ProgramData::~ProgramData() {}

void ProgramData::add(ExternalDeclaration* data) {
	programData->push_back(data);
}

void ProgramData::processGlobalVariables() {
	for (ExternalDeclaration* ptr : *programData) {
		if (ptr->isDeclaration()) {
			Declaration* declaration = ptr->getDeclaration();
			for (InitDeclarator* initDecl : *declaration->getVectorInitDeclarator()) {
				VariableData* data = new VariableData();
				data->name = initDecl->getDeclarator()->getDirectDeclarator()->getId();
				variableTable->push_back(data);
			}
		}
		else if (ptr->isFunction()) {
		}
	}
}

void ProgramData::test() {
	cout << "Number of entries in programData table: " << programData->size() << endl;
	for (VariableData* ptr : *variableTable) {
		cout << "  variable = " << ptr->name << endl;
	}
	/*
	for (Declaration* ptr : *variableTable) {
		cout << "ptr->getVectorInitDeclarator() = " << showbase << hex << ptr->getVectorInitDeclarator() << endl;
		for (InitDeclarator* ptr2 : *ptr->getVectorInitDeclarator()) {
			cout << "  ptr2->getDeclarator()->getDirectDeclarator()->id = " << ptr2->getDeclarator()->getDirectDeclarator()->getId() << endl;
		}
	}
	*/
}
