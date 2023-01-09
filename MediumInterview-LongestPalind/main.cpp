#include <iostream>
using namespace std;


string longestPalindrome (string s) {
    if (s.size() == 1) {
        return s;
    }
    string maxPalindrome = "";
    for (size_t i = 0; i + 1 < s.size(); i++) {
        //don't use i < s.size() - 1 
        string tempPalindrome;
        tempPalindrome += s[i];
        for (size_t j = 1;;j++) {
            if ((i < j) || (i + j >= s.size())) {
                // i - j < 0 won't work
                break;
            }
            if (s[i - j] == s[i + j]) {
                tempPalindrome += s[i + j];
                tempPalindrome = tempPalindrome.insert(0, 1, s[i - j]);
            }
            else {
                break;
            }
        }
        if (tempPalindrome.size() > maxPalindrome.size()) {
            maxPalindrome = tempPalindrome;
        }
    }
    for (size_t i = 0; i + 1 < s.size(); i++) {
        if (s[i] == s[i + 1]) {
            string tempPalindrome;
            tempPalindrome += s[i];
            tempPalindrome += s[i + 1];
            for (size_t j = 1;;j++) {
                if ((i < j) || (i + 1 + j >= s.size())) {
                    break;
                }
                if (s[i - j] == s[i + 1 + j]) {
                    tempPalindrome += s[i + 1 + j];
                    tempPalindrome = tempPalindrome.insert(0, 1, s[i - j]);
                }
                else {
                    break;
                }
            }
            if (tempPalindrome.size() > maxPalindrome.size()) {
                maxPalindrome = tempPalindrome;
            }
        }
    }
    return maxPalindrome;
}


int main () {
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("bb") << endl;
    return 0;
}
