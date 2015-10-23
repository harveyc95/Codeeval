// Sample code to read in test cases:
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    stringstream sline;
    int X, Y, N;
    while (getline(stream, line)) {
    	sline << line;
    	sline >> X;
    	sline >> Y;
    	sline >> N;

    	for (int i = 1; i <= N; i++) {
    		if (i%X == 0 && i%Y == 0) {
    			cout << "FB ";
    		} else if (i%X == 0) {
    			cout << "F ";
    		} else if (i%Y == 0) {
    			cout << "B ";
    		} else{
    			cout << i << " ";
    		}
    	}
    	cout << "\n";

    	sline.clear();

        // Do something with the line
        
    }
    return 0;
}