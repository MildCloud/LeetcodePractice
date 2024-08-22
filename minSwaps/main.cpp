#include <iostream>
#include <vector>
using namespace std;


int minSwaps(vector<int> v) {
    int count_zero_first = 0;
    int i = 0;
    int j = v.size() - 1;
    while (i <= j) {
        while (v[i] == 0 && i <= j) {
            i++;
        }
        while (v[j] == 1 && i <= j) {
            j--;
        }
        if (i <= j && v[i] == 1 && v[j] == 0) {
            count_zero_first++;
            i++;
            j--;
        }
    }

    int count_one_first = 0;
    i = 0;
    j = v.size() - 1;
    while (i <= j) {
        while (v[i] == 1 && i <= j) {
            i++;
        }
        while (v[j] == 0 && i <= j) {
            j--;
        }
        if (i <= j && v[i] == 0 && v[j] == 1) {
            count_one_first++;
            i++;
            j--;
        }
    }

    if (count_one_first < count_zero_first) {
        return count_one_first;
    }
    else {
        return count_zero_first;
    }
}


int main() {
    cout << minSwaps({1, 0, 1, 0, 1}) << endl;
    cout << minSwaps({1, 0, 0, 0, 1}) << endl;
    cout << minSwaps({0, 0, 1, 0, 1}) << endl;
    cout << minSwaps({1, 0, 1, 0, 0}) << endl;
    cout << minSwaps({1, 1, 1, 0, 0}) << endl;
    cout << minSwaps({0, 0, 1, 1, 1}) << endl;
    cout << minSwaps({1, 1, 1, 1, 1}) << endl;
    cout << minSwaps({0, 0, 0, 0, 0}) << endl;
    return 0;
}
