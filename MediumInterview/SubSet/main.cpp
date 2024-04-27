#include <iostream>
#include <vector>
using namespace std;


void help(vector<int>& nums, vector<vector<int>>& subsets) {
    if (nums.size() == 1) {
        vector<int> empty;
        subsets.push_back(empty);
        vector<int> single = {nums[0]};
        subsets.push_back(single);
        return;
    }
    else {
        vector<int> remain(nums.begin()+1, nums.end());
        help(remain, subsets);
        size_t oriSubSize = subsets.size();
        for (size_t i = 0; i < oriSubSize; i++) {
            vector<int> temp = subsets[i];
            temp.push_back(nums[0]);
            subsets.push_back(temp);
        }
        return;
    }
}

vector<vector<int>> subsets(vector<int>& nums) {       
    vector<vector<int>> result;
    help(nums, result);
    return result;
}


int main() {
    return 0;
}

