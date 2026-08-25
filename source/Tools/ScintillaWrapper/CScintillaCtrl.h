#pragma once

#include <afxwin.h>
#include "Scintilla.h"
#include <sal.h>

class AFX_EXT_CLASS CScintillaCtrl :  public CWnd
{
	public:
		//Constructors / Destructors
		CScintillaCtrl() noexcept;

protected:
	DECLARE_DYNAMIC(CScintillaCtrl)

	//Member variables
	BOOL    m_bCallDirect;
	LRESULT m_DirectFunction;
	LRESULT m_DirectPointer;
};

