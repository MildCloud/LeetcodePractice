#include <iostream>
#include <vector>
using namespace std;


int findPeakElement(vector<int>& nums) {
    if (nums.size() == 1) {
        return 0;
    }
    for (size_t i = 0; i < nums.size(); i++) {
        if (i == 0) {
            if (nums[i] > nums[i+1]) {
                return i;
            }
        }
        else if (i == nums.size() - 1) {
            if (nums[i-1] < nums[i]) {
                return i;
            }
        }
        else {
            if (nums[i-1] < nums[i] && nums[i] > nums[i+1]) {
                return i;
            }
        }
    }
    return 0;
}


int main() {
    return 0;
}
