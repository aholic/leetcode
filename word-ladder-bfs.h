//https://oj.leetcode.com/problems/word-ladder/

class Solution {
public:
    bool trans(const string& s1, const string& s2) {
        bool found = false;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (found) return false;
                found = true;
            }
        }
        return found;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int>> que;
        que.push(make_pair(start, 1));

        while (!que.empty()) {
            auto tmp = que.front();
            que.pop();

            if (trans(tmp.first, end)) return tmp.second+1;

            for (int i = 0; i < tmp.first.length(); i++) {
                char tmpc = tmp.first[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c != tmpc) {
                        tmp.first[i] = c;
                        auto itr = dict.find(tmp.first);
                        if (itr == dict.end()) continue;
                        que.push(make_pair(tmp.first, tmp.second+1));
                        dict.erase(itr);
                    }
                }
                tmp.first[i] = tmpc;
            }
        }

        return 0;
    }
};
