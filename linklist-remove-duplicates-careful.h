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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *itr = head;

        while (itr != NULL && itr->next != NULL) {
            if (itr->val == itr->next->val) {
                itr->next = itr->next->next;
            } else {
                itr = itr->next;
            }
        }
        return head;
    }
};
