#ifdef BINARYFORMAT_EXPORTS
#define BINARYFORMAT_API __declspec(dllexport)
#else
#define BINARYFORMAT_API __declspec(dllimport)
#endif

class BINARYFORMAT_API CBinaryFormat {
public:
	CBinaryFormat(void);
};

extern BINARYFORMAT_API int nBinaryFormat;

BINARYFORMAT_API int fnBinaryFormat(void);
