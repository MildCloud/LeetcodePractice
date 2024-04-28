#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (size_t i = 0; i < nums.size(); i++) {
        minHeap.push(nums[i]);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}


int main() {
    return 0;
}

