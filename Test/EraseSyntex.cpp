#include <iostream>
#include <vector>
#include <limits>
#include <cassert>
#include <memory>
#include <string>
#include <cstring>
#include <queue>
#include <mutex>
#include <shared_mutex>
#include <unordered_map>
#include <thread>
#include <sstream>
using namespace std;

weak_ptr<shared_mutex> w_ptr;

int main () {
    unordered_map<int, int> map;
    vector<int> map_erase;
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        map[i] = i + 1;
        vec.push_back(i);
    }
    // for (auto i : map) {
    //     cout << i.first << ' ' << i.second << endl;
    //     if (i.first % 2 == 0) {
    //         map_erase.push_back(i.first);
    //     }
    // }
    // while (!map_erase.empty()) {
    //     map.erase(map_erase.back());
    //     map_erase.pop_back();
    // }
    for (auto it = map.begin(); it != map.end();) {
        if (it->first %2 == 0) {
            it = map.erase(it);
        }
        else {
            it++;
        }
    }
    cout << "After erase" << endl;
    for (auto i : map) {
        cout << i.first << ' ' << i.second << endl;
    }
    cout << "Test vec" << endl;
    for (auto it = vec.begin(); it != vec.end();) {
        if ((*it) % 2 == 0) {
            it = vec.erase(it);
        }
        else {
            it++;
        }
    }
    for (auto i : vec) {
        cout << i << endl;
    }
    return 0;
}
