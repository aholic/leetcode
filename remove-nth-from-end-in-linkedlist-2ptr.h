//https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) return NULL;

        ListNode *fast = head;
        int i = 0;
        while (i <= n && fast != NULL) {
            fast = fast->next;
            i++;
        }

        if (i != n+1) {
            head = head->next;
        } else {
            ListNode *slow = head;
            while (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = slow->next->next;
        }

        return head;
    }
};
