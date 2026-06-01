#pragma once

class Linker
{
	int argc;
	char** argv;
public:
	Linker(int argc, char** argv);
	~Linker();
	int link();
};

