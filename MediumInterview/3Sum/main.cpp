#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


// vector<vector<int>> threeSum (vector<int> & nums) {
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> triples;
//     unordered_map<int, unordered_map<int, int>> triMap;
//     for (size_t i = 0; i < nums.size() - 2; i++) {
//         for (size_t j = i + 1; j < nums.size() - 1; j++) {
//             for (size_t k = j + 1; k < nums.size(); k++) {
//                 if (nums[i]+ nums[j] + nums[k] == 0) {
//                     if (triMap.find(nums[i]) != triMap.end()) {
//                         if (triMap[nums[i]].find(nums[j]) != triMap[nums[i]].end()) {}
//                         else {
//                             triMap[nums[i]][nums[j]] = nums[k];
//                         }
//                     }
//                     else {
//                         unordered_map<int, int> m;
//                         m[nums[j]] = nums[k];
//                         triMap[nums[i]] = m;
//                     }
//                 } 
//             }
//         }
//     }
//     for (auto it = triMap.begin(); it != triMap.end(); it++) {
//         for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
//             triples.push_back({it->first, it2->first, it2->second});
//         }
//     }
//     return triples;
// }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > ans;
        vector<int> tmp;
        unordered_map<int,int> stp;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();++i) stp[nums[i]]=i;
        //record the end position of every duplicating number
        for (int i=0;i<nums.size();){
            for (int j=i+1;j<nums.size();){
                int k=0-nums[i]-nums[j];
                if (k<nums[j]) break;
                if (k==nums[j]&&j==stp[k]) break;
                //-5 -1 -1 -1 -1 0 2
                if (stp.find(k)!=stp.end()){
                    tmp.clear();
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(k);
                    ans.push_back(tmp);
                }
                j=stp[nums[j]]+1;
            }
            i=stp[nums[i]]+1;
        }
        return ans;
    }


int main () {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> nums2 = {-5, -1, -1, -1, -1, 0, 2, -2, 1, 10};
    vector<vector<int>> result = threeSum(nums2);
    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
