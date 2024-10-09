#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

class LRUCache {
public:

    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int newKey, int value) {
            key = newKey;
            val = value;
            next = nullptr;
            prev = nullptr;
        }
    };

    int cacheCapacity;
    unordered_map<int, Node*> cache;
    Node* mru;
    Node* lru;
    int cacheSize;

    LRUCache(int capacity) {
        cacheCapacity = capacity;
        mru = new Node(-1, -1);
        lru = new Node(-1, -1);
        mru->next = lru;
        lru->prev = mru;
        cacheSize = 0;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* temp = cache[key];
            Node* prev = temp->prev;
            Node* next = temp->next;
            prev->next = next;
            next->prev = prev;
            temp->next = mru->next;
            temp->prev = mru;
            mru->next->prev = temp;
            mru->next = temp;
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* temp = cache[key];
            Node* prev = temp->prev;
            Node* next = temp->next;
            prev->next = next;
            next->prev = prev;
            temp->next = mru->next;
            temp->prev = mru;
            mru->next->prev = temp;
            mru->next = temp;
            cache[key]->val = value;
        }
        else {
            Node* temp = new Node(key, value);
            cache[key] = temp;
            if (cacheSize == cacheCapacity) {
                int evictKey = lru->prev->key;
                Node* evictTemp = cache[evictKey];
                Node* prev = evictTemp->prev;
                Node* next = evictTemp->next;
                prev->next = next;
                next->prev = prev;
                cache.erase(evictKey);
                temp->next = mru->next;
                temp->prev = mru;
                mru->next->prev = temp;
                mru->next = temp;
                delete evictTemp;
            }
            else {
                temp->next = mru->next;
                temp->prev = mru;
                mru->next->prev = temp;
                mru->next = temp;
                cacheSize++;
            }
        }
    }

    void checkContinue() {
        int len = 0;
        Node* current = mru;
        while (current) {
            current = current->next;
            len++;
        }
        assert(len == cacheSize);
        current = lru;
        while (current) {
            current = current->prev;
            len--;
        }
        assert(len == 0);
    }
};


int main() {
    LRUCache cache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.put(4, 4);
    cout << cache.get(4) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;
    return 0;
}
