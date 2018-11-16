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
	int currBeads = 0;
	std::vector<int> breakPoints(1);
	char past;
	std::string necklace;
	
	std::ifstream input("beads.in");
	input >> len >> necklace;
	input.close();
	
	necklace += necklace;


	past = necklace[0];
	len *= 2;

	std::string firstrun = necklace;

	for (int i = 1; i < len; i++) {
		if (necklace[i] == 'w') {
			firstrun[i] = past;
		}
		if ((firstrun[i] != past) && (past != 'w')) {
			breakPoints.push_back(0);
			breakPoints[currBeads] = i;
			currBeads++;
		}

		past = firstrun[i];
	}

	past = necklace[len - 1];

	std::string secondrun = necklace;

	for (int i = len - 1; i >= 0; i--) {
		if (necklace[i] == 'w') {
			secondrun[i] = past;
		}
		if ((secondrun[i] != past) && (past != 'w')) {
			breakPoints.push_back(0);
			breakPoints[currBeads] = i;
			currBeads++;
		}

		past = secondrun[i];
	}

	//breakPoints.erase(breakPoints.begin() + currBeads);

	int amt = 0;
	int temp = breakPoints[0] - breakPoints[breakPoints.size()] - 1;
	amt = temp;

	if (breakPoints.size() > 1)
		if (breakPoints.size() > 2) {
			temp = breakPoints[1] - breakPoints[0] - 1 + necklace.size() - breakPoints[breakPoints.size() / 2];
			amt = temp;
			for (int i = 1; i < breakPoints.size(); i++) {
				temp = breakPoints[i + 1] - breakPoints[i - 1] - 1;
				if (temp > amt) amt = temp;
			}
		}
		else amt = temp;
	else amt = necklace.size() / 2;


	std::ofstream output("beads.out");

	output << amt << "\n";
	output.close();

	return 0;
}
