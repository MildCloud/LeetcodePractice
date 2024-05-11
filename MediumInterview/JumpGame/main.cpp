#include <iostream>
#include <vector>
using namespace std;


void help() {}

// Time limit exceeded
bool canJump1(vector<int>& nums) {
    if (nums.size() <= 1) {
        return true;
    }
    if (nums.size() == 2) {
        return nums[0] >= 1;
    }
    bool result = false;
    for (size_t i = 0; i < nums.size() - 1; i++) {
        if (nums[i] >= nums.size() - i - 1) {
            vector<int> remainNums(nums.begin(), nums.begin() + i + 1);
            result = result | canJump1(remainNums);
            if (result) {
                return result;
            }
        }
    }
    return result;
}

bool canJump(vector<int>& nums) {
    vector<vector<bool>> jumpMap(nums.size(), vector<bool>(nums.size(), false));
    for (size_t i = 0; i < nums.size(); i++) {
        if (i == 0) {
            for (size_t j = 0; j <= nums[i]; j++) {
                jumpMap[i][j] = true;
                if (j == nums.size() - 1) {
                    return true;
                }
            }
        }
        else {
            bool canReachCurrent = false;
            for (int j = i - 1; j >= 0; j--) {
                if (jumpMap[j][i]) {
                    canReachCurrent = true;
                    break;
                }
            }
            if (canReachCurrent) {
                for (size_t j = i; j <= i + nums[i]; j++) {
                    jumpMap[i][j] = true;
                    if (j == nums.size() - 1) {
                        return true;
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < jumpMap.size(); i++) {
        for (size_t j = 0; j < jumpMap[0].size(); j++) {
            if (jumpMap[i][j]) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
    }
    return false;
}


int main() {
    vector<int> v = {2,3,1,1,4};
    cout << canJump(v) << endl;
    return 0;
}
