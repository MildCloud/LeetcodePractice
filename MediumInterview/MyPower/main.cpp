#include <iostream>
#include <string>
using namespace std;

double myPow(double x, int n) {
    if(n < 0) {
        x = 1 / x;
    } 
    
    long num = labs(n);
    
    double pow = 1;
    
    while(num){ // equivalent to while(num != 0)
        if(num & 1) { // equivalent to if((num & 1) != 0)
            pow *= x;
        }
        
        x *= x;
        num >>= 1;
    }
    
    return pow;
}

double myPow_my_answer(double x, int n) {
    double result = 1;
    double x_2 = x*x;
    if (x == 1) {
        return result;
    }
    if (n > 0) {
        int i = 0;
        for (; i < n; i += 2) {
            result *= x_2;
            cout << result << endl;
            if (i + 3 == n) {
                result *= x;
                break;
            }
        }
    }
    else {
        if (n == -1) {
            return 1/x;
        }
        int i = 0;
        for (; i > n; i -= 2) {
            result /= x_2;
            if (i - 3 == n) {
                result /= x;
                break;
            }
        }
    }
    
    return result;
}


int main() {
    cout << myPow(2.1, 3) << endl;
    return 0;
}
