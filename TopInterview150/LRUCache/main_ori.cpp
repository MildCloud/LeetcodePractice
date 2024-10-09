#include <iostream>
#include <vector>
using namespace std;

class LRUCache {
public:
    struct cacheLine {
        int key;
        int val;
        int lru;
    };
    int cacheCapacity;
    vector<cacheLine> cache;

    LRUCache(int capacity) {
        cacheCapacity = capacity;
    }
    
    int get(int key) {
        bool found = false;
        int val;
        int lru;
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].key == key) {
                found = true;
                val = cache[i].val;
                lru = cache[i].lru;
                cache[i].lru = 0;
                break;
            }
        }
        if (found) {
            for (int i = 0; i < cache.size(); i++) {
                if (cache[i].lru < lru && cache[i].key != key) {
                    cache[i].lru++;
                }
            }
            return val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        bool found = false;
        int lru;
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].key == key) {
                found = true;
                cache[i].val = value;
                lru = cache[i].lru;
                cache[i].lru = 0;
                break;
            }
        }
        if (found) {
            for (int i = 0; i < cache.size(); i++) {
                if (cache[i].lru < lru && cache[i].key != key) {
                    cache[i].lru++;
                }
            }
            return;
        }

        if (cache.size() < cacheCapacity) {
            for (int i = 0; i < cache.size(); i++) {
                cache[i].lru++;
            }
            cacheLine newLine;
            newLine.key = key;
            newLine.val = value;
            newLine.lru = 0;
            cache.push_back(newLine);
        }
        else {
            for (int i = 0; i < cache.size(); i++) {
                if (cache[i].lru == cacheCapacity - 1) {
                    cache[i].key = key;
                    cache[i].val = value;
                    cache[i].lru = 0;
                }
                else {
                    cache[i].lru++;
                }
            }
        }
    }

    void display() {
        cout << "-----------display-----------" << endl;
        for (int i = 0; i < cache.size(); i++) {
            cout << "key " << cache[i].key << ", val " << cache[i].val << ", lru " << cache[i].lru << endl;
        }
    }
};


int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.display();
    cache.put(2, 2);
    cache.display();
    cout << cache.get(1) << endl;
    cache.display();
    cache.put(3, 3);
    cache.display();
    cout << cache.get(2) << endl;
    cache.display();
    cache.put(4, 4);
    cache.display();
    cout << cache.get(1) << endl;
    cache.display();
    cout << cache.get(3) << endl;
    cache.display();
    cout << cache.get(4) << endl;
    return 0;
}
