#include "Assembler.h"

void tolower_tab_init(void)
{
	int i;

	for (i = 0; i < 256; i++)
		nasm_tolower_tab[i] = tolower(i);
}

char nasm_tolower(char x)
{
	return nasm_tolower_tab[(unsigned char)x];
}

int nasm_memicmp(const char* s1, const char* s2, size_t n)
{
	unsigned char c1, c2;
	int d;

	while (n--) {
		c1 = nasm_tolower(*s1++);
		c2 = nasm_tolower(*s2++);
		d = c1 - c2;
		if (d)
			return d;
	}
	return 0;
}
