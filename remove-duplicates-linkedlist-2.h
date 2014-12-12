//https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    int findRange(ListNode *head) {
        if (head == NULL) return 0;
        int val = head->val;
        int ret = 0;
        while (head != NULL && head->val == val) {
            head = head->next;
            ret ++;
        }
        return ret;
    }

    ListNode* foward(ListNode *itr, int steps) {
        while (steps--) {
            itr = itr->next;
        }
        return itr;
    }

    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        int len = 0;
        ListNode* prev = head;
        ListNode* itr = head;
        bool ret = false;

        while (itr != NULL) {
            len = findRange(itr);
            if (len != 1) {
                itr = foward(itr, len);
                if (!ret) {
                    head = itr;
                    prev = head;
                } else {
                    prev->next = itr;
                }
            } else {
                if (!ret) {
                    ret = true;
                    head = itr;
                }
                prev = itr;
                itr = itr->next;
            }
        }

        return head;
    }
};
