#include "pch.h"
#include "CRuntimeClass.h"

void AFXAPI AfxClassInit(CRuntimeClass* pNewClass)
{}

CObject* CRuntimeClass::CreateObject() { return nullptr; }
BOOL CRuntimeClass::IsDerivedFrom(const CRuntimeClass* pBaseClass) const { return false; }
CRuntimeClass* PASCAL CRuntimeClass::FromName(LPCSTR lpszClassName) { return nullptr; }
CRuntimeClass* PASCAL CRuntimeClass::FromName(LPCWSTR lpszClassName) { return nullptr; }
CObject* PASCAL CRuntimeClass::CreateObject(LPCSTR lpszClassName) { return nullptr; }
CObject* PASCAL CRuntimeClass::CreateObject(LPCWSTR lpszClassName) { return nullptr; }
void CRuntimeClass::Store(CArchive& ar) const {}
CRuntimeClass* PASCAL Load(CArchive& ar, UINT* pwSchemaNum) { return nullptr; }
