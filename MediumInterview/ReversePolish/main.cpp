#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;


int evalRPN(vector<string>& tokens) {
    deque<int> stack;
    while(!tokens.empty()) {
        string s = tokens.front();
        tokens.erase(tokens.begin());
        if (s == "+") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            stack.push_back(a + b);
        }
        else if (s == "-") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            stack.push_back(b - a);
        }
        else if (s == "*") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            stack.push_back(a * b);
        }
        else if (s == "/") {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            stack.push_back(b / a);
        }
        else {
            stack.push_back(stoi(s));
        }
    }
    return stack[0];
}


int main() {
    vector<string> v = {"4","13","5","/","+"};
    cout << evalRPN(v) << endl;
    return 0;
}
