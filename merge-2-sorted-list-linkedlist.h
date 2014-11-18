//https://oj.leetcode.com/problems/merge-two-sorted-lists/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *i = l1;
        ListNode *j = l2;

        ListNode *ret = NULL;
        if (i->val > j->val) {
            ret = j;
            j = j->next;
        } else {
            ret = i;
            i = i->next;
        }
        ListNode *end = ret;

        while (i != NULL && j != NULL) {
            if (i->val > j->val) {
                end->next = j;
                end = end->next;
                j = j->next;
            } else {
                end->next = i;
                end = end->next;
                i = i->next;
            }
        }
        if (i != NULL) {
            while (i != NULL) {
                end->next = i;
                end = end->next;
                i = i->next;
            }
        } else if (j != NULL) {
            while (j != NULL) {
                end->next = j;
                end = end->next;
                j = j->next;
            }
        }

        return ret;
    }
};
