#include <iostream>
#include <string>
#include <vector>
using namespace std;


void help(string digits, string letters, vector<string>& v) {
    if (digits.length() == 0) {
        v.push_back(letters);
    }
    else {
        int numCellLetters = 3;
        if (digits[0] == '9' || digits[0] == '7') {
            numCellLetters = 4;
        }
        for (int i = 0; i < numCellLetters; i++) {
            char letter = 'a' + 3*(digits[0]-'2') + i;
            if (digits[0] >= '8') {
                letter += 1;
            }
            help(digits.substr(1), letters + letter, v);
        }
    }
}

vector<string> letterCombinations(string digits) {  
    vector<string> v;
    if (digits.length() == 0) {
        return v;
    }
    help(digits, "", v);
    return v;
}


int main() {
    cout << '4' - '2' << endl;
    string s = "asdfa";
    cout << s.substr(3) << endl;
    cout << 's' + s << endl;
    return 0;
}
