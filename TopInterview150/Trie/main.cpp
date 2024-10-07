#include <iostream>
#include <string>
using namespace std;


class Trie {
public:

    struct BST {
        string val;
        BST* left;
        BST* right;

        BST(string newVal): val(newVal), left(nullptr), right(nullptr) {}
    };
    BST* head;

    Trie() {
        head = nullptr;
    }
    
    void insert(string word) {
        if (!head) {
            head = new BST(word);
            return;
        }
        BST* current = head;
        BST* newNode = new BST(word);
        while (true) {
            if (word < current->val) {
                if (current->left) {
                    current = current->left;
                }
                else {
                    current->left = newNode;
                    break;
                }
            }
            else {
                if (current->right) {
                    current = current->right;
                }
                else {
                    current->right = newNode;
                    break;
                }
            }
        }
    }
    
    bool search(string word) {
        BST* current = head;
        while (current) {
            if (word == current->val) {
                return true;
            }
            else if (word < current->val) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        BST* current = head;
        while (current) {
            if (current->val.find(prefix) == 0) {
                return true;
            }
            else if (prefix < current->val) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }
};


int main() {
    Trie T;
    T.insert("hotdog");
    cout << T.search("hotdog") << endl;
    cout << T.startsWith("dog") << endl;
    return 0;
}
