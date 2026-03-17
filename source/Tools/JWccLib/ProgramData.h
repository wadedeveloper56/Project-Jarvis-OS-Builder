#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"
#include "ExternalDeclaration.h"
#include "BaseCodeGenerator.h"

using namespace std;

namespace WadeSpace
{
	class BaseCodeGenerator;

	class ProgramData
	{
	public:
		ProgramData();
		virtual ~ProgramData();
		void add(ExternalDeclaration* data) const;
		BaseCodeGenerator* processGlobalVariables();

	private:
		void handleDeclaration(Declaration const* declaration, vector<struct _VariableData*>* variableTable);
		void handleFunction(FunctionDefinition const* declaration, vector<struct _FunctionData*>* functionTable);
		ParameterTypeList* getDeclarationParameterList(vector<InitDeclarator*> const * initDeclaratorsList);
		TokenType getFunctionParameterType(ParameterDeclaration* parameterDeclaration);
		string getParameterDeclarationName(ParameterDeclaration const * parameterDeclaration);
		TokenType getDeclarationSpecifiersType(DeclarationSpecifiers const * declaration_specifiers);
		TypeSpecifier* findType(Declaration* decl);

	public:
		[[nodiscard]] vector<ExternalDeclaration*>* getProgram() const;
		[[nodiscard]] BaseCodeGenerator* getGenerator() const;

		[[nodiscard]] bool hasProgram() const;
		[[nodiscard]] bool hasGenerator() const;

	private:
		vector<ExternalDeclaration*> *program;
		BaseCodeGenerator* generator;
	};
}
