#pragma once
#include <afx.h>
#include <list>

using namespace std;

class CProjectData : public CObject
{
    DECLARE_SERIAL(CProjectData) // Allows object serialization

public:
    CString m_projectName;
    int m_version;
    CStringList m_sourceFiles;
    CStringList m_headerFiles;
	CStringList m_resourceFiles;
	CString m_outputDirectory;
	CString m_intermediateDirectory;
	CString m_buildConfiguration;
	CStringList m_linkedLibraries;
	CStringList m_preprocessorDefinitions;
	CStringList m_includeDirectories;

    CProjectData();
    virtual void Serialize(CArchive& ar) override;
};
