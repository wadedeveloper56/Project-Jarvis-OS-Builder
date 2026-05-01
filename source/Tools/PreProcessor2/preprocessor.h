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
	};

	class  Token
	{
	public:
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
	private:
		TokenString string;
		set<const Macro*> mExpandedFrom;
		// Not implemented - prevent assignment
		Token& operator=(const Token& tok);
	};

	class TokenList
	{
	public:
		class Stream;
	}; 
	
	struct  Output
	{
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
		Location location;
		string msg;
	};

	typedef list<Output> OutputList;

	struct DUI {
		list<string> defines;
		set<string> undefined;
		list<string> includePaths;
		list<string> includes;
		string std;
		bool clearIncludeCache;
		bool removeComments;
	};

	struct FileData {
		string filename;
		TokenList tokens;
	};

	class FileDataCache {
		typedef vector<unique_ptr<FileData>> container_type;
		typedef container_type::iterator iterator;
		typedef container_type::const_iterator const_iterator;
		typedef container_type::size_type size_type;
	private:
		struct FileID
		{
			struct
			{
				uint64_t VolumeSerialNumber;
				struct
				{
					uint64_t IdentifierHi;
					uint64_t IdentifierLo;
				} FileId;
			} fileIdInfo;

			bool operator==(const FileID& that) const noexcept {
				return fileIdInfo.VolumeSerialNumber == that.fileIdInfo.VolumeSerialNumber &&
					fileIdInfo.FileId.IdentifierHi == that.fileIdInfo.FileId.IdentifierHi &&
					fileIdInfo.FileId.IdentifierLo == that.fileIdInfo.FileId.IdentifierLo;
			}
			struct Hasher
			{
				size_t operator()(const FileID& id) const {
					return static_cast<size_t>(id.fileIdInfo.FileId.IdentifierHi ^ id.fileIdInfo.FileId.IdentifierLo ^	id.fileIdInfo.VolumeSerialNumber);
				}
			};
		};

		using name_map_type = unordered_map<string, FileData*>;
		using id_map_type = unordered_map<FileID, FileData*, FileID::Hasher>;
		container_type mData;
		name_map_type mNameMap;
		id_map_type mIdMap;
	};

	struct IfCond {
		Location location;
		string E;
		long long result;
	};

	struct MacroUsage
	{};

	class Macro
	{};

	class NonExistingFilesCache
	{};

	class TokenList::Stream
	{};

	class StdIStream : public TokenList::Stream
	{};

	class StdCharBufStream : public TokenList::Stream
	{};

	class FileStream : public TokenList::Stream
	{};
}

