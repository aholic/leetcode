//https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if (root == NULL) return vector<vector<int> >();

        stack<TreeNode *> sta, next;
        vector<vector<int> > ret;

        TreeNode *tmp;
        vector<int> vtmp;
        bool l2r = true;

        sta.push(root);
        while (!sta.empty()) {
            tmp = sta.top();
            sta.pop();
            if (l2r) {
                if (tmp->left != NULL) next.push(tmp->left);
                if (tmp->right != NULL) next.push(tmp->right);
            } else {
                if (tmp->right != NULL) next.push(tmp->right);
                if (tmp->left != NULL) next.push(tmp->left);
            }
            vtmp.push_back(tmp->val);

            if (sta.empty()) {
                ret.push_back(vtmp);
                vtmp.clear();
                sta = next;
                next = stack<TreeNode *>();
                l2r = !l2r;
            }
        }

        return ret;
    }
};
