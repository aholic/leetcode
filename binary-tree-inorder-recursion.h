//https://oj.leetcode.com/problems/binary-tree-inorder-traversal/

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
    vector<int> ret;
    vector<int> inorderTraversal(TreeNode *root) {
        helper(root);
        return ret;
    }
    void helper(TreeNode* root) {
        if (root == NULL) return;
        helper(root->left);
        ret.push_back(root->val);
        helper(root->right);
    }
};
