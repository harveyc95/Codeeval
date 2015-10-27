// Number Pairs - https://www.codeeval.com/open_challenges/34/
// 
// 	Created by Harvey Chen on 23/10/2015.
//  Copyright (c) 2015 Harvey Chen. All rights reserved.

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

int main (int argc, char *argv[]) {
	std::ifstream input_file(argv[1]);	// open the input file
	char dummy;
	std::vector<int> sorted_input;
	
	int N, X;
	while(input_file) {
		input_file >> N;
		input_file >> dummy;
		sorted_input.push_back(N);
		if (dummy == ';') {
			input_file >> X;
		}
		std::vector<int> v_output;
		for (auto &i : sorted_input) {
			if (std::vector::binary_search(sorted_input.begin(), sorted_input.end(), X - i)) {
				v_output.push_back(i);
				v_output.push_back(X - i);
				sorted_input.erase(std::remove(sorted_input.begin(), sorted_input.end(), i), sorted_input.end());
			}
		}
		if (!v_output.size()) {
			printf("NULL");
		} else { // v_output.size() >= 2
			printf("%d,", v_output.front());
			for (auto i = v_output.begin() + 1; i != v_output.end(); i++) {
				printf(",%d", *i);
			}
			if (v_output.size() > 2) {
				for (auto i = v_output.begin() + 3; i != v_output.end(); i++) {
					printf(";%d,%d", *i, *i++);
				}
			}
		} 
	}
}