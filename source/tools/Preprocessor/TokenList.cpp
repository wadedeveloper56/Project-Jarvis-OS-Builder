#include "pch.h"
#include "simplecpp.h"

using namespace simplecpp;
using namespace std;

extern bool sameline(const Token* tok1, const Token* tok2);

StdIStream::StdIStream(istream& istr) : istr(istr) {
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

StdCharBufStream::StdCharBufStream(const unsigned char* str, size_t size) : str(str), size(size), pos(0), lastStatus(0) {
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

FileStream::FileStream(const string& filename, vector<string>& files) : file(fopen(filename.c_str(), "rb")), lastCh(0), lastStatus(0) {
	if (!file) {
		files.push_back(filename);
		throw simplecpp::Output(files, simplecpp::Output::FILE_NOT_FOUND, "File is missing: " + filename);
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
	// keep lastCh intact
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
	if (isUtf16) {
		// TODO: use ungetc() as well
		// UTF-16 has subsequent unget() calls
		fseek(file, -1, SEEK_CUR);
	}
	else
		ungetc(ch, file);
}

//FileStream::FileStream(const FileStream&) {}

//FileStream& FileStream::operator=(const FileStream&) {}

TokenList::Stream::~Stream() {}

unsigned char TokenList::Stream::readChar() {
	unsigned char ch = static_cast<unsigned char>(get());

	// For UTF-16 encoded files the BOM is 0xfeff/0xfffe. If the
	// character is non-ASCII character then replace it with 0xff
	if (isUtf16) {
		const unsigned char ch2 = static_cast<unsigned char>(get());
		const int ch16 = makeUtf16Char(ch, ch2);
		ch = static_cast<unsigned char>(((ch16 >= 0x80) ? 0xff : ch16));
	}

	// Handling of newlines..
	if (ch == '\r') {
		ch = '\n';

		int ch2 = get();
		if (isUtf16) {
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
	if (isUtf16) {
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
	isUtf16 = false;
	bom = getAndSkipBOM();
	isUtf16 = (bom == 0xfeff || bom == 0xfffe);
}

inline int TokenList::Stream::makeUtf16Char(const unsigned char ch, const unsigned char ch2) const {
	return (bom == 0xfeff) ? (ch << 8 | ch2) : (ch2 << 8 | ch);
}

unsigned short TokenList::Stream::getAndSkipBOM() {
	const int ch1 = peek();

	// The UTF-16 BOM is 0xfffe or 0xfeff.
	if (ch1 >= 0xfe) {
		(void)get();
		const unsigned short byte = (static_cast<unsigned char>(ch1) << 8);
		if (peek() >= 0xfe)
			return byte | static_cast<unsigned char>(get());
		unget();
		return 0;
	}

	// Skip UTF-8 BOM 0xefbbbf
	if (ch1 == 0xef) {
		(void)get();
		if (peek() == 0xbb) {
			(void)get();
			if (peek() == 0xbf) {
				(void)get();
				return 0;
			}
			unget();
		}
		unget();
	}

	return 0;
}


TokenList::TokenList(vector<string>& filenames) : frontToken(nullptr), backToken(nullptr), files(filenames) {}

TokenList::TokenList(istream& istr, vector<string>& filenames, const string& filename, OutputList* outputList)
	: frontToken(nullptr), backToken(nullptr), files(filenames)
{
	StdIStream stream(istr);
	readfile(stream, filename, outputList);
}

TokenList::TokenList(const unsigned char* data, size_t size, vector<string>& filenames, const string& filename, OutputList* outputList)
	: frontToken(nullptr), backToken(nullptr), files(filenames)
{
	StdCharBufStream stream(data, size);
	readfile(stream, filename, outputList);
}

TokenList::TokenList(const char* data, size_t size, vector<string>& filenames, const string& filename, OutputList* outputList)
	: frontToken(nullptr), backToken(nullptr), files(filenames)
{
	StdCharBufStream stream(reinterpret_cast<const unsigned char*>(data), size);
	readfile(stream, filename, outputList);
}

TokenList::TokenList(const string& filename, vector<string>& filenames, OutputList* outputList)
	: frontToken(nullptr), backToken(nullptr), files(filenames)
{
	try {
		FileStream stream(filename, filenames);
		readfile(stream, filename, outputList);
	}
	catch (const Output& e) { // TODO handle extra type of errors
		outputList->push_back(e);
	}
}

TokenList::TokenList(const TokenList& other) : frontToken(nullptr), backToken(nullptr), files(other.files)
{
	*this = other;
}

TokenList::TokenList(TokenList&& other) noexcept : frontToken(nullptr), backToken(nullptr), files(other.files)
{
	*this = move(other);
}

TokenList::~TokenList()
{
	clear();
}

TokenList& TokenList::operator=(const TokenList& other)
{
	if (this != &other) {
		clear();
		files = other.files;
		for (const Token* tok = other.cfront(); tok; tok = tok->next)
			push_back(new Token(*tok));
		sizeOfType = other.sizeOfType;
	}
	return *this;
}

TokenList& TokenList::operator=(TokenList&& other)
{
	if (this != &other) {
		clear();
		frontToken = other.frontToken;
		other.frontToken = nullptr;
		backToken = other.backToken;
		other.backToken = nullptr;
		files = other.files;
		sizeOfType = move(other.sizeOfType);
	}
	return *this;
}

void TokenList::clear()
{
	backToken = nullptr;
	while (frontToken) {
		Token* const next = frontToken->next;
		delete frontToken;
		frontToken = next;
	}
	sizeOfType.clear();
}

void TokenList::push_back(Token* tok)
{
	if (!frontToken)
		frontToken = tok;
	else
		backToken->next = tok;
	tok->previous = backToken;
	backToken = tok;
}

void TokenList::dump() const
{
	cout << stringify() << endl;
}

string TokenList::stringify() const
{
	ostringstream ret;
	Location loc(files);
	for (const Token* tok = cfront(); tok; tok = tok->next) {
		if (tok->location.line < loc.line || tok->location.fileIndex != loc.fileIndex) {
			ret << "\n#line " << tok->location.line << " \"" << tok->location.file() << "\"\n";
			loc = tok->location;
		}

		while (tok->location.line > loc.line) {
			ret << '\n';
			loc.line++;
		}

		if (sameline(tok->previous, tok))
			ret << ' ';

		ret << tok->str();

		loc.adjust(tok->str());
	}

	return ret.str();
}
