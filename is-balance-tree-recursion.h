//https://oj.leetcode.com/problems/balanced-binary-tree/

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
    int absolute(int val) {
        return (val < 0 ? -val : val);
    }
    int height(TreeNode *root) {
        if (root == NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        root->val = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
        return root->val;
    }

    bool balance (TreeNode *root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        if (root->left == NULL && root->right != NULL) return root->right->val == 1;
        if (root->left != NULL && root->right == NULL) return root->left->val == 1;
        if (absolute(root->left->val - root->right->val) <= 1) return (balance(root->left) && balance(root->right));
        return false;
    }

    bool isBalanced(TreeNode *root) {
        height(root);
        return balance(root);
    }
};
