#pragma once

void loadres(FILE* f);
void LoadFIXUP(RelocPtr r, char* buf, long* p);
void EmitLiData(DataBlockPtr p, long segnum, long* ofs);
DataBlockPtr BuildLiData(long* bufofs);
void DestroyLIDATA(DataBlockPtr p);
long loadmod(FILE* objfile);
void loadlib(FILE* libfile, const char* libname);