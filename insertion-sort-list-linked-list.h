//https://oj.leetcode.com/problems/insertion-sort-list/

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
    ListNode* insert(ListNode* head, int len, ListNode* node) {
        if (head == NULL) return head;

        if (node->val <= head->val) {
            node->next = head;
            return node;
        }

        ListNode *itr = head, *after = head->next;
        while (after != NULL && --len > 0) {
            if (after->val >= node->val) {
                itr->next = node;
                node->next = after;
                return head;
            }

            itr = itr->next;
            after = itr->next;
        }

        itr->next = node;
        node->next = after;
        return head;
    }

    bool isLast(ListNode *head, int len, ListNode* node) {
        while (--len) {
            head = head->next;
        }
        return head == node;
    }

    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* itr = head, *node;
        int len = 1;
        while (itr != NULL) {
            node = itr->next;
            if (node == NULL) return head;

            itr->next = node->next;
            head = insert(head, len++, node);
            if (!isLast(head, len, itr)) itr = itr->next;
        }

        return head;
    }
};
