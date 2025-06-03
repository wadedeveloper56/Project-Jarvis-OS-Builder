/*******************************************************************************
 * symbol.c: Provides the sub-command mechanism
 *
 * This file is part of the argtable3 library.
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
 ******************************************************************************/#include "global.h"

DeclarationListPtr symbolTable = NULL;

DeclarationPtr createDeclaration (char *identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType){
 DeclarationPtr node = (DeclarationPtr) malloc(sizeof(Declaration));
 node->identifier = identifier;
 node->type = type;
 node->sign = sign;
 node->storage = storage;
 node->declarationType = declarationType;
 return node;
}

void add(DeclarationPtr declaration){ 
 if (symbolTable!=NULL) {
  DeclarationListPtr ptr = symbolTable;
  while(ptr->next != NULL) {
   ptr = ptr->next;
  }
  DeclarationListPtr node = (DeclarationListPtr) malloc(sizeof(DeclarationList));
  memset(node,sizeof(DeclarationList),0);
  node->var = declaration;
  node->next = NULL;
   
   ptr->next = node;
 } else {
   symbolTable = (DeclarationListPtr) malloc(sizeof(DeclarationList));
   memset(symbolTable,sizeof(DeclarationList),0);
   symbolTable->var = declaration;
   symbolTable->next = NULL;
 }
}

void printDeclaration(DeclarationPtr declaration){
 printf("'%d %d %d %s' added to symboltable\n",declaration->storage,declaration->sign,declaration->type,declaration->identifier);
}

void addToSymbolTable(char *identifier, VariableType type, VariableSignType sign, StorageType storage, DeclarationType declarationType, Boolean constant){
 DeclarationPtr declaration = createDeclaration (identifier, type, sign, storage, declarationType);
 if (declarationType == DECLARATION_VARIABLE) add(declaration);
 printDeclaration(declaration);
}
