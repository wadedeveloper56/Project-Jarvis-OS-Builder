#include "pch.h"
#include "framework.h"
#include "BinaryFormat.h"

using namespace std;

OBJFile::OBJFile() :header({ 0 }), symbolTable(nullptr), stringTableSize(0)
{
}

OBJSectionPtr OBJFile::getSection(int index)
{
	return sectionTable[index];
}

int OBJFile::getSectionTableSize()
{
	return sectionTable.size();
}

void OBJFile::addSection(OBJSectionPtr ptr)
{
	sectionTable.push_back(ptr);
}

int OBJFile::getStringTableSize()
{
	return stringTable.size();
}

void OBJFile::addString(string str)
{
	stringTable.push_back(str);
}

string OBJFile::getString(int index)
{
	return stringTable[index];
}

EXEFile::EXEFile() :is64(false), dosHeader({ 0 }), Signature(0), FileHeader({ 0 }), OptionalHeader32({ 0 }), OptionalHeader64({ 0 })
{
}

int EXEFile::getSectionTableSize()
{
	return sectionTable.size();
}

void EXEFile::addSection(OBJSectionPtr ptr)
{
	sectionTable.push_back(ptr);
}

OBJSectionPtr EXEFile::getSection(int index)
{
	return sectionTable[index];
}

int EXEFile::getImportsTableSize()
{
	return imports.size();
}

void EXEFile::addImport(PIMAGE_IMPORT_DESCRIPTOR ptr) 
{
	imports.push_back(ptr);
}

PIMAGE_IMPORT_DESCRIPTOR EXEFile::getImport(int index)
{
	return imports[index];
}

Resources::Resources() :res({ 0 })
{

}

int Resources::getEntriesSize()
{
	return entries.size();
}

void Resources::addEntry(PIMAGE_RESOURCE_DIRECTORY_ENTRY ptr)
{
	entries.push_back(ptr);
}
