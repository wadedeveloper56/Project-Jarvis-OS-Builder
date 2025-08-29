#include "pch.h"
#include "simplecpp.h"

using namespace simplecpp;
using namespace std;

const string Location::emptyFileName;

Location::Location(const vector<string>& f) : files(f), fileIndex(0), line(1U), col(0U) {}

Location::Location(const Location& loc) : files(loc.files), fileIndex(loc.fileIndex), line(loc.line), col(loc.col) {}

Location& Location::operator=(const Location& other)
{
    if (this != &other) {
        fileIndex = other.fileIndex;
        line = other.line;
        col = other.col;
    }
    return *this;
}

void Location::adjust(const string& str)
{
    if (strpbrk(str.c_str(), "\r\n") == nullptr) {
        col += (unsigned int)str.size();
        return;
    }

    for (size_t i = 0U; i < str.size(); ++i) {
        col++;
        if (str[i] == '\n' || str[i] == '\r') {
            col = 1;
            line++;
            if (str[i] == '\r' && (i + 1) < str.size() && str[i + 1] == '\n')
                ++i;
        }
    }
}

bool Location::operator<(const Location& rhs) const {
    if (fileIndex != rhs.fileIndex)
        return fileIndex < rhs.fileIndex;
    if (line != rhs.line)
        return line < rhs.line;
    return col < rhs.col;
}

bool Location::sameline(const Location& other) const {
    return fileIndex == other.fileIndex && line == other.line;
}

const string& Location::file() const {
    return fileIndex < files.size() ? files[fileIndex] : emptyFileName;
}
