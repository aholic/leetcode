//https://oj.leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode *root) {
        helper(root);
        return ret;
    }
    void helper(TreeNode* root) {
        if (root == NULL) return;
        ret.push_back(root->val);
        helper(root->left);

        helper(root->right);
    }
};

