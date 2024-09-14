#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int currentMin = 0;
    int i = 0;
    int j = 0;
    int val = 0;
    while (i < nums.size()) {
        while (val < target && j < nums.size()) {
            val += nums[j];
            j++;
        }
        if (val >= target && (j - i < currentMin || currentMin == 0)) {
            currentMin = j - i;
        }
        val -= nums[i];
        i++;
    }
    return currentMin;
}


