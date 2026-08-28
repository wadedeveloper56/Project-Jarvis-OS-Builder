#pragma once

#include <afxdialogex.h>
#include <ShlObj_core.h>
#include <afxeditbrowsectrl.h>

class CProjectOpenDlg : public CDialogEx
{
public:
	CProjectOpenDlg() noexcept;

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRJ_OPEN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP();
public:
	virtual void OnOK();

	CString m_projectName;
	CString m_outputDir;
	CString m_intermediateDir;
	CString m_projectDir;
	CString m_projectBase;
	int m_bitSize;

	CEdit m_projectNameControl;
	CEdit m_outputDirControl;
	CEdit m_intermediateDirControl;
	CMFCEditBrowseCtrl m_projectDirControl;
	CEdit m_projectBaseControl;

	afx_msg void OnEnChangeMfceditbrowse1();
	virtual BOOL OnInitDialog();
};
