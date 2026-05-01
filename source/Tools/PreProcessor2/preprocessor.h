#pragma once

using namespace std;

namespace WadeSpace::PreProcessor 
{
    enum cstd_t { CUnknown=-1, C89, C99, C11, C17, C23 };
    enum cppstd_t { CPPUnknown=-1, CPP03, CPP11, CPP14, CPP17, CPP20, CPP23, CPP26 };

    typedef string TokenString;
    class Macro;
    class FileDataCache;

    class  Location {
    public:
        Location(const vector<string>& f);
        Location(const Location& loc);
        Location& operator=(const Location& other);
        void adjust(const string &str);
        bool operator<(const Location& rhs) const;
        bool sameline(const Location& other) const;
        const string& file() const;
        const vector<string> &files;
        unsigned int fileIndex;
        unsigned int line;
        unsigned int col;
    private:
        static const string emptyFileName;
    };

    class  Token {
    public:
        Token(const TokenString& s, const Location& loc, bool wsahead = false);
        Token(const Token& tok);
        void flags();
        const TokenString& str() const;
        void setstr(const string& s);
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
        // Not implemented - prevent assignment
        Token &operator=(const Token &tok);
    };

    struct  Output {
        enum Type {
            ERROR, /* #error */
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
        Output(const vector<string> &files) : type(ERROR), location(files) {}
        Output(const vector<string>& files, Type type, const string& msg) : type(type), location(files), msg(msg) {}
        Location location;
        string msg;
    };

    typedef list<Output> OutputList;

    class  TokenList {
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
        TokenList(TokenList &&other);
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

    struct  MacroUsage {
        explicit MacroUsage(const vector<string> &f, bool macroValueKnown_) : macroLocation(f), useLocation(f), macroValueKnown(macroValueKnown_) {}
        string macroName;
        Location    macroLocation;
        Location    useLocation;
        bool        macroValueKnown;
    };

    struct  IfCond {
        explicit IfCond(const Location& location, const string &E, long long result) : location(location), E(E), result(result) {}
        Location location; // location of #if/#elif
        string E; // preprocessed condition
        long long result; // condition result
    };

    struct  DUI {
        DUI() : clearIncludeCache(false), removeComments(false) {}
        list<string> defines;
        set<string> undefined;
        list<string> includePaths;
        list<string> includes;
        string std;
        bool clearIncludeCache;
        bool removeComments; /** remove comment tokens from included files */
    };

     long long characterLiteralToLL(const string& str);

     FileDataCache load(const TokenList &rawtokens, vector<string> &filenames, const DUI &dui, OutputList *outputList = nullptr);

     void preprocess(TokenList &output, const TokenList &rawtokens, vector<string> &files, FileDataCache &cache, const DUI &dui, OutputList *outputList = nullptr, list<MacroUsage> *macroUsage = nullptr, list<IfCond> *ifCond = nullptr);

     void cleanup(FileDataCache &cache);

     string simplifyPath(string path);

     string convertCygwinToWindowsPath(const string &cygwinPath);

     cstd_t getCStd(const string &std);

     cppstd_t getCppStd(const string &std);

     string getCStdString(const string &std);

     string getCStdString(cstd_t std);

     string getCppStdString(const string &std);

     string getCppStdString(cppstd_t std);

    struct  FileData {
        /** The canonical filename associated with this data */
        string filename;
        /** The tokens associated with this file */
        TokenList tokens;
    };

    class  FileDataCache {
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

    class TokenList::Stream
    {
    public:
        virtual ~Stream() {}

        virtual int get() = 0;
        virtual int peek() = 0;
        virtual void unget() = 0;
        virtual bool good() = 0;

        unsigned char readChar() {
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

        unsigned char peekChar() {
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

        void ungetChar() {
            unget();
            if (isUtf16)
                unget();
        }

    protected:
        void init() {
            // initialize since we use peek() in getAndSkipBOM()
            isUtf16 = false;
            bom = getAndSkipBOM();
            isUtf16 = (bom == 0xfeff || bom == 0xfffe);
        }

    private:
        inline int makeUtf16Char(const unsigned char ch, const unsigned char ch2) const {
            return (bom == 0xfeff) ? (ch << 8 | ch2) : (ch2 << 8 | ch);
        }

        unsigned short getAndSkipBOM() {
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

        unsigned short bom;
    protected:
        bool isUtf16;
    };

    class StdIStream : public TokenList::Stream
    {
    public:
        // cppcheck-suppress uninitDerivedMemberVar - we call Stream::init() to initialize the private members
        explicit StdIStream(istream& istr)
            : istr(istr) {
            assert(istr.good());
            init();
        }

        virtual int get() override {
            return istr.get();
        }
        virtual int peek() override {
            return istr.peek();
        }
        virtual void unget() override {
            istr.unget();
        }
        virtual bool good() override {
            return istr.good();
        }

    private:
        istream& istr;
    };

    class StdCharBufStream : public TokenList::Stream
    {
    public:
        // cppcheck-suppress uninitDerivedMemberVar - we call Stream::init() to initialize the private members
        StdCharBufStream(const unsigned char* str, size_t size)
            : str(str)
            , size(size)
            , pos(0)
            , lastStatus(0) {
            init();
        }

        virtual int get() override {
            if (pos >= size)
                return lastStatus = EOF;
            return str[pos++];
        }
        virtual int peek() override {
            if (pos >= size)
                return lastStatus = EOF;
            return str[pos];
        }
        virtual void unget() override {
            --pos;
        }
        virtual bool good() override {
            return lastStatus != EOF;
        }

    private:
        const unsigned char* str;
        const size_t size;
        size_t pos;
        int lastStatus;
    };

    class FileStream : public TokenList::Stream
    {
    public:
        // cppcheck-suppress uninitDerivedMemberVar - we call Stream::init() to initialize the private members
        explicit FileStream(const string& filename, vector<string>& files)
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

        ~FileStream() override {
            fclose(file);
            file = nullptr;
        }

        virtual int get() override {
            lastStatus = lastCh = fgetc(file);
            return lastCh;
        }
        virtual int peek() override {
            // keep lastCh intact
            const int ch = fgetc(file);
            unget_internal(ch);
            return ch;
        }
        virtual void unget() override {
            unget_internal(lastCh);
        }
        virtual bool good() override {
            return lastStatus != EOF;
        }

    private:
        void unget_internal(int ch) {
            if (isUtf16)
            {
                // TODO: use ungetc() as well
                // UTF-16 has subsequent unget() calls
                fseek(file, -1, SEEK_CUR);
            }
            else
                ungetc(ch, file);
        }

        FileStream(const FileStream&);
        FileStream& operator=(const FileStream&);

        FILE* file;
        int lastCh;
        int lastStatus;
    };

    bool isHex(const string& s);
    bool isOct(const string& s);
    bool isStringLiteral_(const string& s);
    bool isCharLiteral_(const string& s);
    extern TokenString DEFINE;
    extern TokenString UNDEF;
    extern TokenString INCLUDE;
    extern TokenString ERROR;
    extern TokenString WARNING;
    extern TokenString IF;
    extern TokenString IFDEF;
    extern TokenString IFNDEF;
    extern TokenString DEFINED;
    extern TokenString ELSE;
    extern TokenString ELIF;
    extern TokenString ENDIF;
    extern TokenString PRAGMA;
    extern TokenString ONCE;
    extern TokenString HAS_INCLUDE;

    template<class T> string toString(T t)
    {
        // NOLINTNEXTLINE(misc-const-correctness) - false positive
        ostringstream ostr;
        ostr << t;
        return ostr.str();
    }

#ifdef SIMPLECPP_DEBUG_MACRO_EXPANSION
    string locstring(const Location& loc);
#endif
    
    long long stringToLL(const string& s);
    unsigned long long stringToULL(const string& s);
    bool endsWith(const string& s, const string& e);
    bool sameline(const Token* tok1, const Token* tok2);
    bool isAlternativeBinaryOp(const Token* tok, const string& alt);
    bool isAlternativeUnaryOp(const Token* tok, const string& alt);
    string replaceAll(string s, const string& from, const string& to);
    bool isNameChar(unsigned char ch);
    string escapeString(const string& str);
    void portabilityBackslash(OutputList* outputList, const vector<string>& files, const Location& location);
    bool isStringLiteralPrefix(const string& str);

}

