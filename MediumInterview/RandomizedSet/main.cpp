#include <iostream>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> map;
    unsigned int size;
    RandomizedSet() {
        size = 0;
    }
    
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        else {
            map[val] = val;
            size++;
            return true;
        }
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        else {
            map.erase(map.find(val));
            size--;
            return true;
        }
    }
    
    int getRandom() {
        cout << size << endl;
        int randNum = rand() % size;
        cout << randNum << endl;
        auto it = map.begin();
        advance(it, randNum);
        return it->first;
    }
};


int main() {
    RandomizedSet randomizedSet;
    randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    cout << randomizedSet.size << endl;
    randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
    cout << randomizedSet.size << endl;
    randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
    cout << "here" << endl;
    randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
    randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
    randomizedSet.insert(2); // 2 was already in the set, so return false.
    randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
    return 0;
}
