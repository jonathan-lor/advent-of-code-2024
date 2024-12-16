#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	if(argc < 2) cout << "Input file must be provided" << "\n";
	cout << argv[1] << "\n";

	ifstream input(argv[1]);

	if(!input) {
		cout << "Error opening input" << "\n";
		return 1;
	}
	
	string line;
	int pos = 0; // position to begin string search from
	while(getline(input, line)) {
		while(line.find("mul", pos) != string::npos) {
			cout << line.find("mul", pos) << "\n";
		}
	}
	return 0;
}
