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
	std::ifstream input("beads.in");
	int len;
	std::vector<int> locs;
	std::string necklace;
	input >> len >> necklace;
	input.close();
	necklace += necklace; len *= 2;
	char init = '\n';
	char currcolor = necklace[0];
	int max = 0;
	for (int i = 0; i < len; i++) {
		int pos;
		int num = 0;
		if (necklace[i] == currcolor) {
			num++;
		}
		else if (necklace[i] == 'w') {
			num++;
		}
		else {
			if (num > max) max = num;
			pos = i;
			num = 1;
			currcolor = necklace[i];
		}

	}

	std::ofstream output("beads.out");
	output << max << "\n";
	output.close();
	return 0;
}
