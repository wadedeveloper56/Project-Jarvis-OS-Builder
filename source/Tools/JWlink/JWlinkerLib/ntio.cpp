#include "pch.h"
#include "ntio.h"
#include "Structs.h"
#include "globals.h"
#include "File.h"

unsigned QWrite(f_handle file, void* buffer, unsigned len, char* name)
{
	return WriteFile2(file, buffer, len);
}

void QClose(f_handle file, char* name)
{
	CloseFile2(file);
}

void QDelete(char* name)
{
	remove(name);
}
