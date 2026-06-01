#include <iostream>
#include "Linker.h"

using namespace std;

int main(int argc, char** argv)
{
	Linker linker(argc, argv);
	int result = linker.link();
	cout << "Link result: " << result << "\n";
	return result;
}
