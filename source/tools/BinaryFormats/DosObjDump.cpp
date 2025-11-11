#include "pch.h"
#include "framework.h"
#include "BinaryFormat.h"

unsigned char buf[65536];

DOSOBJFilePtr loadDOSObjFile(FileType fileType, char* buffer, LONGLONG fileSize)
{
	bool done = false;
	int offset = 0;
	int index = 0;
	unsigned char rectype;
	unsigned long reclength;

	while(!done)
	{
		rectype = buffer[offset];
		reclength = ((unsigned char)buffer[offset + 1]) + (256 * (unsigned char)buffer[offset + 2]);
		memset(buf, 0, sizeof(buf));
		for (int i = 0; i < reclength; i++) buf[i] = buffer[offset + 3 + i];
		printf("Type 0x%02X : length 0x%04lX (%ld)\n", rectype, reclength, reclength);
		hexdump(buf, reclength, offset+3);
		printf("\n");
		offset += 3 + reclength;
		if (rectype==(unsigned char)MODEND) done=true;
	}

	return nullptr;
}