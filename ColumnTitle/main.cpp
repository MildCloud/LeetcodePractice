#include <iostream>
#include <string>
using namespace std;


int titleToNumber(string columnTitle) {
    int num = 0;
    for (int i = 0; i < columnTitle.length(); i++) {
        int inc = columnTitle[i] - 'A' + 1;
        for (int j = i+1; j < columnTitle.length(); j++) {
            inc *= 26;
        }
        num += inc;
    }
    return num;
}