//https://oj.leetcode.com/problems/clone-graph/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
*/
class Solution {
public:
    unordered_map<int, UndirectedGraphNode*> o2n;
    unordered_map<int, bool> vis;

    void dfsCopy(UndirectedGraphNode *node) {
        if (vis.find(node->label) != vis.end()) return;
        vis[node->label] = true;
        o2n[node->label] = new UndirectedGraphNode(node->label);
        for (int i = 0; i < node->neighbors.size(); i++) {
            dfsCopy(node->neighbors[i]);
        }
    }

    void dfsClone(UndirectedGraphNode *node) {
        if (vis.find(node->label) != vis.end()) return;
        vis[node->label] = true;
        for (int i = 0; i < node->neighbors.size(); i++) {
            o2n[node->label]->neighbors.push_back(o2n[node->neighbors[i]->label]);
            dfsClone(node->neighbors[i]);
        }
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        dfsCopy(node);
        vis.clear();
        dfsClone(node);
        UndirectedGraphNode *ret = o2n[node->label];
        o2n.clear();
        return ret;
    }
};
