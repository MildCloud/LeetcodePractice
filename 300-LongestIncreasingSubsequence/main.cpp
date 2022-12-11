#include <iostream>
#include <vector>
using namespace std;


int LIS (vector<int> & nums) {
    vector<size_t> memo(nums.size());
    memo[0] = 1;
    for (size_t i = 1; i < memo.size(); i++) {
        size_t currentMax = 0;
        for (size_t j = 0; j < i; j++) {
            if (nums[i] > nums[j] && memo[j] + 1 > currentMax) {
                currentMax = memo[j] + 1;
            }
        }
        memo[i] = currentMax;
    }
    
}


int main () {
    return 0;
}
