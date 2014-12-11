//https://oj.leetcode.com/problems/validate-binary-search-tree/

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
    bool helper(TreeNode *root, long long low, long long high) {
        if (root == NULL) return true;
        if (root->val <= low || root->val >= high) return false;
        if (root->left == NULL && root->right == NULL) return true;

        if (root->left == NULL) return (root->val < root->right->val && helper(root->right, root->val, high));
        if (root->right == NULL) return (root->val > root->left->val && helper(root->left, low, root->val));
        return (
                root->val > root->left->val 
                && root->val < root->right->val 
                && helper(root->right, root->val, high)
                && helper(root->left, low, root->val)
               );
    }
    bool isValidBST(TreeNode *root) {
        return helper(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
    }
};
