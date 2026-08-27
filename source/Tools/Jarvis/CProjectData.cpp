#include "pch.h"
#include "CProjectData.h"

IMPLEMENT_SERIAL(CProjectData, CObject, 1) // 1 is the schema version

CProjectData::CProjectData() : m_version(1) {}

void CProjectData::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        // Writing to the binary file
        ar << m_projectName;
        ar << m_version;
        m_sourceFiles.Serialize(ar); // CStringList natively handles its binary storage
        m_headerFiles.Serialize(ar);
		m_resourceFiles.Serialize(ar);
        ar << m_outputDirectory;
		ar << m_intermediateDirectory;
		ar << m_buildConfiguration;
		m_linkedLibraries.Serialize(ar);
		m_preprocessorDefinitions.Serialize(ar);
		m_includeDirectories.Serialize(ar);
    }
    else
    {
        // Reading from the binary file
        ar >> m_projectName;
        ar >> m_version;
        m_sourceFiles.Serialize(ar);
        m_headerFiles.Serialize(ar);
		m_resourceFiles.Serialize(ar);
        ar >> m_outputDirectory;
		ar >> m_intermediateDirectory;
		ar >> m_buildConfiguration;
		m_linkedLibraries.Serialize(ar);
		m_preprocessorDefinitions.Serialize(ar);
		m_includeDirectories.Serialize(ar);
    }
}