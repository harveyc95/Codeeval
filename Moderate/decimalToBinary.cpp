// Decimal to Binary - https://www.codeeval.com/open_challenges/27/
// 
// 	Created by Harvey Chen on 24/10/2015.
//  Copyright (c) 2015 Harvey Chen. All rights reserved.

#include <iostream>
#include <fstream>
#include <math.h>

void binary(int N) {
	int remain;
	if (N <= 1) {
		printf("%d", N);
		return;
	}
	remain = N%2;
	binary(N >> 1);
	printf("%d", remain);
}

int main (int argc, char *argv[]) {
	std::ifstream input_file(argv[1]);	// open the input file
	int N;
	while(input_file) {
		input_file >> N;
		binary(N);
		printf("\n");
	}
}