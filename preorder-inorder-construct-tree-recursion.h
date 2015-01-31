//https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    unordered_map<int, int> pos;
    TreeNode *helper(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie) {
        if (pe < ps || ie < is) return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);
        int mid = pos[root->val];
        root->left = helper(preorder, ps+1, ps+mid-is, inorder, is, mid-1);
        root->right = helper(preorder, pe-ie+mid+1, pe, inorder, mid+1, ie);
            return root;
        }
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            for (int i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;
            return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        }
};
