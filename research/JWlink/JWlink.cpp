#include "pch.h"
#include "Linker.h"

int main(int argc, char** argv)
{
	_argc = argc;
	_argv = argv;
	Linker* linker = new Linker();
	linker->mainLine();
	delete linker;
	printf("Linker exited with code %d\n", (LinkState & LINK_ERROR) ? 1 : 0);
	return((LinkState & LINK_ERROR) ? 1 : 0);
}
