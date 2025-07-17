#include "ProgramData.h"
#include "ExternalDeclaration.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData() {
	programData = new vector<ExternalDeclaration*>();
	functionTable = new vector<FunctionDefinition*>();
	variableTable = new vector<Declaration*>();

}

ProgramData::~ProgramData() {}

void ProgramData::add(ExternalDeclaration* data) {
	programData->push_back(data);
}

void ProgramData::processGlobalVariables() {
	for (ExternalDeclaration* ptr : *programData) {
		if (ptr->isDeclaration()) variableTable->push_back(ptr->getDeclaration());
		if (ptr->isFunction()) functionTable->push_back(ptr->getFunction());
	}
}

void ProgramData::test() {
	cout << "Number of entries in programData table: " << programData->size() << endl;
	cout << "Number of entries in variable table: " << variableTable->size() << endl;
	cout << "Number of entries in function table: " << functionTable->size() << endl;
}
