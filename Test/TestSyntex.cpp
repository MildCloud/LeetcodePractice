#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int main () {
    cout << numeric_limits<int>::max() << endl;
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 4, 3};
    cout << (v1 == v2) << endl;
    string s = "asdf";
    s += 'i';
    s = s.insert(0, 1, 'b');
    s.insert(0, 1, 'b');
    cout << s << endl;
    return 0;
}
