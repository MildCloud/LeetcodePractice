#include <iostream>
#include <deque>
#include <string>
using namespace std;


string simplifyPath(string path) {
    int i = 1;
    string newPath = "/";
    deque<string> d;
    while (i < path.size()) {
        if (path[i] == '/') {
            i++;
        }
        else if (path[i] == '.') {
            if (i+1 < path.size()) {
                if (path[i+1] == '.') {
                    if ((i+2 < path.size() && path[i+2] == '/') || i+2 == path.size()) {
                        if (!d.empty()) {
                            d.pop_back();
                        }
                        i += 2;
                    }
                    else {
                        string name = "";
                        for (; i < path.size(); i++) {
                            if (path[i] == '/') {
                                break;
                            }
                            name += path[i];
                        }
                        d.push_back(name);
                    }
                }
                else if (path[i+1] == '/') {
                    i++;
                }
                else {
                    string name = "";
                    for (; i < path.size(); i++) {
                        if (path[i] == '/') {
                            break;
                        }
                        name += path[i];
                    }
                    d.push_back(name);
                }
            }
            else {
                break;
            }
        }
        else {
            string name = "";
            for (; i < path.size(); i++) {
                if (path[i] == '/') {
                    break;
                }
                name += path[i];
            }
            d.push_back(name);
        }
    }
    while (!d.empty()) {
        newPath += d.front();
        d.pop_front();
        newPath += '/';
    }
    if (newPath.size() > 1) {
        newPath.pop_back();
    }
    return newPath;
}


int main () {
    cout << simplifyPath("/..home") << endl;
    return 0;
}
