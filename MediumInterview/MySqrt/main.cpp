#include <iostream>
using namespace std;

int mySqrt(int x) {
    unsigned long low = 0;
    unsigned long high = x;
    unsigned long result = (low + high) / 2;
    while (true) {
        cout << low << " " << result << " " << high << endl;
        if (result*result <= x && (result+1)*(result+1) > x) {
            break;
        }
        if (result*result < x) {
            low = result + 1;
        }
        else if (result*result > x) {
            high = result;
        }
        result = (low + high) / 2;
    }
    return result;
}


int main() {
    cout << mySqrt(14) << endl;
    return 0;
}