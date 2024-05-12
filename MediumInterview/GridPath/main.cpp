#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int uniquePath(int m, int n) {
    int result_numerator = m+n-2;
    int result_denominator = min(m-1, n-1);
    if (result_denominator == 0) {
        return 1;
    }
    int temp = result_numerator-1;
    for (int i = result_denominator - 1; i > 0; i--) {
        int result_gcd = gcd(result_denominator, result_numerator);
        result_denominator /= result_gcd;
        result_numerator /= result_gcd;
        result_denominator *= i;
        result_numerator *= temp;
        temp--;
    }
    return result_numerator / result_denominator;
}


int main() {
    cout << uniquePath(10, 10) << endl;
    return 0;
}
