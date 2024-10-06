#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


vector<int> mergeVec(vector<int>& v1, vector<int>& v2) {
    int i = 0, j = 0;
    vector<int> v;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            v.push_back(v1[i]);
            i++;
        }
        else {
            v.push_back(v2[j]);
            j++;
        }
    }
    while (i < v1.size()) {
        v.push_back(v1[i]);
        i++;
    }
    while (j < v2.size()) {
        v.push_back(v2[j]);
        j++;
    }
    return v;
}

void sortVec(vector<int>& v) {
    int length = v.size();
    if (length == 1) {
        return;
    }
    vector<int> left(v.begin(), v.begin()+length/2);
    vector<int> right(v.begin()+length/2, v.end());
    sortVec(left);
    sortVec(right);
    v = mergeVec(left, right);
}

ListNode* sortList(ListNode* head) {
    if (!head->next) {
        return head;
    }
    vector<int> v;
    ListNode* current = head;
    while (current) {
        v.push_back(current->val);
        current = current->next;
    }
    sortVec(v);
    current = head;
    for (int i = 0; i < v.size(); i++) {
        current->val = v[i];
        current = current->next;
    }
    return head;
}


int main() {
    vector<int> v = {-1,5,3,4,0};
    sortVec(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}
