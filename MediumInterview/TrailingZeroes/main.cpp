#include <iostream>

int trailingZeroes(int n) {
    int count = 0;
    for (int i = 0; i <= n; i += 5) {
        if (i%5 == 0 && i != 0) {
            int val = i;
            while (val%5 == 0) {
                count++;
                val /= 5;
            }
        }
    }
    return count;
}

int main() {
    std::cout << trailingZeroes(30) << std::endl;
    return 0;
}
