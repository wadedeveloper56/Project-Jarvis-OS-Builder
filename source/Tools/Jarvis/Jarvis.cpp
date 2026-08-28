
// Jarvis.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Jarvis.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "JarvisDoc.h"
#include "JarvisView.h"
#include "CProjectOpenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJarvisApp

BEGIN_MESSAGE_MAP(CJarvisApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CJarvisApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CJarvisApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CJarvisApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CJarvisApp construction

CJarvisApp::CJarvisApp() noexcept
{
	m_bHiColorIcons = TRUE;


	m_nAppLook = 0;
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("Wade.Jarvis.CCompilerIDE.1.0.0.0"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CJarvisApp object

CJarvisApp theApp;


// CJarvisApp initialization

BOOL CJarvisApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Jarvis C Compiler"));
	LoadStdProfileSettings(16);  // Load standard INI file options (including MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_JarvisTYPE,
		RUNTIME_CLASS(CJarvisDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CJarvisView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;

	// call DragAcceptFiles only if there's a suffix
	//  In an MDI app, this should occur immediately after setting m_pMainWnd
	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);


	// Prevent a new document/view or MDI child window from opening on startup
	if (cmdInfo.m_nShellCommand == CCommandLineInfo::FileNew)
	{
		cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;
	}

	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The main window has been initialized, so show and update it
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CJarvisApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CJarvisApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CJarvisApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CJarvisApp customization load/save methods

void CJarvisApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CJarvisApp::LoadCustomState()
{}

void CJarvisApp::SaveCustomState()
{}

// CJarvisApp message handlers

void CJarvisApp::OnFileNew()
{
	CProjectOpenDlg prjOpenDlg;
	int result = prjOpenDlg.DoModal();
	if (result == IDOK)
	{
		// Create a new document
		CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
		if (pMainFrame != nullptr)
		{
			CMDIChildWnd* pChild = (CMDIChildWnd*)pMainFrame->MDIGetActive();

			if (pChild != NULL)
			{
				// 3. Get the active document from the child frame
				CJarvisDoc* pDoc = (CJarvisDoc*)pChild->GetActiveDocument();
				if (pDoc != nullptr)
				{
					// Successfully retrieved! Use your document here
					pDoc->m_myProject.m_projectName = prjOpenDlg.m_projectName;
					pDoc->m_myProject.m_outputDir = prjOpenDlg.m_projectBase;
					pDoc->m_myProject.m_intermediateDir = prjOpenDlg.m_intermediateDir;
					pDoc->m_myProject.m_projectDir = prjOpenDlg.m_projectDir;
					pDoc->m_myProject.m_projectBase = prjOpenDlg.m_projectBase;
					pDoc->m_myProject.m_bitSize = prjOpenDlg.m_bitSize;
				}
			}
		}
	}
}

void CJarvisApp::OnFileOpen()
{
	// Create a file dialog to select a project file
	CFileDialog fileDlg(TRUE, _T("prj"), NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("Jarvis Project Files (*.prj)|*.prj|All Files (*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK)
	{
		CString filePath = fileDlg.GetPathName();
		// Open the selected project file
		CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
		if (pMainFrame != nullptr)
		{
			// 2. Extract the active document from the frame
			CJarvisDoc* pDoc = (CJarvisDoc*)pMainFrame->GetActiveDocument();
			if (pDoc != nullptr)
			{
				// Successfully retrieved! Use your document here
				
			}
		}
	}
}
