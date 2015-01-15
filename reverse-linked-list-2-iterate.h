//https://oj.leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* go(ListNode* itr, int steps) {
        while (steps-- && itr != NULL) itr = itr->next;
        return itr;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;

        ListNode *beforeHead = new ListNode(0);
        beforeHead->next = head;
        beforeHead = go(beforeHead, m-1);

        ListNode *afterEnd = head;
        afterEnd = go(afterEnd, n);

        ListNode *itr = beforeHead->next;
        ListNode *reversedHead = afterEnd, *tmp = NULL;
        while (itr != afterEnd) {
            tmp = reversedHead;
            reversedHead = itr;
            itr = itr->next;
            reversedHead->next = tmp;
        }
        beforeHead->next = reversedHead;

        if (m == 1) return beforeHead->next;
        return head;
    }
};
