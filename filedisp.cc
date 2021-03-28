#include <iostream>
#include <string>
#include <cstring>
//hey
using namespace std;

int main(int argc, char **argv){
	string line = "";
	int i=0;
	while (getline(cin, line)) {
		i++;
		if ((strcmp(argv[1], "-d") == 0) && (i == 1)){
			cout << line << endl;
			return 0;
		}
		if ((strcmp(argv[1], "-f") == 0) && (i == 2)){
			cout << line << endl;
			return 0;
		}
		if ((strcmp(argv[1], "-b") == 0) && (i == 3)){
			cout << line << endl;
			return 0;
		}
	}
}
