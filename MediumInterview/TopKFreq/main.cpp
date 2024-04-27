#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


class Data {
    public:
        int val;
        int freq;
        Data(int _val, int _freq): val(_val), freq(_freq) {};
        friend bool operator< (Data const & a, Data const & b) {
            return a.freq > b.freq;
        };
};


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (size_t i = 0; i < nums.size(); i++) {
        if (map.find(nums[i]) == map.end()) {
            map[nums[i]] = 1;
        }
        else {
            map[nums[i]] += 1;
        }
    }
    priority_queue<Data> dpq;
    for (auto it = map.begin(); it != map.end(); it++) {
        Data d(it->first, it->second);
        dpq.push(d);
        if (dpq.size() > k) {
            dpq.pop();
        }
    }
    vector<int> result;
    while (!dpq.empty()) {
        result.push_back(dpq.top().val);
        dpq.pop();
    }
    return result;
}


int main() {
    return 0;
}
