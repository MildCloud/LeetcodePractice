#include <iostream>
#include <vector>
using namespace std;


int LIS (vector<int> & nums) {
    vector<size_t> memo(nums.size());
    memo[0] = 1;
    for (size_t i = 1; i < memo.size(); i++) {
        size_t currentMax = 1;
        for (size_t j = 0; j < i; j++) {
            if (nums[i] > nums[j] && memo[j] + 1 > currentMax) {
                currentMax = memo[j] + 1;
            }
        }
        memo[i] = currentMax;
    }
    size_t maxLen = 0;
    for (size_t i = 0; i < memo.size(); i++) {
        //cout << memo[i] << " ";
        if (memo[i] > maxLen) {
            maxLen = memo[i];
        }
    }
    //cout << endl;
    return maxLen;
}


int main () {
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    vector<int> nums2 = {0,1,0,3,2,3};
    vector<int> nums3 = {7,7,7,7,7,7,7,7,7};
    cout << LIS(nums1) << endl;
    cout << LIS(nums2) << endl;
    cout << LIS(nums3) << endl;
    return 0;
}
