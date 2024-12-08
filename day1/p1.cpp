#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
using std::cout;
using std::sort;
using std::ifstream;

int main() {
	ifstream inputFile("input_p1.txt");
	if(!inputFile) {
		cout << "Error opening file" << "\n";
		return 1;
	}
	vector<int> v1, v2;
	string line;

	while(std::getline(inputFile, line)) {
		std::istringstream lineStream(line);
		int column1, column2;
		lineStream >> column1 >> column2;
		if(column1 && column2) {
			v1.emplace_back(column1);
			v2.emplace_back(column2);
		}
	}	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	int distanceSum = 0;
	int diff;
	for(int i = 0; i < v1.size(); i++) {
		diff = v1[i] - v2[i];
		distanceSum += diff < 0 ? diff * -1 : diff;
	}
	cout << distanceSum << "\n";
	std::unordered_map<int, int> umap;
	for(int num : v2) umap[num]++;

	long long newVal = 0;

	for(int num : v1) {
		newVal += num * umap[num]; 
	}
	cout << newVal << "\n";
}
