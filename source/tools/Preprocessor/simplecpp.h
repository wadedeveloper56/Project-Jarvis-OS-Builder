#pragma once

#if defined(_WIN32) || defined(__CYGWIN__) || defined(__MINGW32__)
#  define SIMPLECPP_WINDOWS
#endif

#include <cctype>
#include <cstring>
#include <iosfwd>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

//#ifdef _WIN32
//#  ifdef SIMPLECPP_EXPORT
//#    define SIMPLECPP_LIB __declspec(dllexport)
//#  elif defined(SIMPLECPP_IMPORT)
//#    define SIMPLECPP_LIB __declspec(dllimport)
//#  else
//#    define SIMPLECPP_LIB
//#  endif
//#else
#  define SIMPLECPP_LIB
//#endif
//
//#ifdef SIMPLECPP_WINDOWS
//#  include <cstdint>
//#else
//#  include <sys/stat.h>
//#endif
//
//#if defined(_MSC_VER)
//#  pragma warning(push)
//// suppress warnings about "conversion from 'type1' to 'type2', possible loss of data"
//#  pragma warning(disable : 4267)
//#  pragma warning(disable : 4244)
//#endif

using namespace std;

namespace simplecpp {
    /** C code standard */
    enum cstd_t { CUnknown=-1, C89, C99, C11, C17, C23 };

    /** C++ code standard */
    enum cppstd_t { CPPUnknown=-1, CPP03, CPP11, CPP14, CPP17, CPP20, CPP23, CPP26 };

    typedef string TokenString;
    class Macro;
    class FileDataCache;

    class SIMPLECPP_LIB Location {
    public:
        explicit Location(const vector<string>& f);
        Location(const Location& loc);
        Location& operator=(const Location& other);
        void adjust(const string &str);
        bool operator<(const Location& rhs) const;
        bool sameline(const Location & other) const;
        const string& file() const;
        const vector<string> &files;
        unsigned int fileIndex;
        unsigned int line;
        unsigned int col;
    private:
        static const string emptyFileName;
    };

    class SIMPLECPP_LIB Token {
    public:
        Token(const TokenString& s, const Location& loc, bool wsahead = false);
        Token(const Token& tok);
        void flags();
        const TokenString& str() const;
        void setstr(const string& s);;
        bool isOneOf(const char ops[]) const;
        bool startsWithOneOf(const char c[]) const;
        bool endsWithOneOf(const char c[]) const;
        static bool isNumberLike(const string& str);
        TokenString macro;
        char op;
        bool comment;
        bool name;
        bool number;
        bool whitespaceahead;
        Location location;
        Token *previous;
        Token *next;
        mutable const Token *nextcond;
        const Token* previousSkipComments() const;
        const Token* nextSkipComments() const;
        void setExpandedFrom(const Token* tok, const Macro* m);
        bool isExpandedFrom(const Macro* m) const;
        void printAll() const;
        void printOut() const;
    private:
        TokenString string;
        set<const Macro*> mExpandedFrom;
    };

    struct SIMPLECPP_LIB Output {
        enum Type {
            ERROR0, /* #error */ 
            WARNING, /* #warning */
            MISSING_HEADER,
            INCLUDE_NESTED_TOO_DEEPLY,
            SYNTAX_ERROR,
            PORTABILITY_BACKSLASH,
            UNHANDLED_CHAR_ERROR,
            EXPLICIT_INCLUDE_NOT_FOUND,
            FILE_NOT_FOUND,
            DUI_ERROR
        } type;
        explicit Output(const vector<string>& files);
        explicit Output(const vector<string>& files, Type type, const string& msg);
        Location location;
        string msg;
    };

    typedef list<Output> OutputList;

    class SIMPLECPP_LIB TokenList {
    public:
        class Stream;

        explicit TokenList(vector<string> &filenames);
        /** generates a token list from the given istream parameter */
        TokenList(istream &istr, vector<string> &filenames, const string &filename=string(), OutputList *outputList = nullptr);
        /** generates a token list from the given buffer */
        TokenList(const unsigned char* data, size_t size, vector<string> &filenames, const string &filename=string(), OutputList *outputList = nullptr);
        /** generates a token list from the given buffer */
        TokenList(const char* data, size_t size, vector<string> &filenames, const string &filename=string(), OutputList *outputList = nullptr);
        /** generates a token list from the given filename parameter */
        TokenList(const string &filename, vector<string> &filenames, OutputList *outputList = nullptr);
        TokenList(const TokenList &other);
        TokenList(TokenList &&other) noexcept;
        ~TokenList();
        TokenList &operator=(const TokenList &other);
        TokenList &operator=(TokenList &&other);

        void clear();
        bool empty() const {
            return !frontToken;
        }
        void push_back(Token *tok);

        void dump() const;
        string stringify() const;

        void readfile(Stream &stream, const string &filename=string(), OutputList *outputList = nullptr);
        void constFold();

        void removeComments();

        Token *front() {
            return frontToken;
        }

        const Token *cfront() const {
            return frontToken;
        }

        Token *back() {
            return backToken;
        }

        const Token *cback() const {
            return backToken;
        }

        void deleteToken(Token *tok) {
            if (!tok)
                return;
            Token * const prev = tok->previous;
            Token * const next = tok->next;
            if (prev)
                prev->next = next;
            if (next)
                next->previous = prev;
            if (frontToken == tok)
                frontToken = next;
            if (backToken == tok)
                backToken = prev;
            delete tok;
        }

        void takeTokens(TokenList &other) {
            if (!other.frontToken)
                return;
            if (!frontToken) {
                frontToken = other.frontToken;
            } else {
                backToken->next = other.frontToken;
                other.frontToken->previous = backToken;
            }
            backToken = other.backToken;
            other.frontToken = other.backToken = nullptr;
        }

        /** sizeof(T) */
        map<string, size_t> sizeOfType;

        const vector<string>& getFiles() const {
            return files;
        }

    private:
        void combineOperators();

        void constFoldUnaryNotPosNeg(Token *tok);
        void constFoldMulDivRem(Token *tok);
        void constFoldAddSub(Token *tok);
        void constFoldShift(Token *tok);
        void constFoldComparison(Token *tok);
        void constFoldBitwise(Token *tok);
        void constFoldLogicalOp(Token *tok);
        void constFoldQuestionOp(Token **tok1);

        string readUntil(Stream &stream, const Location &location, char start, char end, OutputList *outputList);
        void lineDirective(unsigned int fileIndex, unsigned int line, Location *location);

        string lastLine(int maxsize=1000) const;
        const Token* lastLineTok(int maxsize=1000) const;
        bool isLastLinePreprocessor(int maxsize=1000) const;

        unsigned int fileIndex(const string &filename);

        Token *frontToken;
        Token *backToken;
        vector<string> &files;
    };

    class TokenList::Stream {
    public:
        virtual ~Stream();
        virtual int get() = 0;
        virtual int peek() = 0;
        virtual void unget() = 0;
        virtual bool good() = 0;
        unsigned char readChar();
        unsigned char peekChar();
        void ungetChar();
    protected:
        void init();
    private:
        inline int makeUtf16Char(const unsigned char ch, const unsigned char ch2) const;
        unsigned short getAndSkipBOM();
        unsigned short bom = 0;
    protected:
        bool isUtf16 = false;
    };

    class StdIStream : public simplecpp::TokenList::Stream {
    public:
        // cppcheck-suppress uninitDerivedMemberVar - we call Stream::init() to initialize the private members
        explicit StdIStream(std::istream& istr);

        virtual int get() override;
        virtual int peek() override;
        virtual void unget() override;
        virtual bool good() override;

    private:
        std::istream& istr;
    };

    class StdCharBufStream : public simplecpp::TokenList::Stream {
    public:
        // cppcheck-suppress uninitDerivedMemberVar - we call Stream::init() to initialize the private members
        StdCharBufStream(const unsigned char* str, std::size_t size);
        virtual int get() override;
        virtual int peek() override;
        virtual void unget() override;
        virtual bool good() override;
    private:
        const unsigned char* str;
        const std::size_t size;
        std::size_t pos;
        int lastStatus;
    };

    class FileStream : public simplecpp::TokenList::Stream {
    public:
        // cppcheck-suppress uninitDerivedMemberVar - we call Stream::init() to initialize the private members
        explicit FileStream(const std::string& filename, std::vector<std::string>& files);
        ~FileStream() override;
        virtual int get() override;
        virtual int peek() override;
        virtual void unget() override;
        virtual bool good() override;
    private:
        void unget_internal(int ch);
        FileStream(const FileStream&);
        FileStream& operator=(const FileStream&);
        FILE* file;
        int lastCh;
        int lastStatus;
    };

    /** Tracking how macros are used */
    struct SIMPLECPP_LIB MacroUsage {
        explicit MacroUsage(const vector<string>& f, bool macroValueKnown_);
        string macroName;
        Location    macroLocation;
        Location    useLocation;
        bool        macroValueKnown;
    };

    /** Tracking #if/#elif expressions */
    struct SIMPLECPP_LIB IfCond {
        explicit IfCond(const Location& location, const string& E, long long result);
        Location location; // location of #if/#elif
        string E; // preprocessed condition
        long long result; // condition result
    };

    /**
     * Command line preprocessor settings.
     * On the command line these are configured by -D, -U, -I, --include, -std
     */
    struct SIMPLECPP_LIB DUI {
        DUI();
        list<string> defines;
        set<string> undefined;
        list<string> includePaths;
        list<string> includes;
        string std;
        bool clearIncludeCache;
        bool removeComments; /** remove comment tokens from included files */
    };

    SIMPLECPP_LIB long long characterLiteralToLL(const string& str);

    SIMPLECPP_LIB FileDataCache load(const TokenList &rawtokens, vector<string> &filenames, const DUI &dui, OutputList *outputList = nullptr);

    /**
     * Preprocess
     * @todo simplify interface
     * @param output TokenList that receives the preprocessing output
     * @param rawtokens Raw tokenlist for top sourcefile
     * @param files internal data of simplecpp
     * @param cache output from simplecpp::load()
     * @param dui defines, undefs, and include paths
     * @param outputList output: list that will receive output messages
     * @param macroUsage output: macro usage
     * @param ifCond output: #if/#elif expressions
     */
    SIMPLECPP_LIB void preprocess(TokenList &output, const TokenList &rawtokens, vector<string> &files, FileDataCache &cache, const DUI &dui, OutputList *outputList = nullptr, list<MacroUsage> *macroUsage = nullptr, list<IfCond> *ifCond = nullptr);

    /**
     * Deallocate data
     */
    SIMPLECPP_LIB void cleanup(FileDataCache &cache);

    /** Simplify path */
    SIMPLECPP_LIB string simplifyPath(string path);

    /** Convert Cygwin path to Windows path */
    SIMPLECPP_LIB string convertCygwinToWindowsPath(const string &cygwinPath);

    /** Returns the C version a given standard */
    SIMPLECPP_LIB cstd_t getCStd(const string &std);

    /** Returns the C++ version a given standard */
    SIMPLECPP_LIB cppstd_t getCppStd(const string &std);

    /** Returns the __STDC_VERSION__ value for a given standard */
    SIMPLECPP_LIB string getCStdString(const string &std);
    SIMPLECPP_LIB string getCStdString(cstd_t std);

    /** Returns the __cplusplus value for a given standard */
    SIMPLECPP_LIB string getCppStdString(const string &std);
    SIMPLECPP_LIB string getCppStdString(cppstd_t std);

    struct SIMPLECPP_LIB FileData {
        /** The canonical filename associated with this data */
        string filename;
        /** The tokens associated with this file */
        TokenList tokens;
    };

    class SIMPLECPP_LIB FileDataCache {
    public:
        FileDataCache() = default;

        FileDataCache(const FileDataCache &) = delete;
        FileDataCache(FileDataCache &&) = default;

        FileDataCache &operator=(const FileDataCache &) = delete;
        FileDataCache &operator=(FileDataCache &&) = default;

        /** Get the cached data for a file, or load and then return it if it isn't cached.
         *  returns the file data and true if the file was loaded, false if it was cached. */
        pair<FileData *, bool> get(const string &sourcefile, const string &header, const DUI &dui, bool systemheader, vector<string> &filenames, OutputList *outputList);

        void insert(FileData data) {
            FileData *const newdata = new FileData(move(data));

            mData.emplace_back(newdata);
            mNameMap.emplace(newdata->filename, newdata);
        }

        void clear() {
            mNameMap.clear();
            mIdMap.clear();
            mData.clear();
        }

        typedef vector<unique_ptr<FileData>> container_type;
        typedef container_type::iterator iterator;
        typedef container_type::const_iterator const_iterator;
        typedef container_type::size_type size_type;

        size_type size() const {
            return mData.size();
        }
        iterator begin() {
            return mData.begin();
        }
        iterator end() {
            return mData.end();
        }
        const_iterator begin() const {
            return mData.begin();
        }
        const_iterator end() const {
            return mData.end();
        }
        const_iterator cbegin() const {
            return mData.cbegin();
        }
        const_iterator cend() const {
            return mData.cend();
        }

    private:
        struct FileID {
#ifdef SIMPLECPP_WINDOWS
            struct {
                uint64_t VolumeSerialNumber;
                struct {
                    uint64_t IdentifierHi;
                    uint64_t IdentifierLo;
                } FileId;
            } fileIdInfo;

            bool operator==(const FileID &that) const noexcept {
                return fileIdInfo.VolumeSerialNumber == that.fileIdInfo.VolumeSerialNumber &&
                       fileIdInfo.FileId.IdentifierHi == that.fileIdInfo.FileId.IdentifierHi &&
                       fileIdInfo.FileId.IdentifierLo == that.fileIdInfo.FileId.IdentifierLo;
            }
#else
            dev_t dev;
            ino_t ino;

            bool operator==(const FileID& that) const noexcept {
                return dev == that.dev && ino == that.ino;
            }
#endif
            struct Hasher {
                size_t operator()(const FileID &id) const {
#ifdef SIMPLECPP_WINDOWS
                    return static_cast<size_t>(id.fileIdInfo.FileId.IdentifierHi ^ id.fileIdInfo.FileId.IdentifierLo ^
                                                    id.fileIdInfo.VolumeSerialNumber);
#else
                    return static_cast<size_t>(id.dev) ^ static_cast<size_t>(id.ino);
#endif
                }
            };
        };

        using name_map_type = unordered_map<string, FileData *>;
        using id_map_type = unordered_map<FileID, FileData *, FileID::Hasher>;

        static bool getFileId(const string &path, FileID &id);

        pair<FileData *, bool> tryload(name_map_type::iterator &name_it, const DUI &dui, vector<string> &filenames, OutputList *outputList);

        container_type mData;
        name_map_type mNameMap;
        id_map_type mIdMap;

    };
}

//#if defined(_MSC_VER)
//#  pragma warning(pop)
//#endif
