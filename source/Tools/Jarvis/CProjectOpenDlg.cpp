#include "CProjectOpenDlg.h"
#include "Resource.h"

CProjectOpenDlg::CProjectOpenDlg() noexcept : CDialogEx(IDD_PRJ_OPEN_DIALOG), 
m_projectDirControl()
, m_projectName(_T(""))
, m_outputDir(_T(""))
, m_intermediateDir(_T(""))
, m_projectDir(_T(""))
{}

void CProjectOpenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_projectName);
	DDX_Text(pDX, IDC_EDIT3, m_outputDir);
	DDX_Text(pDX, IDC_EDIT4, m_intermediateDir);
	DDX_Control(pDX, IDC_MFCEDITBROWSE1, m_projectDirControl);
	DDX_Text(pDX, IDC_MFCEDITBROWSE1, m_projectDir);
}

BEGIN_MESSAGE_MAP(CProjectOpenDlg, CDialogEx)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CProjectOpenDlg::OnEnChangeMfceditbrowse1)
END_MESSAGE_MAP()

void CProjectOpenDlg::OnOK()
{
	CDialogEx::OnOK();
	UpdateData(TRUE); // TRUE means read from controls to variables
}

void CProjectOpenDlg::OnEnChangeMfceditbrowse1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

BOOL CProjectOpenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_projectDirControl.EnableFolderBrowseButton();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
