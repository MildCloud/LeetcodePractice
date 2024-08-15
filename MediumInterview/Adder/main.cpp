#include <iostream>
#include <bitset>
using namespace std;

int getSum(int a, int b) {
    int c; 
    while(b !=0 ) {
        cout << bitset<32>(a) << endl;
        cout << bitset<32>(b) << endl;
        c = a&b;
        a = a ^ b;
        b = c<<1;
    }
    return a;
}

int main() {
    cout << getSum(15, 14) << endl;
    return 0;
}