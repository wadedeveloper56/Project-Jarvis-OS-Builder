#include "globals.h"
#include "Linker.h"

using namespace std;

int main(int argc, char *argv[])
{
	Linker* linker = new Linker();
	linker->mainLine();
	delete linker;
	return((LinkState & LINK_ERROR) ? 1 : 0);
}

