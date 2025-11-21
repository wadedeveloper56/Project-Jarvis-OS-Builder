
// IDEView.cpp : implementation of the CIDEView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "IDE.h"
#endif

#include "IDEDoc.h"
#include "IDEView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIDEView

IMPLEMENT_DYNCREATE(CIDEView, CView)

BEGIN_MESSAGE_MAP(CIDEView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CIDEView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CIDEView construction/destruction

CIDEView::CIDEView() noexcept
{
	// TODO: add construction code here

}

CIDEView::~CIDEView()
{
}

BOOL CIDEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CIDEView drawing

void CIDEView::OnDraw(CDC* /*pDC*/)
{
	CIDEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CIDEView printing


void CIDEView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIDEView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIDEView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIDEView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CIDEView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CIDEView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CIDEView diagnostics

#ifdef _DEBUG
void CIDEView::AssertValid() const
{
	CView::AssertValid();
}

void CIDEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIDEDoc* CIDEView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIDEDoc)));
	return (CIDEDoc*)m_pDocument;
}
#endif //_DEBUG


// CIDEView message handlers
