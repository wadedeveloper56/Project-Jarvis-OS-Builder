#include "ProgramData.h"

using namespace WadeSpace;
using namespace std;

ProgramData::ProgramData() {
	programData = vector<ExternalDeclaration>();
	functionTable = vector<FunctionDefinition>();
	variableTable = vector<Declaration>();

}

ProgramData::~ProgramData() {}

void ProgramData::add(ExternalDeclaration& data) {
	programData.push_back(data);
}

void ProgramData::processGlobalVariables() {
	for (size_t i = 0; i < programData.size(); i++) {
		if (programData[i].isDeclaration()) variableTable.push_back(programData[i].getDeclaration());
		if (programData[i].isFunction()) functionTable.push_back(programData[i].getFunction());
	}
}

void ProgramData::test() {
	cout << "Number of entries in programData table: " << programData.size() << endl;
	cout << "Number of entries in variable table: " << variableTable.size() << endl;
	cout << "Number of entries in function table: " << functionTable.size() << endl;
}
