//https://oj.leetcode.com/problems/sort-list/

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
    ListNode* merge(ListNode *l1, ListNode* l2, ListNode* after) {
        if (l1 == NULL && l2 == NULL) return NULL;
        ListNode *itr1 = l1, *itr2 = l2, *itr = NULL;
        while (itr1 != NULL || itr2 != NULL) {
            if (itr2 == NULL || itr1 != NULL && itr1->val < itr2->val) {
                if (itr == NULL) {
                    after->next = itr1;
                } else {
                    itr->next = itr1;
                }
                itr = itr1;
                itr1 = itr1->next;
            } else if (itr1 == NULL || itr2 != NULL && itr1->val >= itr2->val) {
                if (itr == NULL) {
                    after->next = itr2;
                } else {
                    itr->next = itr2;
                }
                itr = itr2;
                itr2 = itr2->next;
            }
        }
        itr->next = NULL;

        return itr;
    }

    int getListLen(ListNode *head) {
        int ret = 0;
        while (head != NULL) {
            head = head->next;
            ret++;
        }
        return ret;
    }

    ListNode* nextList(ListNode *head, int len) {
        if (head == NULL) return NULL;

        ListNode* last = NULL;
        while (head != NULL && len > 0) {
            last = head;
            head = head->next;
            len--;
        }

        ListNode* tmp = last->next;
        last->next = NULL;
        return tmp;
    }

    ListNode* sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        int len = getListLen(head);

        ListNode ahead(0);
        ahead.next = head;

        ListNode *itr, *l1, *next;
        for (int step = 1; step < len; step *= 2) {
            itr = &ahead;
            while (itr->next != NULL) {
                l1 = nextList(itr->next, step);
                next = nextList(l1, step);
                itr = merge(itr->next, l1, itr);
                if (itr == NULL) break;
                itr->next = next;
            }
        }

        return ahead.next;
    }
};
