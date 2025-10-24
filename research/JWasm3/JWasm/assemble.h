#pragma once

#define EXPQUAL

extern struct module_info      ModuleInfo;

int EXPQUAL AssembleModule(const char* source);
void close_files(void);

