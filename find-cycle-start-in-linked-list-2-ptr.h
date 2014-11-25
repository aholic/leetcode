//https://oj.leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        if (head == NULL) return NULL;
        if (head->next == NULL) return NULL;

        int len = 0;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
            len++;
            if (fast == slow) break;
        }

        if (fast == NULL || fast->next == NULL) return NULL;

        fast = head;
        for (int i = 0; i < len; i++) fast = fast->next;

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
