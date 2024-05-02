#include <iostream>
#include <vector>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    if (nums.empty() || target < nums[0] || target > nums.back()) {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] > target) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        if (nums[i] == target) {
            result.push_back(i);
            size_t j = i;
            for (; j < nums.size(); j++) {
                if (nums[j] != target) {
                    break;
                }
            }
            result.push_back(j - 1);
            return result;
        }
    }
    return result;
}
