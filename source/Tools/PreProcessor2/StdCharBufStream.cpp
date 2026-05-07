#include "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

StdCharBufStream::StdCharBufStream(const unsigned char* str, size_t size)
	: str(str)
	, size(size)
	, pos(0)
	, lastStatus(0) {
	init();
}

int StdCharBufStream::get() {
	if (pos >= size)
		return lastStatus = EOF;
	return str[pos++];
}

int StdCharBufStream::peek() {
	if (pos >= size)
		return lastStatus = EOF;
	return str[pos];
}

void StdCharBufStream::unget() {
	--pos;
}

bool StdCharBufStream::good() {
	return lastStatus != EOF;
}