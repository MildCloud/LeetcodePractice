#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    if (target >= nums[0]) {
        size_t i = 0;
        int temp = nums[0];
        while (nums[i] < target) {
            i++;
            if (i >= nums.size() || temp > nums[i]) {
                break;
            }
            else {
                temp = nums[i];
            }
        }
        if (i == nums.size() || nums[i] != target) {
            return -1;
        }
        else {
            return i;
        }
    }
    else {
        int i = nums.size() - 1;
        int temp = nums[nums.size() - 1];
        while (nums[i] > target) {
            i--;
            if (i < 0 || temp < nums[i]) {
                break;
            }
            else {
                temp = nums[i];
            }
        }
        if (i == -1 || nums[i] != target) {
            return -1;
        }
        else {
            return i;
        }
    }       
}
