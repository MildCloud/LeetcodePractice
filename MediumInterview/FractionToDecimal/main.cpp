#include <iostream>
#include <unordered_map>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    bool isPositive = (numerator<0 == denominator<0);
    long a = abs(numerator);
    long b = abs(denominator);
    if (a == 0) {
        return "0";
    }
    unordered_map<long, int> map;
    string result;
    int decimal = 0;
    string decimal_str;
    while (a != 0) {
        if (a < b && map.size() == 0) {
            result += '.';
        }
        if (a < b) {
            a *= 10;
        }
        long current = a / b;
        if (result.length() == 0 || result[result.length() - 1] != '.') {
            result += to_string(current);
        }
        else {
            long remainder = a - current * b;
            if (map.find(remainder) != map.end()) {
                if (current + '0' != decimal_str[map[remainder]]) {
                    decimal_str += '0' + current;
                    map[remainder] += 1;
                }
                decimal_str.insert(map[remainder], "(");
                decimal_str += ')';
                break;
            }
            else {
                map[remainder] = decimal;
                decimal += 1;
                decimal_str += '0' + current; 
            }
        }
        a -= current * b;
    }
    result += decimal_str;
    if (result[0] == '.') {
        result = '0' + result;
    }
    if (!isPositive) {
        result = '-' + result;
    }
    return result;
}


int main() {
    int i = 1 << 31;
    cout << fractionToDecimal(-1, i) << endl;
    cout << fractionToDecimal(50, 8) << endl;
    cout << fractionToDecimal(-50, 8) << endl;
    cout << fractionToDecimal(500, 10) << endl;
    cout << fractionToDecimal(10, 2) << endl;
    cout << fractionToDecimal(4, 333) << endl;
    cout << fractionToDecimal(1, 6) << endl;
    cout << fractionToDecimal(4, 3) << endl;
    return 0;
}
