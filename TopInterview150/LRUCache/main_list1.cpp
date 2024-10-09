#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

class LRUCache {
public:

    struct Node {
        int key;
        Node* next;
        Node* prev;
    };

    int cacheCapacity;
    unordered_map<int, int> cache;
    Node* mru;
    Node* lru;
    int cacheSize;

    LRUCache(int capacity) {
        cacheCapacity = capacity;
        mru = nullptr;
        lru = nullptr;
        cacheSize = 0;
    }
    
    int get(int key) {
        checkContinue();
        if (cache.find(key) != cache.end()) {
            if (mru->key == key) {
                return cache[key];
            }
            else {
                Node* head = mru;
                Node* current = head->next;
                while (current) {
                    if (current->key == key) {
                        head->next = current->next;
                        if (head->next) {
                            Node* next = head->next;
                            next->prev = head;
                        }
                        else {
                            lru = head;
                            if (!head->prev) {
                                head->prev = current;
                            }
                        }
                        current->next = mru;
                        current->prev = nullptr;
                        mru->prev = current;
                        mru = current;
                        break;
                    }
                    current = current->next;
                    head = head->next;
                }
                return cache[key];
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        checkContinue();
        if (cache.find(key) != cache.end()) {
            cache[key] = value;
            Node* head = mru;
            Node* current = head->next;
            while (current) {
                if (current->key == key) {
                    head->next = current->next;
                    if (head->next) {
                        Node* next = head->next;
                        next->prev = head;
                    }
                    else {
                        lru = head;
                        if (!head->prev) {
                            head->prev = current;
                        }
                    }
                    current->next = mru;
                    current->prev = nullptr;
                    mru->prev = current;
                    mru = current;
                    break;
                }
                current = current->next;
                head = head->next;
            }
        }
        else {
            cache[key] = value;
            Node* newNode = new Node;
            newNode->key = key;
            if (!mru) {
                newNode->next = nullptr;
                newNode->prev = nullptr;
                mru = newNode;
                lru = newNode;
                cacheSize++;
                return;
            }
            newNode->prev = nullptr;
            newNode->next = mru;
            mru->prev = newNode;
            mru = newNode;
            if (cacheSize == cacheCapacity) {
                int evicted_key = lru->key;
                cache.erase(evicted_key);
                lru = lru->prev;
                lru->next = nullptr;
            }
            else {
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
