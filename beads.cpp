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
	int num = 0;
	int finalnum = 0;
	
	for (int i = 0; i < len; i++) {
		char currcolor = necklace[i];
		for (int j = i; j != -1; j++){
			if (currcolor == 'w'){
				currcolor = necklace[j];
			}
			if (necklace[j] == currcolor || necklace[j] == 'w') {
				num++;
			}
			else {
				j = -1;
			}
		}
		for (int j = i - 1; j != -1; j--){
			if (currcolor == 'w'){
				currcolor = necklace[j];
			}
			if (necklace[j] == currcolor || necklace[j] == 'w') {
				num++;
			}
			else {
				j = -1;
			}
		}
		
		if (finalnum < num)
			num = finalnum;
	}
	
	if (finalnum > len / 2)
		finalnum = len / 2;
	
	std::ofstream output("beads.out");
	output << finalnum << "\n";
	output.close();

	return 0;
}
