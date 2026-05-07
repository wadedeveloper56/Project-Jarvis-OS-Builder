#include "pch.h"
#include "preprocessor.h"

using namespace std;
using namespace WadeSpace::PreProcessor;

NonExistingFilesCache::NonExistingFilesCache() {}

bool NonExistingFilesCache::contains(const string& path) {
	lock_guard<mutex> lock(m_mutex);
	return (m_pathSet.find(path) != m_pathSet.end());
}

void NonExistingFilesCache::add(const string& path) {
	lock_guard<mutex> lock(m_mutex);
	m_pathSet.insert(path);
}

void NonExistingFilesCache::clear() {
	lock_guard<mutex> lock(m_mutex);
	m_pathSet.clear();
}
