#include "pch.h"
#include "ObjDump.h"

bool Descriptions;
bool InterpretComent;
bool quiet;
bool TranslateIndex;

int main(int argc, char* argv[])
{
	FILE* fp;
	//pgroup2     pg;
	char        file[_MAX_PATH];
	char* fn;
	int         i;
	char* list_file;
	FILE* fh;
	bool        is_intel;

	Descriptions = false;
	InterpretComent = true;
	TranslateIndex = false;
	list_file = NULL;
	is_intel = false;
	quiet = false;
	for (i = 1; i < argc; ++i) {
		if (argv[i][0] == '-') {
			switch (tolower(argv[i][1])) {
				case 'l':
					list_file = argv[i] + 2;
					if (*list_file == '=') {
						list_file++;
					}
					break;
				case 'd':
					Descriptions = true;
					break;
				case 'c':
					InterpretComent = false;
					break;
				case 'r':
					if (_strnicmp(argv[i] + 1, "rec=", 4) == 0) {
						if (rec_count < 10) {
							if (isdigit(argv[i][5])) {
								rec_type[rec_count++] = atoi(argv[i] + 5);
							}
							else {
								rec_type[rec_count++] = RecNameToNumber(argv[i] + 5);
							}
						}
						else {
							Output("Maximum 10 record type allowed.\n");
							OutputFini();
						}
					}
					else {
						DumpRaw = true;
					}
					break;
				case 'i':
					is_intel = false;
					break;
				case 'q':
					quiet = true;
					break;
				case 't':
					TranslateIndex = true;
					break;
				default:
					//usage();
					//leave(1);
					// never return
					break;
			}
		}
		else {
			break;
		}
	}

}
