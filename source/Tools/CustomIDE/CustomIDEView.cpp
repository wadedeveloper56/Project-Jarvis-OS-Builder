
// CustomIDEView.cpp : implementation of the CCustomIDEView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CustomIDE.h"
#endif

#include "CustomIDEDoc.h"
#include "CustomIDEView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCustomIDEView

IMPLEMENT_DYNCREATE(CCustomIDEView, CView)

BEGIN_MESSAGE_MAP(CCustomIDEView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCustomIDEView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CCustomIDEView construction/destruction

CCustomIDEView::CCustomIDEView() noexcept
{
	// TODO: add construction code here

}

CCustomIDEView::~CCustomIDEView()
{
}

BOOL CCustomIDEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCustomIDEView drawing

void CCustomIDEView::OnDraw(CDC* /*pDC*/)
{
	CCustomIDEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCustomIDEView printing


void CCustomIDEView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCustomIDEView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCustomIDEView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCustomIDEView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCustomIDEView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCustomIDEView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCustomIDEView diagnostics

#ifdef _DEBUG
void CCustomIDEView::AssertValid() const
{
	CView::AssertValid();
}

void CCustomIDEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCustomIDEDoc* CCustomIDEView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCustomIDEDoc)));
	return (CCustomIDEDoc*)m_pDocument;
}
#endif //_DEBUG


// CCustomIDEView message handlers
