//https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;

        if (root->left == NULL && root->right == NULL) {
            return 1;
        } else if (root->left != NULL && root->right != NULL) {
            int l = minDepth(root->left);
            int r = minDepth(root->right);
            return l<r ? l+1 : r+1;
        } else if (root->left != NULL) {
            return minDepth(root->left)+1;
        } else if (root->right != NULL) {
            return minDepth(root->right)+1;
        }
    }
};
