#include <iostream>
#include <sstream>
using namespace std;


string say(string s) {
    string dummy = s + '~';
    string say_result = "";
    string partial_say = "";
    for (size_t i = 0; i < dummy.length(); i++) {
        if (partial_say == "" || dummy[i] == partial_say[0]) {
            partial_say += dummy[i];
        }
        else {
            stringstream strStream;
            strStream << partial_say.length() << partial_say[0];
            say_result.append(strStream.str());
            partial_say = "";
            partial_say += dummy[i];
        }
    }
    return say_result;
}

string countAndSay (int n) {
    if (n == 1) {
        return "1";
    }
    else {
        return say(countAndSay(n - 1));
    }
}

int main () {
    cout << say("1") << endl;
    cout << countAndSay(4) << endl;
    return 0;
}
