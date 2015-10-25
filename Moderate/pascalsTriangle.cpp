// Pascal's Triangle - https://www.codeeval.com/open_challenges/66/
// 
// 	Created by Harvey Chen on 24/10/2015.
//  Copyright (c) 2015 Harvey Chen. All rights reserved.

#include <iostream>
#include <fstream>
#include <math.h>

void printPascalTriangle(int N) {
	int array[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == 0 || i == j)	array[i][j] = 1;
			else array[i][j] = 0;
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < i; j++) {
			array[i][j] = array[i-1][j-1] + array[i-1][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", array[i][j]);
		}
	}
	printf("\n");
}

int main (int argc, char *argv[]) {
	std::ifstream input_file(argv[1]);	// open the input file

	int N;
	while(input_file) {
		input_file >> N;
		printPascalTriangle(N);		
	}
}

