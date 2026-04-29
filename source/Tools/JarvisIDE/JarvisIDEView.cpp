
// JarvisIDEView.cpp : implementation of the CJarvisIDEView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "JarvisIDE.h"
#endif

#include "JarvisIDEDoc.h"
#include "JarvisIDEView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJarvisIDEView

IMPLEMENT_DYNCREATE(CJarvisIDEView, CView)

BEGIN_MESSAGE_MAP(CJarvisIDEView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CJarvisIDEView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CJarvisIDEView construction/destruction

CJarvisIDEView::CJarvisIDEView() noexcept
{
	// TODO: add construction code here

}

CJarvisIDEView::~CJarvisIDEView()
{
}

BOOL CJarvisIDEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CJarvisIDEView drawing

void CJarvisIDEView::OnDraw(CDC* /*pDC*/)
{
	CJarvisIDEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CJarvisIDEView printing


void CJarvisIDEView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CJarvisIDEView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CJarvisIDEView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CJarvisIDEView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CJarvisIDEView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CJarvisIDEView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CJarvisIDEView diagnostics

#ifdef _DEBUG
void CJarvisIDEView::AssertValid() const
{
	CView::AssertValid();
}

void CJarvisIDEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJarvisIDEDoc* CJarvisIDEView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJarvisIDEDoc)));
	return (CJarvisIDEDoc*)m_pDocument;
}
#endif //_DEBUG


// CJarvisIDEView message handlers
