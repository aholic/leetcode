//https://oj.leetcode.com/problems/binary-search-tree-iterator/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> sta;
    void pushStack(TreeNode* node) {
        while (node != NULL) {
            sta.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        pushStack(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !(sta.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = sta.top();
        sta.pop();
        pushStack(top->right);
        return top->val;
    }
};

/**
  * Your BSTIterator will be called like this:
  * BSTIterator i = BSTIterator(root);
  * while (i.hasNext()) cout << i.next();
  */
