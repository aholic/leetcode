//https://oj.leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > v;
        if (root == NULL) return v;

        queue<pair<TreeNode*, int> > q;
        pair<TreeNode*, int> tmp;
        q.push(pair<TreeNode*, int>(root, 1));
        while (!q.empty()) {
            tmp = q.front();
            q.pop();

            v.resize(tmp.second);
            v[tmp.second-1].push_back((tmp.first)->val);
            if ((tmp.first)->left != NULL) q.push(pair<TreeNode*, int>((tmp.first)->left, tmp.second+1));
            if ((tmp.first)->right != NULL) q.push(pair<TreeNode*, int>((tmp.first)->right, tmp.second+1));
        }

        return v;
    }
};
