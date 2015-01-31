//https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode *helper(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe) {
        if (pe < ps || ie < is) return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);
        int mid = pos[root->val];
        root->left = helper(inorder, is, mid-1, postorder, ps, ps+mid-is-1);
        root->right = helper(inorder, mid+1, ie, postorder, pe-ie+mid, pe-1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        for (int i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
