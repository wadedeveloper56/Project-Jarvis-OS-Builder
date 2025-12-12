#include "globals.h"
#include "Linker.h"

using namespace std;

int main(int argc, char *argv[])
{
	Linker linker;
	linker.mainLine();
	return((LinkState & LINK_ERROR) ? 1 : 0);
}

