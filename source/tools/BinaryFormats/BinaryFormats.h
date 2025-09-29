#ifdef BINARYFORMATS_EXPORTS
#define BINARYFORMATS_API __declspec(dllexport)
#else
#define BINARYFORMATS_API __declspec(dllimport)
#endif

class BINARYFORMATS_API CBinaryFormats {
public:
	CBinaryFormats(void);
};

extern BINARYFORMATS_API int nBinaryFormats;

BINARYFORMATS_API int fnBinaryFormats(void);
