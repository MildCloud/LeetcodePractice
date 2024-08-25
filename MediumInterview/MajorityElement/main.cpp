#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;


int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;
    for (unsigned int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        if (nums[i] == candidate) {
            count++;
        }
        else {
            count--;
        }
        cout << count << " " << candidate << endl;
    }
    return candidate;
}


int main() {
    vector<int> nums = {1, 2, 3, 1, 1};
    cout << majorityElement(nums) << endl;
    return 0;
}