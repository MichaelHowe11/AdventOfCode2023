#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
using namespace std;

map<string,int> resetColors(map<string,int> colors) {
    colors.at("red") = 0;
    colors.at("green") = 0;
    colors.at("blue") = 0;
    return colors;
}

bool checkPoss(map<string,int> colors) {
    if (colors.at("red") <= 12 && colors.at("green") <= 13 && colors.at("blue") <= 14) {
        return true;
    }
    return false;
}




int main() {
	ifstream file("input.txt");
	string line;


	map<string,int> colors = {{"red",0},{"green",0},{"blue",0}};

	int sum = 0;

	while(getline(file,line)) {
		cout << line << endl;
		int gameNum = line[5]-'0';
		if (isdigit(line[6]) && !isdigit(line[7])) {
			gameNum = stoi(line.substr(5,2));
		}	
	    	line+=";";


		for (int i = 0; i < line.length(); i++) {
			for (int e = 3; e < 6; e++) {
				if (colors.find(line.substr(i,e)) != colors.end()) {
					if (isdigit(line[i-3])) {
						colors.at(line.substr(i,e))+=stoi(line.substr(i-3,2));
					} else {
						colors.at(line.substr(i,e))+=line[i-2]-'0';
					}
				}
			}
			if (line[i]==';') {
				cout << "red: " << colors.at("red") << endl;
				cout << "green: " << colors.at("green") << endl;
				cout << "blue: " << colors.at("blue") << endl;


				if (checkPoss(colors) && i==line.length()-1) {
					sum+=gameNum;
					cout << "Possible at " << gameNum << endl;
					break;
				} else if (!checkPoss(colors)) {
					break;
				}
				colors = resetColors(colors);
				
				
			} 
		}



		colors = resetColors(colors);
	}

	cout << sum << endl;



}
    


