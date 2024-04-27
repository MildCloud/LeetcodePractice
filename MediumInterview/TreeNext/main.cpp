#include<iostream>
#include<deque>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    deque<Node*> deq0, deq1;
    if (root) {
        deq0.push_back(root);
        while (!deq0.empty() || !deq1.empty()) {
            while (!deq0.empty()) {
                Node* temp = deq0.front();
                deq0.pop_front();
                if (temp->left) {
                    deq1.push_back(temp->left);
                }
                if (temp->right) {
                    deq1.push_back(temp->right);
                }
                if (deq0.empty()) {
                    temp->next = nullptr;
                }
                else {
                    temp->next = deq0.front();
                }
            }
            while (!deq1.empty()) {
                Node* temp = deq1.front();
                deq1.pop_front();
                if (temp->left) {
                    deq0.push_back(temp->left);
                }
                if (temp->right) {
                    deq0.push_back(temp->right);
                }
                if (deq1.empty()) {
                    temp->next = nullptr;
                }
                else {
                    temp->next = deq1.front();
                }
            }
        }
    }
    return root;
}


int main() {
    return 0;
}
