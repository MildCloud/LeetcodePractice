#include <iostream>
#include <vector>
using namespace std;


void help(vector<int>& nums, vector<int> currentPerm, vector<vector<int>>& totalPerm) {
    if (nums.size() == 1) {
        vector<int> newPerm = currentPerm;
        newPerm.push_back(nums[0]);
        totalPerm.push_back(newPerm);
        return;
    }
    else {
        for (size_t i = 0; i < nums.size(); i++) {
            swap(nums[0], nums[i]);
            vector<int> remainNums(nums.begin() + 1, nums.end());
            vector<int> newPerm = currentPerm;
            newPerm.push_back(nums[0]);
            help(remainNums, newPerm, totalPerm);
            swap(nums[0], nums[i]);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> v;
    vector<vector<int>> result;
    help(nums, v, result);
    return result;
}


int main() {
    vector<int> v = {1, 2, 3, 4};
    vector<int> v2 = {1, 5, 2, 3, 4};
    vector<int> v3 = v;
    swap(v[0], v[2]);
    for (auto i = v.begin(); i < v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;
    v2 = v3;
    for (size_t i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
    return 0;
}
