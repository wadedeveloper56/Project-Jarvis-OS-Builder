#include  "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

pair<FileData*, bool> FileDataCache::get(const string& sourcefile, const string& header, const DUI& dui, bool systemheader, vector<string>& filenames, OutputList* outputList)
{
	if (isAbsolutePath(header))
	{
		auto ins = mNameMap.emplace(simplifyPath(header), nullptr);

		if (ins.second)
		{
			const auto ret = tryload(ins.first, dui, filenames, outputList);
			if (ret.first != nullptr)
			{
				return ret;
			}
		}
		else
		{
			return { ins.first->second, false };
		}

		return { nullptr, false };
	}

	if (!systemheader)
	{
		auto ins = mNameMap.emplace(simplifyPath(dirPath(sourcefile) + header), nullptr);

		if (ins.second)
		{
			const auto ret = tryload(ins.first, dui, filenames, outputList);
			if (ret.first != nullptr)
			{
				return ret;
			}
		}
		else if (ins.first->second != nullptr)
		{
			return { ins.first->second, false };
		}
	}

	for (const auto& includePath : dui.includePaths)
	{
		auto ins = mNameMap.emplace(simplifyPath(includePath + "/" + header), nullptr);

		if (ins.second)
		{
			const auto ret = tryload(ins.first, dui, filenames, outputList);
			if (ret.first != nullptr)
			{
				return ret;
			}
		}
		else if (ins.first->second != nullptr)
		{
			return { ins.first->second, false };
		}
	}

	return { nullptr, false };
}

void FileDataCache::insert(FileData data) {
	FileData* const newdata = new FileData(move(data));

	mData.emplace_back(newdata);
	mNameMap.emplace(newdata->filename, newdata);
}

void FileDataCache::clear() {
	mNameMap.clear();
	mIdMap.clear();
	mData.clear();
}

FileDataCache::size_type FileDataCache::size() const {
	return mData.size();
}

FileDataCache::iterator FileDataCache::begin() {
	return mData.begin();
}

FileDataCache::iterator FileDataCache::end() {
	return mData.end();
}

FileDataCache::const_iterator FileDataCache::begin2() const {
	return mData.begin();
}

FileDataCache::const_iterator FileDataCache::end2() const {
	return mData.end();
}

FileDataCache::const_iterator FileDataCache::cbegin() const {
	return mData.cbegin();
}

FileDataCache::const_iterator FileDataCache::cend() const {
	return mData.cend();
}

bool FileDataCache::FileID::operator==(const FileID& that) const noexcept {
	return fileIdInfo.VolumeSerialNumber == that.fileIdInfo.VolumeSerialNumber &&
		fileIdInfo.FileId.IdentifierHi == that.fileIdInfo.FileId.IdentifierHi &&
		fileIdInfo.FileId.IdentifierLo == that.fileIdInfo.FileId.IdentifierLo;
}

size_t FileDataCache::FileID::Hasher::operator()(const FileDataCache::FileID& id) const {
#ifdef SIMPLECPP_WINDOWS
	return static_cast<size_t>(id.fileIdInfo.FileId.IdentifierHi ^ id.fileIdInfo.FileId.IdentifierLo ^
		id.fileIdInfo.VolumeSerialNumber);
#else
	return static_cast<size_t>(id.dev) ^ static_cast<size_t>(id.ino);
#endif
}

bool FileDataCache::getFileId(const string& path, FileID& id)
{
#ifdef SIMPLECPP_WINDOWS
	HANDLE hFile = CreateFileA(path.c_str(), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	const BOOL ret = GetFileInformationByHandleEx(hFile, FileIdInfo, &id.fileIdInfo, sizeof(id.fileIdInfo));

	CloseHandle(hFile);

	return ret == TRUE;
#else
	struct stat statbuf;

	if (stat(path.c_str(), &statbuf) != 0)
		return false;

	id.dev = statbuf.st_dev;
	id.ino = statbuf.st_ino;

	return true;
#endif
}

pair<FileData*, bool> FileDataCache::tryload(FileDataCache::name_map_type::iterator& name_it, const DUI& dui, vector<string>& filenames, OutputList* outputList)
{
	const string& path = name_it->first;
	FileID fileId;

	if (!getFileId(path, fileId))
		return { nullptr, false };

	const auto id_it = mIdMap.find(fileId);
	if (id_it != mIdMap.end())
	{
		name_it->second = id_it->second;
		return { id_it->second, false };
	}

	ifstream f(path);
	FileData* const data = new FileData{ path, TokenList(f, filenames, path, outputList) };

	if (dui.removeComments)
		data->tokens.removeComments();

	name_it->second = data;
	mIdMap.emplace(fileId, data);
	mData.emplace_back(data);

	return { data, true };
}
