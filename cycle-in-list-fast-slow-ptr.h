//https://oj.leetcode.com/problems/linked-list-cycle/

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
    bool jump1(ListNode** ptr) {
        if ((*ptr)->next == NULL) return false;
        *ptr = (*ptr)->next;
        return true;
    }

    bool jump2(ListNode** ptr) {
        if (!jump1(ptr)) return false;
        return jump1(ptr);
    }

    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;

        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL ) {
            if (!jump2(&fast)) return false;
            if (!jump1(&slow)) return false;
            if (fast == slow) return true;
        }
        return false;
    }
};
