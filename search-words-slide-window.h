//https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        if (L.empty()) return vector<int>();

        int wl = L[0].length();
        int num = L.size();
        int slen = S.length();
        unordered_map<string, int> origin;
        for (int i = 0; i < L.size(); i++) origin[L[i]] += 1;

        vector<int> ret;
        for (int i = 0; i < wl; i++) {
            queue<string> q;
            unordered_map<string, int> toCheck = origin;

            int j = i;
            while (j + (num - q.size()) * wl <= slen) {
                string tmp = S.substr(j, wl);
                if (toCheck.find(tmp) == toCheck.end()) {
                    j += wl;
                    q = queue<string>();
                    toCheck = origin;
                    continue;
                } else if (toCheck[tmp] == 0) {
                    while (q.front() != tmp) {
                        toCheck[q.front()] += 1;
                        q.pop();
                    }
                    toCheck[q.front()] += 1;
                    q.pop();
                }

                toCheck[tmp] -= 1;
                q.push(tmp);
                j += wl;

                if (q.size() == num) {
                    ret.push_back(j - wl * num);
                    tmp = q.front();
                    q.pop();
                    toCheck[tmp] += 1;
                }
            }
        }
        return ret;
    }
};
