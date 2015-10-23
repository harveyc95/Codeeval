// Prime Numbers - https://www.codeeval.com/open_challenges/46/
// 
// Print out the prime numbers less than a given number N. 
// For bonus points your solution should run in N*(log(N)) time or better. 
// You may assume that N is always a positive integer.
// Your program should accept as its first argument a path to a filename. 
// Each line in this file is one test case. Each test case will contain an integer n < 4,294,967,295. E.g.
// INPUT SAMPLE:
// 10
// 20
// 100
// OUTPUT SAMPLE:
// 2,3,5,7
// 2,3,5,7,11,13,17,19
// 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
// 	Created by Harvey Chen on 23/10/2015.
//  Copyright (c) 2015 Harvey Chen. All rights reserved.

#include <iostream>
#include <fstream>
#include <math.h>

void SieveOfEratosthenes (bool array[], unsigned long long range) {
	
	array[0] = 0;
	array[1] = 0;
	for (unsigned long long i = 2; i <= range; i++) { // set all to true
		array[i] = 1;
	}
	unsigned long long upperBound = abs(ceil(sqrt(range)));
	for (int i = 2; i <= upperBound; i++) {
		if (array[i]) {
			for (unsigned long long j = i*i; j <= range; j += i) {
				array[j] = 0;
			}
		}
	}
	return;
}

bool isPrime (unsigned long long n) {
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n%2 == 0)
		return false;
	unsigned long long m = sqrt(n);

	for (unsigned long long i = 3; i <= m; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

int main (int argc, char *argv[]) {
	std::ifstream input_file(argv[1]);	// open the input file
	unsigned long long seiveRange = 4967295;
	bool array[seiveRange + 1];
	SieveOfEratosthenes(array, seiveRange + 1);

	for (unsigned long long i = 0; i < seiveRange; i++)
		if (array[i]) printf("%d ", i);
	
	unsigned long long N;
	while(input_file) {
		input_file >> N;
		printf("2");
		// if (N < 94967295) {
			for (unsigned long long i = 3; i < N; i++)
				if (array[i])	printf(",%llu",i);
		// }
	}
}