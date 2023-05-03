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
    unordered_map<int, vector<int>> map_vec;
    map_vec[1].push_back(0);
    
    map_vec[1].push_back(1);
    cout << map_vec[1][0] << map_vec[1][1] << endl;
    return 0;
}
