#include "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

FileStream::FileStream(const string& filename, vector<string>& files)
	: file(fopen(filename.c_str(), "rb"))
	, lastCh(0)
	, lastStatus(0) {
	if (!file)
	{
		files.push_back(filename);
		throw Output(files, Output::FILE_NOT_FOUND, "File is missing: " + filename);
	}
	init();
}

FileStream::~FileStream() {
	fclose(file);
	file = nullptr;
}

int FileStream::get() {
	lastStatus = lastCh = fgetc(file);
	return lastCh;
}

int FileStream::peek() {
	const int ch = fgetc(file);
	unget_internal(ch);
	return ch;
}

void FileStream::unget() {
	unget_internal(lastCh);
}

bool FileStream::good() {
	return lastStatus != EOF;
}

void FileStream::unget_internal(int ch) {
	if (isUtf16)
	{
		fseek(file, -1, SEEK_CUR);
	}
	else
		ungetc(ch, file);
}