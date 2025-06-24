/*******************************************************************************
 * symbol.c: Provides the sub-command mechanism
 *
 * This file is part of the ArgumentsTable library.
 *
 * Copyright (C) 2025 Christopher D. Wade
 * <wade4615@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of STEWART HEITMANN nor the  names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL STEWART HEITMANN BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/
#include "global.h"

ExpressionListPtr createExpression(char* identifier, VariableType type, VariableSignType sign, Boolean constant, Boolean emptyArray) {
	ExpressionListPtr listNode = (ExpressionListPtr)malloc(sizeof(ExpressionList));
	if (listNode) {
		memset(listNode, sizeof(ExpressionList), 0);
		strcpy(listNode->expression.node.data.identifier, identifier);
		listNode->expression.node.data.type = type;
		listNode->expression.node.data.sign = sign;
		listNode->expression.node.data.constant = constant;
		listNode->expression.node.data.pointerLevel = 0;
		listNode->expression.node.data.emptyArray = emptyArray;
		listNode->next = NULL;
	}
	return listNode;
}

DeclarationPtr createDeclaration(int pointerLevel, char* identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType, ExpressionListPtr arrayExpression, ParameterListNodePtr parameterList, Boolean emptyArray) {
	DeclarationPtr node = (DeclarationPtr)malloc(sizeof(Declaration));
	if (node) {
		memset(node, sizeof(Declaration), 0);
		strcpy(node->data.identifier, identifier);
		node->data.type = type;
		node->data.sign = sign;
		node->data.storage = storage;
		node->data.declarationType = declarationType;
		node->arrayExpression = arrayExpression;
		node->data.pointerLevel = pointerLevel;
		node->parameterList = parameterList;
		node->data.emptyArray = emptyArray;
	}
	return node;
}

void addDeclaration(DeclarationPtr declaration) {
	if (symbolTable != NULL) {
		DeclarationListPtr ptr = symbolTable;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		DeclarationListPtr node = (DeclarationListPtr)malloc(sizeof(DeclarationList));
		memset(node, sizeof(DeclarationList), 0);
		if (node) {
			memcpy(&node->declaration, &(*declaration), sizeof(node->declaration));
			node->next = NULL;
		}
		ptr->next = node;
	}
	else {
		symbolTable = (DeclarationListPtr)malloc(sizeof(DeclarationList));
		memset(symbolTable, sizeof(DeclarationList), 0);
		if (symbolTable) {
			memcpy(&symbolTable->declaration, &(*declaration), sizeof(*declaration));
			symbolTable->next = NULL;
		}
	}
}

void addFunction(DeclarationPtr declaration) {
	if (functionTable != NULL) {
		DeclarationListPtr ptr = functionTable;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		DeclarationListPtr node = (DeclarationListPtr)malloc(sizeof(DeclarationList));
		if (node) {
			memset(node, sizeof(DeclarationList), 0);
			memcpy(&node->declaration, &(*declaration), sizeof(*declaration));
			node->next = NULL;
			ptr->next = node;
		}
	}
	else {
		functionTable = (DeclarationListPtr)malloc(sizeof(DeclarationList));
		if (functionTable) {
			memset(functionTable, sizeof(DeclarationList), 0);
			memcpy(&functionTable->declaration, &(*declaration), sizeof(*declaration));
			functionTable->next = NULL;
		}
	}
}

void addToSymbolTable(int pointerLevel, char* identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType, Boolean constant, Boolean emptyArray, ExpressionListPtr arrayExpression) {
	DeclarationPtr declaration = createDeclaration(pointerLevel, identifier, type, sign, storage, declarationType, arrayExpression, NULL, emptyArray);
	if (declarationType == DECLARATION_VARIABLE) {
		addDeclaration(declaration);
		printDeclaration(declaration);
	}
}

void addToFunctionTable(char* identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType, Boolean constant, ExpressionListPtr arrayExpression, ParameterListNodePtr parameterList) {
	DeclarationPtr declaration = createDeclaration(0, identifier, type, sign, storage, declarationType, arrayExpression, parameterList, FALSE);
	if (declarationType == DECLARATION_FUNCTION) {
		addFunction(declaration);
		printFunction(declaration);
	}
}

void addToExpression(ExpressionListPtrPtr expression, char* identifier, VariableType type, VariableSignType sign, Boolean constant) {
	if (*expression == NULL) {
		*expression = createExpression(identifier, type, sign, constant, FALSE);
	}
	else {
		ExpressionListPtr ptr = *expression;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = createExpression(identifier, type, sign, constant, FALSE);
	}
}

void addToExpression2(ExpressionListPtrPtr expression, char* identifier, VariableType type, VariableSignType sign, Boolean constant) {
	if (*expression == NULL) {
		*expression = createExpression(identifier, type, sign, constant, TRUE);
	}
	else {
		ExpressionListPtr ptr = *expression;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = createExpression(identifier, type, sign, constant, TRUE);
	}
}

ParameterListNodePtr createParameterListNode(CompilerInfoPtr node) {
	ParameterListNodePtr listNode = (ParameterListNodePtr)malloc(sizeof(ParameterListNode));
	if (listNode) {
		memset(listNode, sizeof(ParameterListNode), 0);
		memcpy(&listNode->data, &node->data, sizeof(IdentifierData));
		listNode->next = NULL;
		printSize(listNode);

	}
	return listNode;
}

int printSize(ParameterListNodePtr list) {
	int size = 0;
	ParameterListNodePtr ptr = list;
	while (ptr != NULL) {
		ptr = ptr->next;
		size++;
	}
	return size;
}

void addToParameterList(ParameterListNodePtrPtr list, ParameterListNodePtr node) {
	if (*list == NULL) {
		*list = node;
	}
	else {
		ParameterListNodePtr ptr = *list;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = node;
	}
}

void addToParameterList2(ParameterListNodePtrPtr list, CompilerInfoPtr node) {
	if (*list == NULL) {
		*list = createParameterListNode(node);
	}
	else {
		ParameterListNodePtr ptr = *list;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = createParameterListNode(node);
	}
}

void printDeclaration(DeclarationPtr declaration) {
	if (declaration != NULL && declaration->arrayExpression == NULL) {
		printf("'%s %s %s '%s' PL=%d EA=%d' added to symbol table\n", VariableStorageName[declaration->data.storage], VariableSignName[declaration->data.sign], VariableTypeName[declaration->data.type], declaration->data.identifier, declaration->data.pointerLevel, declaration->data.emptyArray);
	}
	else if (declaration != NULL && declaration->arrayExpression != NULL) {
		printf("'%s %s %s '%s[]' PL=%d EA=%d' added to symbol table\n", VariableStorageName[declaration->data.storage], VariableSignName[declaration->data.sign], VariableTypeName[declaration->data.type], declaration->data.identifier, declaration->data.pointerLevel,declaration->data.emptyArray);
	}
}

void printFunction(DeclarationPtr declaration) {
	printf("'%s %s %s '%s' PL=%d EA=%d' added to functiom table\n", VariableStorageName[declaration->data.storage], VariableSignName[declaration->data.sign], VariableTypeName[declaration->data.type], declaration->data.identifier, declaration->data.pointerLevel, declaration->data.emptyArray);
	ParameterListNodePtr ptr = declaration->parameterList;
	while (ptr != NULL) {
		printf("      '%s %s %s '%s' PL=%d EA=%d' parameter\n", VariableStorageName[ptr->data.storage], VariableSignName[ptr->data.sign], VariableTypeName[ptr->data.type], ptr->data.identifier,ptr->data.pointerLevel,ptr->data.emptyArray);
		ptr = ptr->next;
	}
}

void printParameterListNode(char* message, ParameterListNodePtr list) {
	if (list != NULL) {
		fprintf(fileLexLog, "'%s %s %s '%s'' => %s\n", VariableStorageName[list->data.storage], VariableSignName[list->data.sign], VariableTypeName[list->data.type], list->data.identifier, message);
	}
	else {
		fprintf(fileLexLog, "%s\n", message);
	}
}

void printCompilerInfoNode(char* message, CompilerInfoPtr list) {
	if (list != NULL) {
		fprintf(fileLexLog, "'%s %s %s '%s' PL=%d' EA=%d => %s\n", VariableStorageName[list->data.storage], VariableSignName[list->data.sign], VariableTypeName[list->data.type], list->data.identifier, list->data.pointerLevel, list->data.emptyArray, message);
	}
	else {
		fprintf(fileLexLog, "%s\n", message);
	}
}
