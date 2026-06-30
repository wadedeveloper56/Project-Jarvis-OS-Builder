#include <iostream>
#include <memory>
#include "Linker.h"

using namespace std;

int main(int argc, char** argv)
{
	Linker *linker = new Linker(argc, argv);
	int result = linker->link(nullptr);
	cout << "Link result: " << result << "\n";
	delete linker;
	return result;
}
