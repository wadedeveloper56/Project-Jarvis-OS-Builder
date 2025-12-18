#include "pch.h"
#include "SpillFile.h"
#include "FileSubsystem.h"

SpillFile::SpillFile(FileSubsystem* file)
{
	this->file = file;
	TFileName = nullptr;
	TmpFSize = 0;
}

SpillFile::~SpillFile()
{
}