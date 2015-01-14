//https://oj.leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<vector<vector<TreeNode *> > > dp;
    vector<TreeNode *> helper(int start, int end) {
        if (start > end) return vector<TreeNode *>(1, NULL);

        if (dp[start-1][end-1].size() != 0) return dp[start-1][end-1];

        for (int root = start; root <= end; root++) {
            vector<TreeNode *> left = helper(start, root-1);
            vector<TreeNode *> right = helper(root+1, end);
            for (int i = 0; i < left.size(); i++) {
                for (int j = 0; j < right.size(); j++) {
                    TreeNode *tmp = new TreeNode(root);
                    tmp->left = left[i];
                    tmp->right = right[j];
                    dp[start-1][end-1].push_back(tmp);
                }
            }
        }

        return dp[start-1][end-1];
    }

    vector<TreeNode *> generateTrees(int n) {
        dp.resize(n);
        for (int i = 0; i < n; i++) dp[i].resize(n);

        return helper(1, n);
    }
};
