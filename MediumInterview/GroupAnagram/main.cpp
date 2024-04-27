#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


// vector<vector<string>> groupAnagrams (vector<string>& strs) {
//     vector<vector<string>> anagrams;
//     vector<bool> isChecked(strs.size(), false);
//     for (size_t i = 0; i < strs.size(); i++) {
//         if (!isChecked[i]) {
//             isChecked[i] = true;
//             int countLetterStd[26] = {0};
//             vector<string> anagram;
//             for (size_t j = 0; j < strs[i].size(); j++) {
//                 countLetterStd[strs[i][j] - 'a']++;
//             }
//             anagram.push_back(strs[i]);
//             for (size_t j = i+ 1; j < strs.size(); j++) {
//                 int countLetter[26] = {0};
//                 if (!isChecked[j]) {
//                     for (size_t k = 0; k < strs[j].size(); k++) {
//                         countLetter[strs[j][k] - 'a']++;
//                     }
//                     bool isAnagram = true;
//                     for (int k = 0; k < 26; k++) {
//                         if (countLetter[k] != countLetterStd[k]){
//                             isAnagram = false;
//                         }
//                     }
//                     if (isAnagram) {
//                         isChecked[j] = true;
//                         anagram.push_back(strs[j]);
//                     }
//                 }
//             }
//             anagrams.push_back(anagram);
//         }
//     }
//     return anagrams;
// }

vector<vector<string>> groupAnagrams (vector<string>& strs) {
    vector<vector<string>> anagrams;
    unordered_map<string, vector<string>> map;
    for (size_t i = 0; i < strs.size(); i++) {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        map[temp].push_back(strs[i]);
    }
    for (auto i : map) {
        anagrams.push_back(i.second);
    }
    return anagrams;
}


int main () {
    vector<string> input = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams(input);
    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
