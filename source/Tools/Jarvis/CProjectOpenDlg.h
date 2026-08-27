#pragma once
#include <afxdialogex.h>

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
	CString m_projectDir;
	virtual void OnOK();
};
