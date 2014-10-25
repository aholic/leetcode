//https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/

/**
 *   Definition for binary tree
 *   struct TreeNode {
 *       int val;
 *       TreeNode *left;
 *       TreeNode *right;
 *       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *   };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        root->val = 1;
        q.push(root);

        TreeNode* tmp;
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            if (tmp->left != NULL) {
                tmp->left->val = tmp->val + 1;
                q.push(tmp->left);
            }
            if (tmp->right != NULL) {
                tmp->right->val = tmp->val + 1;
                q.push(tmp->right);
            }
        }
        return tmp->val;
    }
};
