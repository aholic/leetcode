//https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode *helper(vector<int> &num, int low, int high) {
        if (high - low == 0) return NULL;
        if (high - low == 1) return (new TreeNode (num[low]));

        int mid = low + (high - low) / 2;
        TreeNode* tmp = new TreeNode(num[mid]);
        tmp->left = helper(num, low, mid);
        tmp->right = helper(num, mid+1, high);
        return tmp;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return helper(num, 0, num.size());
    }
};
