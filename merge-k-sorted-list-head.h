//https://oj.leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp {
    bool operator () (const ListNode* p1, const ListNode* p2) const {
        return p1->val > p2->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) que.push(lists[i]);
        }

        ListNode *head = NULL, *end = NULL;
        while (!que.empty()) {
            ListNode *tmp = que.top();
            que.pop();
            if (head == NULL) {
                head = tmp;
            } else {
                end->next = tmp;
            }
            end = tmp;
            if (tmp->next != NULL) {
                que.push(tmp->next);
                tmp->next = NULL;
            }
        }

        return head;
    }
};
