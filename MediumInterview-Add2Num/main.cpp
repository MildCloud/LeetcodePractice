#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode * add2Numbers(ListNode * l1, ListNode * l2) {
    int carry = 0;
    ListNode* result = new ListNode;
    ListNode * current = result;
    if (l1->val + l2->val > 9) {
        result->val = l1->val + l2->val - 10;
        carry = 1;
    }
    else {
        result->val = l1->val + l2->val;
    }
    l1 = l1->next;
    l2 = l2->next;

    while (l1 && l2) {
        ListNode * newNode = new ListNode;
        if (carry + l1->val + l2->val > 9) {
            newNode->val = carry + l1->val + l2->val - 10;
            carry = 1;
        }
        else {
            newNode->val = carry + l1->val + l2->val;
            carry = 0;
        }
        current->next= newNode;
        current = current->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        ListNode * newNode = new ListNode;
        if (carry + l1->val > 9) {
            newNode->val = carry + l1->val - 10;
            carry = 1;
        }
        else {
            newNode->val = carry + l1->val;
            carry = 0;
        }
        current->next = newNode;
        current = current->next;
        l1 = l1->next;
    }
    while (l2) {
        ListNode * newNode = new ListNode;
        if (carry + l2->val > 9) {
            newNode->val = carry + l2->val - 10;
            carry = 1;
        }
        else {
            newNode->val = carry + l2->val;
            carry = 0;
        }
        current->next = newNode;
        current = current->next;
        l2 = l2->next;
    }
    if (carry == 1) {
        ListNode * newNode = new ListNode(1);
        current->next = newNode;
    }
    return result;
}

int main() {
    return 0;
}
