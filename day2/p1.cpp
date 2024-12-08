#include <iostream>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::istringstream;
using std::getline;
using std::cout;

int main() {
	ifstream input("input.txt");

	if(input == nullptr) {
		cout << "error opening file" << "\n";
		return 1;
	}

	return 0;
}
