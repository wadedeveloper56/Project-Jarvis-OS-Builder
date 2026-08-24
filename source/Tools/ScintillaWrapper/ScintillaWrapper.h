// ScintillaWrapper.h : main header file for the ScintillaWrapper DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CScintillaWrapperApp
// See ScintillaWrapper.cpp for the implementation of this class
//

class CScintillaWrapperApp : public CWinApp
{
public:
	CScintillaWrapperApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
