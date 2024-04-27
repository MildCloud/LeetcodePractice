#include <iostream>
#include <vector>
using namespace std;


int lengthOfLongestSubstring (string s) {
    int maxLength = 0;
    string noRepeat = "";
    for (int i = 0; i < s.length(); i++) {
        int position = noRepeat.find(s[i]);
        if (position != -1) {
            noRepeat.erase(noRepeat.begin(), noRepeat.begin() + position + 1);
            noRepeat += s[i];
        }
        else {
            noRepeat += s[i];
            if (noRepeat.length() > maxLength) {
                maxLength = noRepeat.length();
            }
        }
    }
    return maxLength;
}


int main () {
    string input = "bbbbb";
    cout << lengthOfLongestSubstring(input) << endl;
    return 0;
}
