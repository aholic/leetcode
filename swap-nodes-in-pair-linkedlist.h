//https://oj.leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) return head;
        if (head->next == NULL) return head;

        ListNode *ret = head->next;
        ListNode *itr = head;
        ListNode *last = NULL;
        ListNode *tmp = NULL;
        while (itr != NULL && itr->next != NULL) {
            tmp = itr->next;
            itr->next = tmp->next;
            tmp->next = itr;
            if (last != NULL) last->next = tmp;
            last = itr;
            itr = itr->next;
        }
        return ret;
    }
};
