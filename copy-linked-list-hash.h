//https://oj.leetcode.com/problems/copy-list-with-random-pointer/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;

        unordered_map<RandomListNode*, RandomListNode*> old2new;
        old2new.insert(pair<RandomListNode*, RandomListNode*>(NULL, NULL));

        RandomListNode *ret, *nitr, *oitr;
        ret = new RandomListNode(head->label);
        old2new.insert(make_pair(head, ret));
        auto tmp = old2new.find(head->random);
        if (tmp != old2new.end()) {
            ret->random = tmp->second;
        } else {
            ret->random = new RandomListNode(head->random->label);
            old2new.insert(make_pair(head->random, ret->random));
        }

        nitr = ret;
        oitr = head->next;
        while (oitr != NULL) {
            tmp = old2new.find(oitr);
            if (tmp != old2new.end()) {
                nitr->next = tmp->second;
            } else {
                nitr->next = new RandomListNode(oitr->label);
                old2new.insert(make_pair(oitr, nitr->next));
            }

            tmp = old2new.find(oitr->random);
            if (tmp != old2new.end()) {
                nitr->next->random = tmp->second;
            } else {
                nitr->next->random = new RandomListNode(oitr->random->label);
                old2new.insert(make_pair(oitr->random, nitr->next->random));
            }

            nitr = nitr->next;
            oitr = oitr->next;
        }
        nitr->next = NULL;

        return ret;
    }
};
