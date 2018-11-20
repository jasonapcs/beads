/*
ID: jason.z2
LANG: C++
PROG: beads
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	int len;
	std::string necklace;
	int amt = 0;
	std::vector<short int> breakPoints;

	std::ifstream input("beads.in");
	input >> len >> necklace;
	input.close();


	len *= 2;
	necklace += necklace;

	std::string first = necklace;
	std::string second = necklace;
	char past = necklace[0];

	for (int i = 1; i < len - 1; i++) {
		if (necklace[i] != past && necklace[i] != 'w') {
			breakPoints.push_back(i);
		}
		past = necklace[i];
	}

	past = necklace[len - 1];
	for (int i = len - 2; i >= 0; i--) {
		if (necklace[i] != past && necklace[i] != 'w') {
			breakPoints.push_back(i);
		}
		past = necklace[i];
	}
	
	std::ofstream output("beads.out");

	output << amt << "\n";
	output.close();

	return 0;
}
