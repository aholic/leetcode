//https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode* findNext(TreeLinkNode* itr, TreeLinkNode* except = NULL) {
        while (itr != NULL && (itr->left == NULL || itr->left == except) && itr->right == NULL) {
            itr = itr->next;
        }

        if (itr == NULL) return itr;
        if (itr ->left != NULL && itr->left != except) return itr->left;
        if (itr->right != NULL) return itr->right;
    }
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        root->next = NULL;

        TreeLinkNode* itr = root;
        TreeLinkNode* nextHead = findNext(itr);

        while (nextHead != NULL) {
            while (itr != NULL) {
                if (itr->left != NULL) {
                    itr->left->next = findNext(itr, itr->left);
                }

                if (itr->right != NULL) {
                    itr->right->next = findNext(itr->next);
                }

                itr = itr->next;
            }
            itr = nextHead;
            nextHead = findNext(itr);
        }
    }
};
