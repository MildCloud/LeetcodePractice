#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int lengthOfLongestSubstring(string s) {
    int i = 0;
    int j = 0;
    int result = 0;
    unordered_map<char, int> map;
    while (i < s.size()) {
        while (j < s.size()) {
            if (map.find(s[j]) == map.end()) {
                map[s[j]] = j;
                j++;
            }
            else {
                break;
            }
        }
        int currentLen = j - i;
        if (currentLen > result || result == 0) {
            result = currentLen;
        }
        if (j >= s.size()) {
            break;
        }
        if (map.find(s[j]) != map.end()) {
            int k = i;
            i = map[s[j]] + 1;
            for (; k <= i - 1; k++) {
                map.erase(s[k]);
            }
        }
    }
    return result;
}


int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}
