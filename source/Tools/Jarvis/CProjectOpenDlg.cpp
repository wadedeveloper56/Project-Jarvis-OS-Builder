#include "CProjectOpenDlg.h"
#include "Resource.h"

CProjectOpenDlg::CProjectOpenDlg() noexcept : CDialogEx(IDD_PRJ_OPEN_DIALOG), 
m_projectDirControl()
, m_projectName(_T(""))
, m_outputDir(_T(""))
, m_intermediateDir(_T(""))
, m_projectDir(_T(""))
, m_bitSize(0)
{}

void CProjectOpenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_projectName);
	DDX_Control(pDX, IDC_EDIT2, m_projectNameControl);

	DDX_Text(pDX, IDC_EDIT3, m_outputDir);
	DDX_Control(pDX, IDC_EDIT3, m_outputDirControl);

	DDX_Text(pDX, IDC_EDIT4, m_intermediateDir);
	DDX_Control(pDX, IDC_EDIT4, m_intermediateDirControl);

	DDX_Control(pDX, IDC_MFCEDITBROWSE1, m_projectDirControl);
	DDX_Text(pDX, IDC_MFCEDITBROWSE1, m_projectDir);

	DDX_Control(pDX, IDC_EDIT1, m_projectBaseControl);
	DDX_Text(pDX, IDC_EDIT1, m_projectBase);

	DDX_Radio(pDX, IDC_RADIO1, m_bitSize);
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
	CString strName;
	m_projectNameControl.GetWindowText(strName);

	CString strPath;
	m_projectDirControl.GetWindowText(strPath);

	// Update your other control here
	CString pd = strPath + _T("\\") + strName;
	m_projectBaseControl.SetWindowText(pd);
	m_outputDirControl.SetWindowText(pd + _T("\\output\\bin\\"));
	m_intermediateDirControl.SetWindowText(pd + _T("\\output\\intermediate\\"));
}

BOOL CProjectOpenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_projectDirControl.EnableFolderBrowseButton();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
