//https://oj.leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        ListNode *itrA = headA;
        ListNode *itrB = headB;

        while (itrA->next != NULL) itrA = itrA->next;
        while (itrB->next != NULL) itrB = itrB->next;

        if (itrA != itrB) return NULL;

        itrA->next = headB;

        ListNode *slow = headA;
        ListNode *fast = headA;
        int l = 0;
        while (true) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
            l++;
            if (fast == slow) break;
        }

        slow = headA;
        fast = headA;
        while (l--) fast = fast->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        itrB->next = NULL;
        return slow;
    }
};
