// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here

#include <windows.h>
#include <iostream>
#include <fcntl.h>   // Required for file control constants like _O_CREAT, _O_WRONLY
#include <sys/stat.h> // Required for permission constants like _S_IREAD, _S_IWRITE
#include <share.h>   // Required for file sharing constants like _SH_DENYNO
#include <errno.h>   // Required for errno_t and error handling

#endif //PCH_H
