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
    ListNode* mid(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *fast = head, *slow = head, *end = NULL;
        while (fast != NULL) {
            fast = fast->next;
            if (fast == NULL) break;
            end = slow;
            slow = slow->next;
            fast = fast->next;
        }
        end->next = NULL;
        return slow;
    }

    ListNode* merge(ListNode *l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* ret = l1;
        if (l1->val >= l2->val) ret = l2;

        ListNode* itr1 = l1, *itr2 = l2, *itr = NULL;
        while (itr1 != NULL && itr2 != NULL) {
            if (itr1->val < itr2->val) {
                if (itr != NULL) itr->next = itr1;
                itr = itr1;
                itr1 = itr1->next;
            } else {
                if (itr != NULL) itr->next = itr2;
                itr = itr2;
                itr2 = itr2->next;
            }
        }

        while (itr1 != NULL) {
            itr->next = itr1;
            itr1 = itr1->next;
            itr = itr->next;
        }

        while (itr2 != NULL) {
            itr->next = itr2;
            itr2 = itr2->next;
            itr = itr->next;
        }

        itr->next = NULL;
        return ret;
    }

    ListNode* sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *tmp = sortList(mid(head));
        return merge(sortList(head), tmp);
    }
};
