#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) {
        return nullptr;
    }
    else if (inorder.size() == 1 && postorder.size() == 1) {
        TreeNode* n = new TreeNode(inorder[0]);
        return n;
    }
    else {
        int val = postorder[postorder.size() - 1];
        int i = 0;
        for (; i < inorder.size(); i++) {
            if (inorder[i] == val) {
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + i);
        TreeNode* left = buildTree(leftInorder, leftPostorder);
        vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());
        vector<int> rightPostorder(postorder.begin() + i, postorder.end() - 1);
        TreeNode* right = buildTree(rightInorder, rightPostorder);
        TreeNode* n = new TreeNode(val, left, right);
        return n;
    }
}