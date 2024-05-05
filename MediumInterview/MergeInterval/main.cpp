#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Time limit exceeded
vector<vector<int>> merge_(vector<vector<int>>& intervals) {       
    vector<vector<int>> result;
    for (size_t i = 0; i < intervals.size(); i++) {
        int newIntervalBegin = intervals[i][0];
        int newIntervalEnd = intervals[i][1];
        bool canMerge = true;
        while (canMerge) {
            bool allExclude = true;
            for (size_t j = 0; j < result.size(); j++) {
                if ((newIntervalBegin >= result[j][0] && newIntervalBegin <= result[j][1]) || 
                (newIntervalEnd >= result[j][0] && newIntervalEnd<= result[j][1])) {
                    allExclude = false;
                    if (result[j][0] < newIntervalBegin) {
                        newIntervalBegin = result[j][0];
                    }
                    if (result[j][1] > newIntervalEnd) {
                        newIntervalEnd = result[j][1];
                    }
                    result.erase(result.begin()+j);
                    break;
                }
            }
            if (allExclude) {
                canMerge = true;
            }
        }
        vector<int> newInterval = {newIntervalBegin, newIntervalEnd};
        result.push_back(newInterval);
    }
    return result;
}


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size(); i++) {
        vector<int> temp = intervals[i];
        while (i < intervals.size() && temp[1] >= intervals[i][0]) {
            temp[1] = max(temp[1],intervals[i][1]);
            i++;
        }
        if (i < intervals.size() && temp != intervals[i]) {
            i--;
        };
        ans.push_back(temp);
    }
    return ans;
}


int main() {
    vector<vector<int>> v = {{1,2}, {1,1}, {0,3}, {2,3}};
    sort(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i][0] << v[i][1] << endl;
    }
    vector<vector<int>> mergedV = merge(v);
    return 0;
}
