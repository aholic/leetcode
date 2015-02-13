//https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    TreeNode* getRightmost(TreeNode *root) {
        if (root == NULL) return NULL;
        while (root->right != NULL) {
            root = root->right;
        }

        return root;
    }

    void flatten(TreeNode *root) {
        TreeNode *itr = root, *last = NULL;
        while (itr != NULL) {
            if (itr->left == NULL) {
                itr = itr->right;
                continue;
            }
            last = getRightmost(itr->left);
            last->right = itr->right;
            itr->right = itr->left;
            itr->left = NULL;
            itr = itr->right;
        }
    }
};
