
// CustomIDEView.h : interface of the CCustomIDEView class
//

#pragma once

#include "scintilla.h"

class CCustomIDEView : public CView
{
protected: // create from serialization only
	CCustomIDEView() noexcept;
	DECLARE_DYNCREATE(CCustomIDEView)

// Attributes
public:
	CCustomIDEDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCustomIDEView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CustomIDEView.cpp
inline CCustomIDEDoc* CCustomIDEView::GetDocument() const
   { return reinterpret_cast<CCustomIDEDoc*>(m_pDocument); }
#endif

