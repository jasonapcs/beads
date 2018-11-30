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
	int pos;
	int num = 0;
	int bestpos;
	for (int i = 0; i < len; i++) {
		if (necklace[i] == currcolor) {
			num++;
		}
		else if (necklace[i] == 'w') {
			num++;
		}
		else {
			if (num > max) {
				max = num;
				bestpos = i;
			}
			pos = i;
			num = 1;
			currcolor = necklace[i];
		}
	}

	currcolor = necklace[len - 1];
	int max2 = 0;
	int pos2;
	int num2 = 0;
	int bestpos2;
	for (int i = len - 1; i >= 0; i--) {
		if (necklace[i] == currcolor) {
			num2++;
		}
		else if (necklace[i] == 'w') {
			num2++;
		}
		else {
			if (num2 > max2) {
				max2 = num2;
				bestpos2 = i;
			}
			pos2 = i;
			num2 = 1;
			currcolor = necklace[i];
		}
	}

	currcolor = necklace[bestpos];
	int num3 = 0;
	for (int i = bestpos; i != -1; i++) {
		if (necklace[i] == currcolor) {
			num3++;
		}
		else if (necklace[i] == 'w') {
			num3++;
		}
		else {
			i = -1;
		}
	}

	int num4 = 0;
	for (int i = bestpos; i != -1; i--) {
		if (necklace[i] == currcolor) {
			num4++;
		}
		else if (necklace[i] == 'w') {
			num4++;
		}
		else {
			i = -1;
		}
	}

	int finalnum = num3 + num4 - 1;



	std::ofstream output("beads.out");
	output << finalnum << "\n";
	output.close();

	std::cout << finalnum;
	std::cin.get();
	return 0;
}
