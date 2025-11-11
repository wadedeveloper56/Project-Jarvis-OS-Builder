#include "pch.h"
#include "framework.h"
#include "BinaryFormat.h"

DOSOBJFilePtr loadDOSObjFile(FileType fileType, char* buffer, LONGLONG fileSize)
{
	bool done = false;
	int offset = 0;
	unsigned char rectype;
	unsigned long reclength;

	DOSOBJFilePtr ptr = new DOSOBJFile();
	while (!done)
	{
		DOSOBJRecordPtr record = new DOSOBJRecord();
		rectype = buffer[offset];
		reclength = ((unsigned char)buffer[offset + 1]) + (256 * (unsigned char)buffer[offset + 2]);
		record->rectype = rectype;
		record->reclength = reclength;
		record->buffer = new unsigned char[reclength];
		memset(record->buffer, 0, reclength);
		for (int i = 0; i < reclength; i++) record->buffer[i] = buffer[offset + 3 + i];
		offset += 3 + reclength;
		if (rectype == (unsigned char)MODEND || rectype == (unsigned char)MODEND32) done = true;
		ptr->records.push_back(record);
	}
	return ptr;
}