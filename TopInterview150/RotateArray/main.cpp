#include <iostream>
#include <vector>
using namespace std;


void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    k = nums.size() - k;
    for (int i = 0; i < k; i++) {
        nums.push_back(nums[i]);
    }
    nums.erase(nums.begin(), nums.begin() + k);
}