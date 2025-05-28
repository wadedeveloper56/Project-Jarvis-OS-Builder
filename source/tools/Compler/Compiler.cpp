#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool bit16 = false;
bool bit32 = false;
bool bit64 = false;

int main(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		char* argument = argv[i];
		if (strcmp("-bit16", argv[1]) == 0) {
			bit16 = true;
		}
		else if (strcmp("-bit32", argv[1]) == 0) {
			bit32 = true;
		}
		else if (strcmp("-bit64", argv[1]) == 0) {
			bit64 = true;
		}
	}
	return 0;
}