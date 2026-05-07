#include "pch.h"
#include "PreProcessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

StdIStream::StdIStream(istream& istr)
	: istr(istr) {
	assert(istr.good());
	init();
}

int StdIStream::get() {
	return istr.get();
}

int StdIStream::peek() {
	return istr.peek();
}

void StdIStream::unget() {
	istr.unget();
}

bool StdIStream::good() {
	return istr.good();
}