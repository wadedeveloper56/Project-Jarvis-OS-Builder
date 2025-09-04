#ifndef _COFFSymbolTable_H_
#define _COFFSymbolTable_H_

class COFFSymbolTable;

class COFFSymbol
{
	PSTR 			m_pStringTable;
	PIMAGE_SYMBOL 	m_pSymbolData;
	DWORD			m_index;
	PSTR			m_pszShortString;
	char			m_szTypeName[16];

	void	CleanUp(void);

public:

	COFFSymbol(PIMAGE_SYMBOL pSymbolData, PSTR pStringTable, DWORD index);
	~COFFSymbol();
	DWORD GetIndex();
	PSTR  GetName();
	DWORD GetValue();
	SHORT GetSectionNumber();
	WORD  GetType();
	PSTR  GetTypeName();
	BYTE  GetStorageClass();
	PSTR  GetStorageClassName();
	BOOL  GetNumberOfAuxSymbols();
	BOOL  GetAuxSymbolAsString(PSTR pszBuffer, unsigned cbBuffer);
	friend class COFFSymbolTable;
};

typedef COFFSymbol* PCOFFSymbol;

class COFFSymbolTable
{
private:

	PIMAGE_SYMBOL	m_pSymbolBase;
	unsigned 		m_cSymbols;
	PSTR			m_pStringTable;

public:

	COFFSymbolTable(PVOID pSymbolBase, unsigned cSymbols);
	~COFFSymbolTable();

	unsigned GetNumberOfSymbols(void) { return m_cSymbols; }

	PCOFFSymbol GetNextSymbol(PCOFFSymbol);

	PCOFFSymbol GetNearestSymbolFromRVA(DWORD rva, BOOL fExact);

	PCOFFSymbol GetSymbolFromIndex(DWORD index);
};

typedef COFFSymbolTable* PCOFFSymbolTable;

#endif
