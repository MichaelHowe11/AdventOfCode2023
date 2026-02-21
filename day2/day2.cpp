#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

map<string,int> resetColors(map<string,int> colors) {
    colors.at("red") = 0;
    colors.at("green") = 0;
    colors.at("blue") = 0;
    return colors;
}

bool checkPossibility(map<string,int> colors) {
    if (colors.at("red") <= 12 && colors.at("green") <= 13 && colors.at("blue") <= 14) {
        return true;
    }
    return false;
}




int main() {
    ifstream file("sample.txt");
    string line;


    map<string,int> colors = {{"red",0},{"green",0},{"blue",0}};


    int gameN = 0;
    int possibleGames = 0;


    while(getline(file,line)) {
        cout << line << endl;
        // cout << stoi(&line[5]) << endl;
        gameN = stoi(&line[5]);
        bool isPossible = false;
        for (int i = 8; i < line.length(); i++) {
            // if (colors.at("red") != 0) {
            //     cout << colors.at("blue") << endl;
            // }
            if (line[i] == ';') {
                cout << colors.at("red") << " " << colors.at("green") << " " << colors.at("blue") << " " << endl;
                if (checkPossibility(colors) && !isPossible) {
                    possibleGames+=gameN;
                    isPossible = true;
                } else if (!checkPossibility(colors) && isPossible){
                    possibleGames-=gameN;
                    break;
                } else if (!checkPossibility(colors)) {
                    break;
                }
                colors = resetColors(colors);
            } else if (isdigit(line[i])) {
                for (int e = 3; e < 6; e++) {
                    
                    if (colors.find(line.substr(i+2,e)) != colors.end()) {
                        string num = "";
                        
                        if (isdigit(line[i-1])) {
                            num+=line[i-1];
                            num+=line[i];
                        } else {
                            num = line[i];
                        }
                        colors.at(line.substr(i+2,e)) += stoi(num);
                        
                        cout << "{" << line.substr(i+2,e) << stoi(num) << "}" << endl;
                        
                        
                        num = "";
                        // break;
                    }
                }
            }
            
            
            

        }
        
        cout << possibleGames << endl;
        colors = resetColors(colors);
        
    }
    

}