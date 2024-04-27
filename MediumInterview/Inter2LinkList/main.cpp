#include <iostream>
#include <deque>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    deque<ListNode*> dequeA;
    deque<ListNode*> dequeB;
    ListNode* nodeA = headA;
    while (nodeA) {
        dequeA.push_back(nodeA);
        nodeA = nodeA->next;
    }
    ListNode* nodeB = headB;
    while (nodeB) {
        dequeB.push_back(nodeB);
        nodeB = nodeB->next;
    }
    ListNode* commonNode;
    if (dequeA.back() != dequeB.back()) {
        return nullptr;
    }
    else {
        commonNode = dequeA.back();
        dequeA.pop_back();
        dequeB.pop_back();
    }
    while (!dequeA.empty() && !dequeB.empty()) {
        if (dequeA.back() != dequeB.back()) {
            return commonNode;
        }
        else {
            commonNode = dequeA.back();
            dequeA.pop_back();
            dequeB.pop_back();
        }
    }
    return commonNode;
}

void printList(ListNode* head) {
    ListNode* node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    return;
}

ListNode* contructList(int min, int max) {
    ListNode* headA = new ListNode;
    ListNode* nodeA = headA;
    nodeA->val = min;
    for (int i = min; i < max; i++) {
        ListNode* newNode = new ListNode;
        newNode->val = i+1;
        nodeA->next = newNode;
        nodeA = newNode;
    }
    nodeA->next = nullptr;
    return headA;
}

int main() {
    ListNode* headA = contructList(1, 9);
    ListNode* headB = contructList(-5, 1);
    ListNode* tempNode = headB;
    while (tempNode->next) {
        tempNode = tempNode->next;
    }
    tempNode->next = headA->next->next->next;
    printList(headA);
    printList(headB);
    ListNode* commonNode = getIntersectionNode(headA, headB);
    cout << commonNode->val << endl;
    return 0;
}
