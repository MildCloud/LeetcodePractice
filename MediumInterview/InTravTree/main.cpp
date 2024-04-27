#include<iostream>
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


void help(TreeNode* root, vector<int> & v) {
    if (root) {
        help(root->left, v);
        v.push_back(root->val);
        help(root->right, v);
    }
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    help(root, v);
    return v;
}


int main() {

    return 0;
}
