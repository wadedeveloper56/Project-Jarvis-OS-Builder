
// Jarvis.h : main header file for the Jarvis application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CJarvisApp:
// See Jarvis.cpp for the implementation of this class
//

class CJarvisApp : public CWinAppEx
{
public:
	CJarvisApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();

	DECLARE_MESSAGE_MAP()
};

extern CJarvisApp theApp;
