//https://oj.leetcode.com/problems/path-sum-ii/

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
    vector<int> path;

    bool isLeaf(TreeNode *node) {
        return node->left == NULL && node->right == NULL;
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (root == NULL) return vector<vector<int> >();

        if (isLeaf(root)) {
            if (sum != root->val) return vector<vector<int> >();
            vector<int> tmp = path;
            tmp.push_back(root->val);
            return vector<vector<int> >(1, tmp);
        }

        path.push_back(root->val);
        vector<vector<int> > left = pathSum(root->left, sum-root->val);
        vector<vector<int> > right = pathSum(root->right, sum-root->val);
        path.pop_back();

        vector<vector<int> > ret;
        for (int i = 0; i < left.size(); i++) ret.push_back(left[i]);
        for (int i = 0; i < right.size(); i++) ret.push_back(right[i]);

        return ret;
    }
};
