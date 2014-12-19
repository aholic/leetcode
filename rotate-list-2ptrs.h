//https://oj.leetcode.com/problems/rotate-list/

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
        while (steps--) itr = itr->next;
        return itr;
    }

    int len(ListNode* itr) {
        int ret = 0;
        while (itr != NULL) {
            itr = itr->next;
            ret ++;
        }
        return ret;
    }

    ListNode *rotateRight(ListNode *head, int k) {
        int l = len(head);
        if (l == 0) return head;
        k %= l;
        if (k == 0 || l == 0) return head;

        ListNode* fast = go(head, k);
        ListNode* slow = head;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        ListNode* tmp = slow->next;
        slow->next = NULL;
        return tmp;
    }
};
