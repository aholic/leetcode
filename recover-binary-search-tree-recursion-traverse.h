//https://oj.leetcode.com/problems/recover-binary-search-tree/

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
    vector<TreeNode*> vec;
    void helper(TreeNode *root) {
        if (root == NULL) return;
        helper(root->left);
        vec.push_back(root);
        helper(root->right);
    }
    void recoverTree(TreeNode *root) {
        helper(root);
        TreeNode *n1 = NULL, *n2 = NULL;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i]->val < vec[i-1]->val) {
                if (n1 == NULL) n1 = vec[i-1];
                n2 = vec[i];
            }
        }

        int tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;
    }
};
