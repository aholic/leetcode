//https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* mid(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL) break;
            fast = fast->next;
        }

        prev->next = NULL;
        return slow;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return (new TreeNode(head->val));

        ListNode *m = mid(head);
        ListNode *left = head;
        ListNode *right = m->next;

        TreeNode *ret = new TreeNode(m->val);
        ret->left = sortedListToBST(head);
        ret->right = sortedListToBST(m->next);

        return ret;
    }
};
