//https://oj.leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;cd le 
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* go(ListNode* itr, int step) {
        while (itr != NULL && step > 0) {
            itr = itr->next;
            step -= 1;
        }
        return itr;
    }

    ListNode* reverse(ListNode *beforHead, ListNode *end) {
        ListNode *itr = beforHead->next;
        ListNode *tmp;
        while (itr != end) {
            ListNode *tmp = itr->next;
            itr->next = end->next;
            end->next = itr;
            itr = tmp;
        }
        tmp = beforHead->next;
        beforHead->next = end;
        return tmp;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode beforeHead(0);
        beforeHead.next = head;

        ListNode *beg = &beforeHead;
        ListNode *end = beg;

        while (true) {
            end = go(end, k);
            if (end == NULL) break;

            beg = reverse(beg, end);
            end = beg;
        }

        return beforeHead.next;
    }
};
