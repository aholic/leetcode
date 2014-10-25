//https://oj.leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode *root) {
        helper(root);
        return ret;
    }
    void helper(TreeNode *root) {
        if (root == NULL) return;
        if (root->left != NULL) helper(root->left);
        if (root->right != NULL) helper(root->right);
        ret.push_back(root->val);
    }
};
