#include "pch.h"
#include "CScintillaCtrl.h"

IMPLEMENT_DYNAMIC(CScintillaCtrl, CWnd)

CScintillaCtrl::CScintillaCtrl() noexcept : m_DirectFunction(0),
m_DirectPointer(0),
m_bCallDirect(TRUE)
{}

