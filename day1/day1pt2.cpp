#include <iostream>
#include <map>
#include <fstream>
using namespace std;


int leftRightNum(string l) {
    string numStr = "";
    if (l.length() >= 3) {
        map<string, int> nums = {{"one", 1},{"two", 2},{"three", 3},{"four", 4},{"five", 5},{"six", 6},{"seven", 7},{"eight", 8},{"nine", 9}};
        int numLength = 0;
        
        for (int i = 0; i < l.length(); i++) {
            
            for (int e = 2; e < 6; e++) {
                if (isdigit(l[i])) {
                    numStr += l[i];
                    break;
                }else if (nums.find(l.substr(i,e)) != nums.end()) {
                    numStr += to_string(nums.at(l.substr(i,e)));
                    break;
                }
            }
            if (numStr != "") {
                break;
            }
            
        }
        for (int i = l.length(); i > 0; i--) {
            
            for (int e = 2; e < 6; e++) {
                if (isdigit(l[i])) {
                    numStr += l[i];
                    break;
                }else if (nums.find(l.substr(i,e)) != nums.end()) {
                    numStr += to_string(nums.at(l.substr(i,e)));
                    break;
                }
            }
            if (numStr.length() >= 2) {
                break;
            }
            
        }
    }
    
    if (l.length()<3) {
        for (int i = 0; i < l.length(); i++) {
            if (isdigit(l[i])) {
                numStr += l[i];
            }
        }
    }

    if (numStr.length()<=1) {
        numStr+=numStr;
    }
    
    // cout << numStr << endl;
    

    if (numStr != "") {
        return stoi(numStr);
    } else {
        return 0;
    }
    
}


int main() {
    int sum = 0;
    ifstream file("input.txt");
    string line;
    while(getline(file,line)) {
        sum += leftRightNum(line);
    }
    cout << sum << endl;
}
