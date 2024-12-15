#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

using std::vector;
using std::abs;
using std::ifstream;
using std::istringstream;
using std::getline;
using std::cout;
using std::string;
using std::stringstream;


bool checkLineBruteForce(string line) {
	stringstream lineStream(line);

	vector<int> nums;

	int val;

	while(lineStream >> val) nums.emplace_back(val);

	// checking each possible permutation of the line
	int n = nums.size();
	for(int i = -1; i < n; i++) {
		// i is the index we are skipping in each iteration
		// start i at -1 to first check if unmodified is safe	
		// set pointers
		int p1, p2;
		if(i == 0) {
			p1 = 1;
			p2 = 2;
		} else if(i == 1) {
			p1 = 0;
			p2 = 2;
		} else {
			p1 = 0;
			p2 = 1;
		}
		bool inc = false, dec = false;
		bool isSafe = true;

		while(p2 < n) {
			
			int v1 = nums[p1];
			int v2 = nums[p2];

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
			p1 = p2;
			p2++;
			if(p2 == i) p2++;
		}	
		if(isSafe) return true;	
	}
	return false;
}

int main() {
	ifstream input("input.txt");

	if(!input) {
		cout << "error opening file" << "\n";
		return 1;
	}
	
	string line;
	int numSafe = 0;	
	while(getline(input, line)) {
//		stringstream lineStream(line);
//		int v1, v2;
//		bool inc = false, dec = false;
//		// bandaid fix for above flags messing with tolerating up to 1 bad
//		bool prevInc, prevDec;
//		bool isSafe = true;	
//		int numBad = 0; // we can tolerate up to 1 bad level in each line
//		lineStream >> v1;
//		while(lineStream >> v2) {
//			if(abs(v2 - v1) > 3 || v2 - v1 == 0) {
//				if(numBad == 0) {
//					numBad++;
//					continue;	
//				} else {
//					isSafe = false;
//					break;
//				}
//			}
//			prevInc = inc;
//			prevDec = dec;
//			dec = dec || v2 - v1 < 0; // this causes bug because it line will always be unsafe even if only one change in direction because flag stays set
//			
//			inc = inc || v2 - v1 > 0;
//			if(dec == inc) {
//				if(numBad == 0) {
//					inc = prevInc;
//					dec = prevDec;
//					numBad++;
//					continue;	
//				} else {
//					isSafe = false;
//					break;
//				}
//			}
//			v1 = v2;
//		}
//		isSafe ? numSafe++ : numSafe = numSafe;
//		cout << isSafe << "\n";
		if(checkLineBruteForce(line)) numSafe++; 
	}
	cout << numSafe;

	return 0;
}
