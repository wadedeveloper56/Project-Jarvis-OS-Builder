#include "pch.h"
#include "framework.h"
#include "BinaryFormat.h"

using namespace std;

_OBJFile::_OBJFile() :header({ 0 }), symbolTable(nullptr), stringTableSize(0)
{
}

_EXEFile::_EXEFile() :is64(false), dosHeader({ 0 }), Signature(0), FileHeader({ 0 }), OptionalHeader32({ 0 }), OptionalHeader64({ 0 }), exports(nullptr), config32({ 0 }), config64({ 0 })
{
}

_ResourcesEntry::_ResourcesEntry() :entry({ 0 }), isDirectory(0), isString(0)
{
}

_Resources::_Resources() :header({ 0 })
{

}

_Thunk64::_Thunk64() :thunk({ 0 }), ordinalname(nullptr)
{
}

_Thunk32::_Thunk32() :thunk({ 0 }), ordinalname(nullptr)
{
}

_Exports::_Exports() :exports({ 0 }), filename(nullptr)
{
}

_Imports::_Imports() :imports({ 0 }), filename(nullptr)
{
}

_ExportsFunctions::_ExportsFunctions() :filename(nullptr), ordinal(0), entryPoint(0)
{
}

_RelocsEntry::_RelocsEntry() :relocType(0), szRelocType(nullptr)
{
}

_Relocs::_Relocs() :baseReloc({ 0 })
{
}

_DebugEntry::_DebugEntry() :entry({ 0 }), debugFormat(nullptr)
{
}

_Debug::_Debug()
{
}
