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
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        root->next = NULL;

        TreeLinkNode* itr = root;
        TreeLinkNode* nextHead = itr->left;

        while (nextHead != NULL) {
            while (itr != NULL) {
                itr->left->next = itr->right;
                if (itr->next == NULL) {
                    itr->right->next = itr->next;
                } else {
                    itr->right->next = itr->next->left;
                }
                itr = itr->next;
            }
            itr = nextHead;
            nextHead = itr->left;
        }
    }
};
