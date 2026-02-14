#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;


int main() {
	string input = "input.txt";


	ifstream file(input);
	string line = "";

	if (!file){
		cout << "File not found." << endl;
	}

	


	int sum = 0;
	string numString = "";
	while (getline(file,line)) {
		for (int i = 0; i < line.length(); i++) {
			if ((isdigit(line[i]))) {
				numString+=line[i];
				break;	
			}				
		}

		for (int i = line.length()-1; i >= 0; i--) {
			if (isdigit(line[i])) {
				numString+=line[i];
				break;
			}
		}

		sum+=stoi(numString);
		numString="";
	}
	cout << sum << endl;



}
