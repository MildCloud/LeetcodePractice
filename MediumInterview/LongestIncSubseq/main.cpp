#include <iostream>
#include <vector>
using namespace std;


int lengthOfLIS(vector<int>& nums) {
    vector<int> longestEndingAt(nums.size(), 1);
    for (size_t i = 0; i < nums.size(); i++) {
        int currMax = 1;
        for (size_t j = 0; j < i; j++) {
            int tempLength = 1;
            if (nums[j] < nums[i]) {
                tempLength = longestEndingAt[j] + 1;
            }
            if (tempLength > currMax) {
                currMax = tempLength;
            }
        }
        longestEndingAt[i] = currMax;
    }
    int currMax = 1;
    for (size_t i = 0; i < nums.size(); i++) {
        cout << longestEndingAt[i] << " ";
        if (longestEndingAt[i] > currMax) {
            currMax = longestEndingAt[i];
        }
    }
    cout << endl;
    return currMax;
}


int main() {
    vector<int> v{4,10,4,3,8,9};
    cout << lengthOfLIS(v) << endl;
    return 0;
}
