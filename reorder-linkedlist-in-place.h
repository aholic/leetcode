//https://oj.leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode *head) {
        if (head == NULL) return;
        if (head-> next == NULL) return;

        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL) break;
            fast = fast->next;
        }

        ListNode *mid = slow;
        ListNode *tail = NULL;
        ListNode *tmp = NULL;
        while (slow->next != NULL) {
            tmp = slow->next;
            slow->next = tail;
            tail = slow;
            slow = tmp;
        }
        slow->next = tail;

        ListNode *itr = head;
        while (slow != NULL && itr != mid) {
            tmp = itr->next;
            itr->next = slow;
            itr = tmp;

            tmp = slow->next;
            slow->next = itr;
            slow = tmp;
        }
        if (slow != NULL) slow->next = NULL;
        if (itr != NULL) itr->next = NULL;
    }
};
