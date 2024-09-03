#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int leastInterval(vector<char>& tasks, int n) {
    vector<int> taskNums(26, 0);
    vector<int> intervals(26, 0);
    int cycle = 0;
    for (size_t i = 0; i < tasks.size(); i++) {
        int idx = tasks[i] - 'A';
        taskNums[idx]++;
    }
    int completedTaskNum = 0;
    while (completedTaskNum != tasks.size()) {
        bool idel = true;
        size_t maxTaskNumIdx = 0;
        int maxTaskNum = 0;
        for (size_t i = 0; i < taskNums.size(); i++) {
            if (taskNums[i] > 0) {
                if (intervals[i] == 0 && taskNums[i] > maxTaskNum) {
                    idel = false;
                    maxTaskNum = taskNums[i];
                    maxTaskNumIdx = i;
                }
                else if (intervals[i] != 0) {
                    intervals[i]--;
                }
            }
        }
        if (!idel) {
            completedTaskNum++;
            taskNums[maxTaskNumIdx]--;
            intervals[maxTaskNumIdx] = n;
        }
        cycle++;
    }
    return cycle;
}


int main() {
    vector<char> v = {'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E'};
    cout << leastInterval(v, 2) << endl;;
    return 0;
}
