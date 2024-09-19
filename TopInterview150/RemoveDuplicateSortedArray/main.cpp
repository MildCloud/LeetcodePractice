#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 1) {
        return 1;
    }
    int i = 0;
    int j = 1;
    int result = 1;
    while (j < nums.size()) {
        if (nums[i] != nums[j]) {
            i++;
            j++;
            result++;
        }
        else {
            nums.erase(nums.begin() + j);
        }
    }
    return result;
}
