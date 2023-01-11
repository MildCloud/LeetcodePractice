#include <iostream>
#include <limits>
#include <vector>
using namespace std;


bool incTriplet (vector<int> & nums) {
    if (nums.size() < 3) {
        return false;
    }
    int a = numeric_limits<int>::max();
    int b = numeric_limits<int>::max();
    for (auto i : nums) {
        a = min(a, i);
        if (i > b) {
            return true;
        }
        if (i > a) {
            b = i;
        }
    }
    return false;
}


int main () {
    return 0;
}
