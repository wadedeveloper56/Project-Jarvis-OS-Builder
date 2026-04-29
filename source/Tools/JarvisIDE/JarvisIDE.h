
// JarvisIDE.h : main header file for the JarvisIDE application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CJarvisIDEApp:
// See JarvisIDE.cpp for the implementation of this class
//

class CJarvisIDEApp : public CWinAppEx
{
public:
	CJarvisIDEApp() noexcept;


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
	DECLARE_MESSAGE_MAP()
};

extern CJarvisIDEApp theApp;
