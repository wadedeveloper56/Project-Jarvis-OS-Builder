#pragma once
#include <afx.h>
#include <list>

using namespace std;

class CProjectData : public CObject
{
    DECLARE_SERIAL(CProjectData) // Allows object serialization

public:
    int m_version;

	CString m_projectName;
	CString m_outputDir;
	CString m_intermediateDir;
	CString m_projectDir;
	CString m_projectBase;
	int m_bitSize; // 16,32 or 64	

    CStringList m_sourceFiles;
    CStringList m_headerFiles;
	CStringList m_resourceFiles;
	CStringList m_linkedLibraries;
	CStringList m_preprocessorDefinitions;
	CStringList m_includeDirectories;


    CProjectData();
    virtual void Serialize(CArchive& ar) override;
};
