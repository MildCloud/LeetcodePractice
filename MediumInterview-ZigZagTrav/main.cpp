#include<iostream>
#include<deque>
#include<vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    deque<TreeNode*> node_ptr_stack0;
    deque<TreeNode*> node_ptr_stack;
    if (root) {
        node_ptr_stack0.push_back(root);
    }
    while (!node_ptr_stack0.empty() || !node_ptr_stack.empty()) {
        vector<int> zig;
        while(!node_ptr_stack0.empty()) {
            TreeNode* tempNode = node_ptr_stack0.back();
            node_ptr_stack0.pop_back();
            zig.push_back(tempNode->val);
            if (tempNode->left) {
                node_ptr_stack.push_back(tempNode->left);
            }
            if (tempNode->right) {
                node_ptr_stack.push_back(tempNode->right);
            }
        }
        if (!zig.empty()) {
            result.push_back(zig);
        }
        vector<int> zag;
        while(!node_ptr_stack.empty()) {
            TreeNode* tempNode = node_ptr_stack.back();
            node_ptr_stack.pop_back();
            zag.push_back(tempNode->val);
            if (tempNode->right) {
                node_ptr_stack0.push_back(tempNode->right);
            }
            if (tempNode->left) {
                node_ptr_stack0.push_back(tempNode->left);
            }
        }
        if (!zag.empty()) {
            result.push_back(zag);
        }
    }
    return result;
}

int main() {

    return 0;
}
