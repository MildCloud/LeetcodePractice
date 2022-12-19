#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


vector<vector<int>> threeSum (vector<int> & nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> triples;
    unordered_map<int, unordered_map<int, int>> triMap;
    for (size_t i = 0; i < nums.size() - 2; i++) {
        for (size_t j = i + 1; j < nums.size() - 1; j++) {
            for (size_t k = j + 1; k < nums.size(); k++) {
                if (nums[i]+ nums[j] + nums[k] == 0) {
                    if (triMap.find(nums[i]) != triMap.end()) {
                        if (triMap[nums[i]].find(nums[j]) != triMap[nums[i]].end()) {}
                        else {
                            triMap[nums[i]][nums[j]] = nums[k];
                        }
                    }
                    else {
                        unordered_map<int, int> m;
                        m[nums[j]] = nums[k];
                        triMap[nums[i]] = m;
                    }
                } 
            }
        }
    }
    for (auto it = triMap.begin(); it != triMap.end(); it++) {
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            triples.push_back({it->first, it2->first, it2->second});
        }
    }
    return triples;
}


int main () {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(nums);
    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
