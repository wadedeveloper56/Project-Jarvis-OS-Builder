#include "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

unsigned char TokenList::Stream::readChar() {
	unsigned char ch = static_cast<unsigned char>(get());

	// For UTF-16 encoded files the BOM is 0xfeff/0xfffe. If the
	// character is non-ASCII character then replace it with 0xff
	if (isUtf16)
	{
		const unsigned char ch2 = static_cast<unsigned char>(get());
		const int ch16 = makeUtf16Char(ch, ch2);
		ch = static_cast<unsigned char>(((ch16 >= 0x80) ? 0xff : ch16));
	}

	// Handling of newlines..
	if (ch == '\r')
	{
		ch = '\n';

		int ch2 = get();
		if (isUtf16)
		{
			const int c2 = get();
			ch2 = makeUtf16Char(ch2, c2);
		}

		if (ch2 != '\n')
			ungetChar();
	}

	return ch;
}

unsigned char TokenList::Stream::peekChar() {
	unsigned char ch = static_cast<unsigned char>(peek());

	// For UTF-16 encoded files the BOM is 0xfeff/0xfffe. If the
	// character is non-ASCII character then replace it with 0xff
	if (isUtf16)
	{
		(void)get();
		const unsigned char ch2 = static_cast<unsigned char>(peek());
		unget();
		const int ch16 = makeUtf16Char(ch, ch2);
		ch = static_cast<unsigned char>(((ch16 >= 0x80) ? 0xff : ch16));
	}

	// Handling of newlines..
	if (ch == '\r')
		ch = '\n';

	return ch;
}

void TokenList::Stream::ungetChar() {
	unget();
	if (isUtf16)
		unget();
}

void TokenList::Stream::init() {
	// initialize since we use peek() in getAndSkipBOM()
	isUtf16 = false;
	bom = getAndSkipBOM();
	isUtf16 = (bom == 0xfeff || bom == 0xfffe);
}

int TokenList::Stream::makeUtf16Char(const unsigned char ch, const unsigned char ch2) const {
	return (bom == 0xfeff) ? (ch << 8 | ch2) : (ch2 << 8 | ch);
}

unsigned short TokenList::Stream::getAndSkipBOM() {
	const int ch1 = peek();

	// The UTF-16 BOM is 0xfffe or 0xfeff.
	if (ch1 >= 0xfe)
	{
		(void)get();
		const unsigned short byte = (static_cast<unsigned char>(ch1) << 8);
		if (peek() >= 0xfe)
			return byte | static_cast<unsigned char>(get());
		unget();
		return 0;
	}

	// Skip UTF-8 BOM 0xefbbbf
	if (ch1 == 0xef)
	{
		(void)get();
		if (peek() == 0xbb)
		{
			(void)get();
			if (peek() == 0xbf)
			{
				(void)get();
				return 0;
			}
			unget();
		}
		unget();
	}

	return 0;
}
