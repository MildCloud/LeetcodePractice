#include <iostream>
#include <deque>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    
    int cacheCapacity;
    deque<int> lru;
    unordered_map<int, int> cache;

    LRUCache(int capacity) {
        cacheCapacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            int i = 0;
            for (; i < lru.size(); i++) {
                if (lru[i] == key) {
                    lru.erase(lru.begin() + i);
                    break;
                }
            }
            lru.push_back(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key] = value;
            int i = 0;
            for (; i < lru.size(); i++) {
                if (lru[i] == key) {
                    lru.erase(lru.begin() + i);
                    break;
                }
            }
            lru.push_back(key);
        }
        else {
            cache[key] = value;
            if (lru.size() == cacheCapacity) {
                int evictKey = lru.front();
                lru.pop_front();
                cache.erase(evictKey);
            }
            lru.push_back(key);
        }
    }

    void display() {
        cout << "-----------display-----------" << endl;
    }
};


int main() {
    // LRUCache cache(2);
    // cache.put(1, 1);
    // cache.display();
    // cache.put(2, 2);
    // cache.display();
    // cout << cache.get(1) << endl;
    // cache.display();
    // cache.put(3, 3);
    // cache.display();
    // cout << cache.get(2) << endl;
    // cache.display();
    // cache.put(4, 4);
    // cache.display();
    // cout << cache.get(1) << endl;
    // cache.display();
    // cout << cache.get(3) << endl;
    // cache.display();
    // cout << cache.get(4) << endl;
    // return 0;
}
