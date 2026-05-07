#pragma once

using namespace std;

namespace WadeSpace::PreProcessor
{
	enum cstd_t { CUnknown = -1, C89, C99, C11, C17, C23 };
	enum cppstd_t { CPPUnknown = -1, CPP03, CPP11, CPP14, CPP17, CPP20, CPP23, CPP26 };
	typedef string TokenString;
	class Macro;
	class FileDataCache;
	class TokenList;

	class  Location
	{
	public:
		const vector<string>& files;
		unsigned int fileIndex;
		unsigned int line;
		unsigned int col;
	private:
		static const string emptyFileName;
	public:
		Location(const vector<string>& f);
		Location(const Location& loc);
		Location& operator=(const Location& other);
		void adjust(const string& str);
		bool operator<(const Location& rhs) const;
		bool sameline(const Location& other) const;
		const string& file() const;
	};

	class  Token
	{
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
		Token* previous;
		Token* next;
		mutable const Token* nextcond;
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
		Token& operator=(const Token& tok);
	};

	struct  Output
	{
		explicit Output(const vector<string>& files) : type(ERROR), location(files) {}
		enum Type
		{
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
		explicit Output(const vector<string>& files, Type type, const string& msg) : type(type), location(files), msg(msg) {}
		Location location;
		string msg;
	};

	typedef list<Output> OutputList;

	class TokenList
	{
	public:
		class Stream;

		explicit TokenList(vector<string>& filenames);
		TokenList(istream& istr, vector<string>& filenames, const string& filename = string(), OutputList* outputList = nullptr);
		TokenList(const unsigned char* data, size_t size, vector<string>& filenames, const string& filename = string(), OutputList* outputList = nullptr);
		TokenList(const char* data, size_t size, vector<string>& filenames, const string& filename = string(), OutputList* outputList = nullptr);
		TokenList(const string& filename, vector<string>& filenames, OutputList* outputList = nullptr);
		TokenList(const TokenList& other);
		TokenList(TokenList&& other);
		~TokenList();
		TokenList& operator=(const TokenList& other);
		TokenList& operator=(TokenList&& other);
		void clear();
		bool empty() const;
		void push_back(Token* tok);
		void dump() const;
		string stringify() const;
		void readfile(Stream& stream, const string& filename = string(), OutputList* outputList = nullptr);
		void constFold();
		void removeComments();
		Token* front();
		const Token* cfront() const;
		Token* back();
		const Token* cback() const;
		void deleteToken(Token* tok);
		void takeTokens(TokenList& other);
		/** sizeof(T) */
		map<string, size_t> sizeOfType;
		const vector<string>& getFiles() const;
	private:
		void combineOperators();
		void constFoldUnaryNotPosNeg(Token* tok);
		void constFoldMulDivRem(Token* tok);
		void constFoldAddSub(Token* tok);
		void constFoldShift(Token* tok);
		void constFoldComparison(Token* tok);
		void constFoldBitwise(Token* tok);
		void constFoldLogicalOp(Token* tok);
		void constFoldQuestionOp(Token** tok1);
		string readUntil(Stream& stream, const Location& location, char start, char end, OutputList* outputList);
		void lineDirective(unsigned int fileIndex, unsigned int line, Location* location);
		string lastLine(int maxsize = 1000) const;
		const Token* lastLineTok(int maxsize = 1000) const;
		bool isLastLinePreprocessor(int maxsize = 1000) const;
		unsigned int fileIndex(const string& filename);
		Token* frontToken;
		Token* backToken;
		vector<string>& files;
	};

	struct DUI
	{
		DUI() : clearIncludeCache(false), removeComments(false) {}
		list<string> defines;
		set<string> undefined;
		list<string> includePaths;
		list<string> includes;
		string std;
		bool clearIncludeCache;
		bool removeComments;
	};

	struct FileData
	{
		string filename;
		TokenList tokens;
	};

	class FileDataCache
	{
	public:
		FileDataCache() = default;
		FileDataCache(const FileDataCache&) = delete;
		FileDataCache(FileDataCache&&) = default;
		FileDataCache& operator=(const FileDataCache&) = delete;
		FileDataCache& operator=(FileDataCache&&) = default;
		pair<FileData*, bool> get(const string& sourcefile, const string& header, const DUI& dui, bool systemheader, vector<string>& filenames, OutputList* outputList);
		void insert(FileData data);
		void clear();
		typedef vector<unique_ptr<FileData>> container_type;
		typedef container_type::iterator iterator;
		typedef container_type::const_iterator const_iterator;
		typedef container_type::size_type size_type;
		size_type size() const;
		iterator begin();
		iterator end();
		const_iterator begin2() const;
		const_iterator end2() const;
		const_iterator cbegin() const;
		const_iterator cend() const;
	private:
		struct FileID
		{
#ifdef SIMPLECPP_WINDOWS
			struct
			{
				uint64_t VolumeSerialNumber;
				struct
				{
					uint64_t IdentifierHi;
					uint64_t IdentifierLo;
				} FileId;
			} fileIdInfo;

			bool operator==(const FileID& that) const noexcept;
#else
			dev_t dev;
			ino_t ino;

			bool operator==(const FileID& that) const noexcept;
#endif
			struct Hasher
			{
				size_t operator()(const FileID& id) const;
			};
		};
		using name_map_type = unordered_map<string, FileData*>;
		using id_map_type = unordered_map<FileID, FileData*, FileID::Hasher>;
		static bool getFileId(const string& path, FileID& id);
		pair<FileData*, bool> tryload(name_map_type::iterator& name_it, const DUI& dui, vector<string>& filenames, OutputList* outputList);
		container_type mData;
		name_map_type mNameMap;
		id_map_type mIdMap;
	};

	struct IfCond
	{
		IfCond(const Location& location, const string& E, long long result) : location(location), E(E), result(result) {}
		Location location;
		string E;
		long long result;
	};

	struct MacroUsage
	{
		MacroUsage(const vector<string>& f, bool macroValueKnown_) : macroLocation(f), useLocation(f), macroValueKnown(macroValueKnown_) {}
		string macroName;
		Location    macroLocation;
		Location    useLocation;
		bool        macroValueKnown;
	};

    using MacroMap = unordered_map<TokenString, Macro>;

    class Macro
    {
    public:
        Macro(vector<string>& f);
        Macro(const Token* tok, vector<string>& f);
        Macro(const string& name, const string& value, vector<string>& f);
        Macro(const Macro& other);
        ~Macro();
        Macro& operator=(const Macro& other);
        bool valueDefinedInCode() const;
        const Token* expand(TokenList* const output, const Token* rawtok, const MacroMap& macros, vector<string>& inputFiles) const;
        const TokenString& name() const;
        const Location& defineLocation() const;
        const list<Location>& usage() const;
        bool functionLike() const;

        struct Error
        {
            Error(const Location& loc, const string& s) : location(loc), what(s) {}
            const Location location;
            const string what;
        };

        /** Struct that is thrown when macro is expanded with wrong number of parameters */
        struct wrongNumberOfParameters : public Error
        {
            wrongNumberOfParameters(const Location& loc, const string& macroName) : Error(loc, "Wrong number of parameters for macro \'" + macroName + "\'.") {}
        };

        /** Struct that is thrown when there is invalid ## usage */
        struct invalidHashHash : public Error
        {
            static inline string format(const string& macroName, const string& message) {
                return "Invalid ## usage when expanding \'" + macroName + "\': " + message;
            }

            invalidHashHash(const Location& loc, const string& macroName, const string& message)
                : Error(loc, format(macroName, message)) {}

            static inline invalidHashHash unexpectedToken(const Location& loc, const string& macroName, const Token* tokenA) {
                return invalidHashHash(loc, macroName, "Unexpected token '" + tokenA->str() + "'");
            }

            static inline invalidHashHash cannotCombine(const Location& loc, const string& macroName, const Token* tokenA, const Token* tokenB) {
                return invalidHashHash(loc, macroName, "Combining '" + tokenA->str() + "' and '" + tokenB->str() + "' yields an invalid token.");
            }

            static inline invalidHashHash unexpectedNewline(const Location& loc, const string& macroName) {
                return invalidHashHash(loc, macroName, "Unexpected newline");
            }

            static inline invalidHashHash universalCharacterUB(const Location& loc, const string& macroName, const Token* tokenA, const string& strAB) {
                return invalidHashHash(loc, macroName, "Combining '\\" + tokenA->str() + "' and '" + strAB.substr(tokenA->str().size()) + "' yields universal character '\\" + strAB + "'. This is undefined behavior according to C standard chapter 5.1.1.2, paragraph 4.");
            }
        };
    private:
        Token* newMacroToken(const TokenString& str, const Location& loc, bool replaced, const Token* expandedFromToken = nullptr) const;
        bool parseDefine(const Token* nametoken);
        unsigned int getArgNum(const TokenString& str) const;
        vector<const Token*> getMacroParameters(const Token* nameTokInst, bool calledInDefine) const;
        const Token* appendTokens(TokenList* tokens,
            const Location& rawloc,
            const Token* const lpar,
            const MacroMap& macros,
            const set<TokenString>& expandedmacros,
            const vector<const Token*>& parametertokens) const;
		const Token* expand(TokenList* const output, const Location& loc, const Token* const nameTokInst, const MacroMap& macros, set<TokenString> expandedmacros) const;
		const Token* recursiveExpandToken(TokenList* output, TokenList& temp, const Location& loc, const Token* tok, const MacroMap& macros, const set<TokenString>& expandedmacros, const vector<const Token*>& parametertokens) const;
		const Token* expandToken(TokenList* output, const Location& loc, const Token* tok, const MacroMap& macros, const set<TokenString>& expandedmacros, const vector<const Token*>& parametertokens) const;
		bool expandArg(TokenList* output, const Token* tok, const vector<const Token*>& parametertokens) const;
		bool expandArg(TokenList* output, const Token* tok, const Location& loc, const MacroMap& macros, const set<TokenString>& expandedmacros, const vector<const Token*>& parametertokens) const;
		const Token* expandHash(TokenList* output, const Location& loc, const Token* tok, const set<TokenString>& expandedmacros, const vector<const Token*>& parametertokens) const;
		const Token* expandHashHash(TokenList* output, const Location& loc, const Token* tok, const MacroMap& macros, const set<TokenString>& expandedmacros, const vector<const Token*>& parametertokens, bool expandResult = true) const;
		static bool isReplaced(const set<string>& expandedmacros);
        const Token* nameTokDef;
        vector<TokenString> args;
        const Token* valueToken;
        const Token* endToken;
        vector<string>& files;
        TokenList tokenListDefine;
        mutable list<Location> usageList;
        bool variadic;
        bool variadicOpt;
        const TokenList* optExpandValue;
        const TokenList* optNoExpandValue;
        bool valueDefinedInCode_;
    };

	class NonExistingFilesCache
	{};

	class TokenList::Stream
	{
	public:
		virtual ~Stream() {}
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

	template<class T> static string toString(T t)
	{
		ostringstream ostr;
		ostr << t;
		return ostr.str();
	}

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

    bool isHex(const string& s);
	bool isOct(const string& s);
	bool sameline(const Token* tok1, const Token* tok2);
	long long stringToLL(const string& s);
	unsigned long long stringToULL(const string& s);
	bool endsWith(const string& s, const string& e);
	bool sameline(const Token* tok1, const Token* tok2);
	bool isAlternativeBinaryOp(const Token* tok, const string& alt);
	bool isAlternativeUnaryOp(const Token* tok, const string& alt);
	void portabilityBackslash(OutputList* outputList, const vector<string>& files, const Location& location);
	string replaceAll(string s, const string& from, const string& to);
	bool isNameChar(unsigned char ch);
	string escapeString(const string& str);
	bool isStringLiteralPrefix(const string& str);
	bool isFloatSuffix(const Token* tok);
	bool isAbsolutePath(const string& path);
	string simplifyPath(string path);
	string dirPath(const string& path, bool withTrailingSlash = true);
	bool isStringLiteral_(const string& s);
	bool isCharLiteral_(const string& s);
}

