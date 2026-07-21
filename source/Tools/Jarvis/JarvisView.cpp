
// JarvisView.cpp : implementation of the CJarvisView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Jarvis.h"
#endif

#include "JarvisDoc.h"
#include "JarvisView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJarvisView

IMPLEMENT_DYNCREATE(CJarvisView, CView)

BEGIN_MESSAGE_MAP(CJarvisView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CJarvisView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CJarvisView construction/destruction

CJarvisView::CJarvisView() noexcept
{
	// TODO: add construction code here

}

CJarvisView::~CJarvisView()
{
}

BOOL CJarvisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CJarvisView drawing

void CJarvisView::OnDraw(CDC* /*pDC*/)
{
	CJarvisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CJarvisView printing


void CJarvisView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CJarvisView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CJarvisView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CJarvisView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CJarvisView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CJarvisView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CJarvisView diagnostics

#ifdef _DEBUG
void CJarvisView::AssertValid() const
{
	CView::AssertValid();
}

void CJarvisView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJarvisDoc* CJarvisView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJarvisDoc)));
	return (CJarvisDoc*)m_pDocument;
}
#endif //_DEBUG


// CJarvisView message handlers
