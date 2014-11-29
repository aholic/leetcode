//https://oj.leetcode.com/problems/add-two-numbers/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *itr1 = l1;
        ListNode *itr2 = l2;

        ListNode *ret = NULL;
        ListNode *end = NULL;
        int jw = 0;

        while (itr1 != NULL || itr2 != NULL) {
            int val = 0;
            if (itr1 != NULL) val += itr1->val;
            if (itr2 != NULL) val += itr2->val;
            val += jw;

            ListNode *tmp = new ListNode(val % 10);
            jw = val / 10;

            if (ret == NULL) {
                ret = tmp;
                end = tmp;
            } else {
                end->next = tmp;
                end = end->next;
            }

            if (itr1 != NULL) itr1 = itr1->next;
            if (itr2 != NULL) itr2 = itr2->next;
        }

        if (jw != 0) {
            ListNode *tmp = new ListNode(jw);
            end->next = tmp;
            end = end->next;
        }

        return ret;
    }
};
