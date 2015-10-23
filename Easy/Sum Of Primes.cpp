#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

bool isPrime (int n);

using namespace std;
int main(int argc, char *argv[]) {

	int numberOfPrimes = 0;
	int sumOfPrimes = 0;
	int n = 1;

	while (numberOfPrimes < 1000) {
		if (isPrime(n)) {
			numberOfPrimes++;
			sumOfPrimes += n;
		}
		n++;
	}

	cout << sumOfPrimes;

	return 0;
}

bool isPrime (int n) {
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n%2 == 0)
		return false;
	int m = sqrt(n);

	for (int i = 3; i <= m; i++) {
		if (n%i == 0)
			return false;
	}

	return true;
}