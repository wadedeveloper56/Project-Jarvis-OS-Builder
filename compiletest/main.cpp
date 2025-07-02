#include <fstream>
#include "scanner.h"
#include "parser.hpp"
#include "interpreter.h"

using namespace WadeSpace;
using namespace std;

int main(int argc, char* argv[]) {
	ifstream rfile;
	rfile.open(argv[1], ifstream::in);
	int res = 0;

	if (rfile.is_open()) {
		Interpreter i;
		i.switchInputStream(&rfile);
		res = i.parse();
		cout << "Parse complete. Result = " << res << endl;
	}
	else {
		cerr << "Error opening file " << argv[1] << endl;
		res = -1;
	}
	rfile.close();
	return res;
}
