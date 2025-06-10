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

ExpressionListPtr createExpression(char* identifier, VariableType type, VariableSignType sign, Boolean constant) {
	ExpressionListPtr listNode = (ExpressionListPtr)malloc(sizeof(ExpressionList));
	memset(listNode, sizeof(ExpressionList), 0);
	listNode->expression.node.data.identifier = identifier;
	listNode->expression.node.data.type = type;
	listNode->expression.node.data.sign = sign;
	listNode->expression.node.data.constant = constant;
	return listNode;
}

DeclarationPtr createDeclaration(char* identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType, ExpressionListPtr arrayExpression) {
	DeclarationPtr node = (DeclarationPtr)malloc(sizeof(Declaration));
	node->data.identifier = identifier;
	node->data.type = type;
	node->data.sign = sign;
	node->data.storage = storage;
	node->data.declarationType = declarationType;
	node->arrayExpression = arrayExpression;
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
			node->declaration = declaration;
			node->next = NULL;
		}
		ptr->next = node;
	}
	else {
		symbolTable = (DeclarationListPtr)malloc(sizeof(DeclarationList));
		memset(symbolTable, sizeof(DeclarationList), 0);
		if (symbolTable) {
			symbolTable->declaration = declaration;
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
		memset(node, sizeof(DeclarationList), 0);
		node->declaration = declaration;
		node->next = NULL;
		ptr->next = node;
	}
	else {
		functionTable = (DeclarationListPtr)malloc(sizeof(DeclarationList));
		memset(functionTable, sizeof(DeclarationList), 0);
		functionTable->declaration = declaration;
		functionTable->next = NULL;
	}
}

void addToSymbolTable(char* identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType, Boolean constant, ExpressionListPtr arrayExpression) {
	DeclarationPtr declaration = createDeclaration(identifier, type, sign, storage, declarationType, arrayExpression);
	if (declarationType == DECLARATION_VARIABLE) {
		addDeclaration(declaration);
		printDeclaration(declaration);
	}
}

void addToFunctionTable(char* identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType, Boolean constant, ExpressionListPtr arrayExpression) {
	DeclarationPtr declaration = createDeclaration(identifier, type, sign, storage, declarationType, arrayExpression);
	if (declarationType == DECLARATION_FUNCTION) {
		addFunction(declaration);
		printFunction(declaration);
	}
}

void addToExpression(ExpressionListPtrPtr expression, char* identifier, VariableType type, VariableSignType sign, Boolean constant) {
	if (*expression == NULL) {
		*expression = createExpression(identifier, type, sign, constant);
	}
	else {
		ExpressionListPtr ptr = *expression;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = createExpression(identifier, type, sign, constant);
	}
}

CompilerInfoNodePtr createParameterListNode(CompilerInfoNodePtr node) {
	CompilerInfoNodePtr listNode = (CompilerInfoNodePtr)malloc(sizeof(CompilerInfoNode));
	memset(listNode, sizeof(CompilerInfoNode), 0);
	listNode->data.identifier = node->data.identifier;
	listNode->data.type = node->data.type;
	listNode->data.sign = node->data.sign;
	listNode->data.constant = node->data.constant;
	return listNode;
}

void addToPrameterList(ConpilerInfoPtrPtr list, CompilerInfoNodePtr node) {
	if ((*list)->parameterList == NULL) {
		(*list)->parameterList = createParameterListNode(node);
	}
	else {
		CompilerInfoNodePtr ptr = (*list)->parameterList;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = createParameterListNode(node);
	}
}

void printDeclaration(DeclarationPtr declaration) {
	printf("'%d %d %d %d %s' added to symboltable\n", declaration->data.storage, declaration->data.sign, declaration->data.type, declaration->data.declarationType, declaration->data.identifier);
}

void printFunction(DeclarationPtr declaration) {
	printf("'%d %d %d %d %s' added to functiontable\n", declaration->data.storage, declaration->data.sign, declaration->data.type, declaration->data.declarationType, declaration->data.identifier);
}
