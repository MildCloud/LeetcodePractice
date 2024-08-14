#include <iostream>
#include <string>
using namespace std;

int next(int n) {
    string s = to_string(n);
    n = 0;
    for (int i = s.length() - 1; i > -1; i--) {
        int digit = s[i] - '0';
        n += digit * digit;
    }
    return n;
}

bool isHappy(int n) {
    int n1 = n;
    int n2 = next(n);
    while (n1 != n2) {
        if (n2 == 1) {
            return true;
        }
        n1 = next(n1);
        n2 = next(n2);
        n2 = next(n2);
    }
    if (n2 == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cout << isHappy(19) << endl;
    cout << isHappy(2) << endl;
    return 0;
}
