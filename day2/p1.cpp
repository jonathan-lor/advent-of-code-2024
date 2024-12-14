#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using std::abs;
using std::ifstream;
using std::istringstream;
using std::getline;
using std::cout;
using std::string;
using std::stringstream;

int main() {
	ifstream input("input.txt");

	if(!input) {
		cout << "error opening file" << "\n";
		return 1;
	}
	
	string line;
	int numSafe = 0;	
	while(getline(input, line)) {
		stringstream lineStream(line);
		int v1, v2;
		bool inc = false, dec = false;
		bool isSafe = true;	
		lineStream >> v1;
		while(lineStream >> v2) {
			if(abs(v2 - v1) > 3 || v2 - v1 == 0) {
				isSafe = false;
				break;
			}
			dec = dec || v2 - v1 < 0;
			inc = inc || v2 - v1 > 0;
			if(dec == inc) {
				isSafe = false;
				break;
			}
			v1 = v2;
		}
		isSafe ? numSafe++ : numSafe = numSafe;
	}
	cout << numSafe;

	return 0;
}
