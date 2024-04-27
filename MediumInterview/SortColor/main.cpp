#include <vector>
using namespace std;


void sortColors(vector<int>& nums) {
    size_t num0 = 0;
    size_t num1 = 0;
    size_t num2 = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            num0 += 1;
        }
        if (nums[i] == 1) {
            num1 += 1;
        }
        if (nums[i] == 2) {
            num2 += 1;
        }
    }
    for (size_t i = 0; i < num0; i++) {
        nums[i] = 0;
    }
    for (size_t i = num0; i < num0+num1; i++) {
        nums[i] = 1;
    }
    for (size_t i = num0+num1; i < num0+num1+num2; i++) {
        nums[i] = 2;
    }
}

void sortColorsFast(vector<int>& nums) {
    int s = 0, e = nums.size()-1, n = nums.size();
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == 0 && i != s)
        {
            swap(nums[i], nums[s]);
            i--;
            s++;
        }
        if(nums[i] == 2 && i < e)
        {
            swap(nums[i], nums[e]);
            e--;
            i--;
        }
    }
}
