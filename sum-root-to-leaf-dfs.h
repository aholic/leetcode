//https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int ans = 0;
    void dfs(TreeNode *root, int num) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            ans += (num * 10 + root->val);
        } else if (root->left != NULL && root->right != NULL) {
            dfs(root->left, 10*num+root->val);
            dfs(root->right, 10*num+root->val);
        } else if (root->left != NULL) {
            dfs(root->left, 10*num+root->val);
        } else if (root->right != NULL) {
            dfs(root->right, 10*num+root->val);
        }
    }
    int sumNumbers(TreeNode *root) {
        if (root == NULL) return ans;
        dfs(root, 0);
        return ans;
    }
};
