#include <iostream>
#include <memory>
#include "Linker.h"

using namespace std;

int main(int argc, char** argv)
{
	shared_ptr<Linker> linker = make_shared<Linker>(argc, argv);
	int result = linker->link();
	cout << "Link result: " << result << "\n";
	return result;
}
