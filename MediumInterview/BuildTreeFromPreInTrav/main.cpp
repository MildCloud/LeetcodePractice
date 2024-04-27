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


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) {
        return nullptr;
    }
    else {
        TreeNode* root = new TreeNode;
        root->val = preorder[0];
        int inorderId = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                inorderId = i;
                break;
            }
        }
        if (inorderId > 0) {
            vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+1+inorderId);
            vector<int> leftInorder(inorder.begin(), inorder.begin()+inorderId);
            root->left = buildTree(leftPreorder, leftInorder);
        }
        else {
            root->left = nullptr;
        }
        if (inorderId < inorder.size()-1) {
            vector<int> rightPreorder(preorder.begin()+1+inorderId, preorder.end());
            vector<int> rightInorder(inorder.begin()+inorderId+1, inorder.end());
            root->right = buildTree(rightPreorder, rightInorder);
        }
        else {
            root->right = nullptr;
        }
        return root;
    }
}

int main() {
    return 0;
}
