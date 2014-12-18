//https://oj.leetcode.com/problems/partition-list/

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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* l1head = NULL, *l1end = NULL;
        ListNode* l2head = NULL, *l2end = NULL;

        ListNode* itr = head;
        while (itr != NULL) {
            if (itr->val < x) {
                if (l1head == NULL) {
                    l1head = itr;
                    l1end = itr;
                } else {
                    l1end->next = itr;
                    l1end = itr;
                }
            } else {
                if (l2head == NULL) {
                    l2head = itr;
                    l2end = itr;
                } else {
                    l2end->next = itr;
                    l2end = itr;
                }
            }
            itr = itr->next;
        }
        if (l2end != NULL) l2end->next = NULL;
        if (l1head == NULL) return l2head;
        l1end->next = l2head;
        return l1head;
    }
};
