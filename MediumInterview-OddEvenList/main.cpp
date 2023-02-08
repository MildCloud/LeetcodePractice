#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* oddEvenList (ListNode* head) {
    ListNode* odd = new ListNode;
    ListNode* currentOdd = odd;
    ListNode* even = new ListNode;
    ListNode* currentEven = even;
    bool countOdd = true;
    if (head) {
        odd->val = head->val;
        head = head->next;
    }
    else {
        return nullptr;
    }
    if (head) {
        even->val = head->val;
        head = head->next;
    }
    else {
        return odd;
    }
    while (head) {
        ListNode* newNode = new ListNode(head->val);
        if (countOdd) {
            currentOdd->next = newNode;
            currentOdd = currentOdd->next;
        }
        else {
            currentEven->next = newNode;
            currentEven = currentEven->next;
        }
        countOdd = !countOdd;
        head = head->next;
    }
    currentOdd->next = even;
    return odd;
}


int main () {
    return 0;
}
