#include "pch.h"
#include "obj.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "MemorySubsystem.h"

#define LIB_SEARCH (INSTAT_USE_LIBPATH | INSTAT_LIBRARY)

void PrintIOError(MessagingSubsystem* mss, unsigned msg, char* types, char* name)
{
	mss->LnkMsg(msg, types, name, strerror(errno));
}

time_t QFModTime(int handle)
{
	struct stat buf;

	fstat(handle, &buf);
	return buf.st_mtime;
}

int QMakeFileName(char** pos, char* name, char* fname)
{
	char* pathptr;
	unsigned int        path_len;
	char* file_ptr;

	pathptr = *pos;
	if (pathptr == NULL)
		return(0);
	while (*pathptr != '\0') {
		if (*pathptr == PATH_LIST_SEP)
			*pos = ++pathptr;
		for (;;) {
			if (*pathptr == '\0')
				break;
			if (*pathptr == PATH_LIST_SEP)
				break;
			pathptr++;
		}
		path_len = pathptr - *pos;
		if (path_len != 0) {
			memcpy(fname, *pos, path_len);
			file_ptr = fname + path_len;
			switch (file_ptr[-1]) {
			CASE_PATH_SEP:
				break;
				default:
					*file_ptr++ = PATH_SEP;
					break;
			}
			strcpy(file_ptr, name);
			*pos = pathptr;
			return(1);
		}
		*pos = pathptr;
	}
	return(0);
}

f_handle PathObjOpen(FileSubsystem* files, char* path_ptr, char* name, char* new_name, infilelist* list)
{
	f_handle fp = NIL_HANDLE;
	for (;;) {
		list->prefix = path_ptr;
		if (!QMakeFileName(&path_ptr, name, new_name)) break;
		fp = files->QObjOpen(new_name);
		if (fp != NIL_HANDLE) break;
	}
	return fp;
}

char* GetEnvString(char* envname)
{
	return(getenv(envname));
}

f_handle TrySearchingLib(FileSubsystem* files, char* name, char* new_name, infilelist* list)
{
	f_handle fp = NIL_HANDLE;
	if (list->flags & INSTAT_USE_LIBPATH) {
		fp = PathObjOpen(files, GetEnvString("LIB"), name, new_name, list);
	}
	return fp;
}

bool QHavePath(char* name)
{
	return(*name == '\\' || *name == '/' || *(name + 1) == ':');
}

bool DoObjOpen(infilelist* list)
{
	char* name;
	f_handle    fp;
	unsigned    err;
	char* path_ptr;
	char        new_name[PATH_MAX];
	path_entry* searchpath;
	bool        haspath;

	name = list->name;
	if (list->handle != NIL_HANDLE) return(true);
	list->currpos = 0;
	haspath = QHavePath(name);
	if (list->path_list == NULL || haspath) {
		list->path_list = NULL;
		fp = files->QObjOpen(name);
		if (fp == NIL_HANDLE && !haspath) {
			fp = TrySearchingLib(files, name, new_name, list);
		}
	}
	else if (list->prefix != NULL) {
		path_ptr = list->prefix;
		QMakeFileName(&path_ptr, name, new_name);
		fp = files->QObjOpen(new_name);
	}
	else {
		fp = NIL_HANDLE;
		if (list->flags & LIB_SEARCH) {
			/* try libraries in current directory */
			fp = files->QObjOpen(name);
		}
		if (fp == NIL_HANDLE) {
			searchpath = list->path_list;
			for (;;) {
				fp = PathObjOpen(files, searchpath->name, name, new_name, list);
				if (fp != NIL_HANDLE || !(list->flags & LIB_SEARCH)) break;
				searchpath = searchpath->next;
				if (searchpath == NULL) {
					fp = TrySearchingLib(files, name, new_name, list);
					break;
				}
			}
		}
	}
	if (fp != NIL_HANDLE) {
		if (!(list->flags & INSTAT_GOT_MODTIME)) {
			list->modtime = QFModTime(fp);
		}
		list->handle = fp;
		return true;
	}
	else if (!(list->flags & INSTAT_NO_WARNING)) {
		err = (list->flags & INSTAT_OPEN_WARNING) ?
			WRN + MSG_CANT_OPEN : ERR + MSG_CANT_OPEN;
		PrintIOError(msg, err, "12", name);
		list->prefix = NULL;
		list->handle = NIL_HANDLE;
	}
	return false;
}
