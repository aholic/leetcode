//https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int max(int a, int b, int c) {
        return max(a, max(b, c));
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        int ret = root->val;
        int tmp = helper(root, ret);
        return max(tmp, ret);
    }

    int helper(TreeNode *root, int& ret) {
        if (root == NULL) return 0;

        int lmax = helper(root->left, ret);
        int rmax = helper(root->right, ret);

        int tmp = root->val;
        if (lmax > 0) tmp += lmax;
        if (rmax > 0) tmp += rmax;
        ret = max(tmp, ret);

        return max(root->val, root->val + lmax, root->val + rmax);
    }
};
