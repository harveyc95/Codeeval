// Counting Primes - https://www.codeeval.com/open_challenges/63/
// 
// Given two integers N and M, count the number of prime numbers between N and M (both inclusive)
// Your program should accept as its first argument a path to a filename. 
// Each line in this file contains two comma separated positive integers. E.g.
// INPUT SAMPLE:
// 2, 10
// 20, 30
// OUTPUT SAMPLE:
// 4
// 2
// 	Created by Harvey Chen on 23/10/2015.
//  Copyright (c) 2015 Harvey Chen. All rights reserved.

#include <iostream>
#include <fstream>
#include <math.h>

void SieveOfEratosthenes (bool array[], int range) {
	
	array[0] = 0;
	array[1] = 0;
	for (int i = 2; i <= range; i++) { // set all to true
		array[i] = 1;
	}
	int upperBound = ceil(sqrt(range));
	for (int i = 2; i <= upperBound; i++) {
		if (array[i]) {
			for (int j = i*i; j <= range; j += i) {
				array[j] = 0;
			}
		}
	}
	return;
}

int main (int argc, char *argv[]) {
	std::ifstream input_file(argv[1]);	// open the input file
	int seiveRange = 1000000;
	bool array[seiveRange + 1];
	SieveOfEratosthenes(array, seiveRange + 1);
	
	int M, N, primeCount;
	char dummy;
	while(input_file) {
		input_file >> N >> dummy >> M;
		primeCount = 0;
		for (int i = N; i <= M; i++) {
			if (array[i])	primeCount++;
		}
		printf("%d\n", primeCount);
	}

}