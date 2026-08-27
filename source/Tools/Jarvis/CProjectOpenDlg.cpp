#include "CProjectOpenDlg.h"
#include "Resource.h"

CProjectOpenDlg::CProjectOpenDlg() noexcept : CDialogEx(IDD_PRJ_OPEN_DIALOG), m_projectDir(_T(""))
{}

void CProjectOpenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_projectDir);
}

BEGIN_MESSAGE_MAP(CProjectOpenDlg, CDialogEx)
END_MESSAGE_MAP()

void CProjectOpenDlg::OnOK()
{
	CDialogEx::OnOK();
	UpdateData(TRUE); // TRUE means read from controls to variables
}
