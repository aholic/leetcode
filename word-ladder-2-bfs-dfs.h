//https://oj.leetcode.com/problems/word-ladder-ii/

class Solution {
public:
    unordered_map<string, vector<vector<string>>> path;
    void backtracking(string start, unordered_map<string, vector<string>>& next) {
        vector<string>& childs = next[start];
        if (childs.size() == 0) {
            path[start] = vector<vector<string>>({{start}});
            return;
        }

        vector<vector<string>> ret;
        for (int i = 0; i < childs.size(); i++) {
            vector<vector<string>> tmp;
            if (path.find(childs[i]) == path.end()) {
                backtracking(childs[i], next);
            } 
            tmp = path[childs[i]];
            for (int j = 0; j < tmp.size(); j++) {
                tmp[j].push_back(start);
                ret.push_back(tmp[j]);
            }
        }

        path[start] = ret;
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        unordered_map<string, vector<string>> prev;
        unordered_map<string, int> level;

        dict.erase(start);
        dict.insert(end);

        q.push(start);
        level[start] = 1;
        while (!q.empty()) {
            string tmp = q.front();
            if (level.find(end) != level.end() && level[end] <= level[tmp]) break;

            for (int i = 0; i < tmp.length(); i++) {
                char tmpc = tmp[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == tmpc) continue;
                    tmp[i] = c;

                    if (dict.find(tmp) == dict.end()) continue;
                    if (level.find(tmp) != level.end() && level[tmp] <= level[q.front()]) continue;

                    if (level.find(tmp) == level.end()) {
                        q.push(tmp);
                        level[tmp] = level[q.front()] + 1;
                    }
                    prev[tmp].push_back(q.front());
                }
                tmp[i] = tmpc;
            }

            q.pop();
        }

        if (prev[end].size() == 0) return vector<vector<string>>();
        backtracking(end, prev);
        return path[end];
    }
};
