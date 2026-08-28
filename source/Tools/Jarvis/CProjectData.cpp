#include "pch.h"
#include "CProjectData.h"

IMPLEMENT_SERIAL(CProjectData, CObject, 1) // 1 is the schema version

CProjectData::CProjectData() : m_version(1) {}

void CProjectData::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        // Writing to the binary file
        ar << m_version;
        ar << m_projectName;
        ar << m_outputDir;
        ar << m_intermediateDir;
        ar << m_projectDir;
        ar << m_projectBase;
        ar << m_bitSize;
    }
    else
    {
        // Reading from the binary file
        ar >> m_version;
        ar >> m_projectName;
        ar >> m_outputDir;
        ar >> m_intermediateDir;
        ar >> m_projectDir;
        ar >> m_projectBase;
        ar >> m_bitSize;
    }
}