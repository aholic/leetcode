//https://oj.leetcode.com/problems/word-break-ii/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        vector<int> dp[len];

        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= i; j++) {
                if (dict.find(s.substr(j, i-j+1)) != dict.end()) {
                    dp[i].push_back(j);
                }
            }
        }

        dfs(dp, len-1, "", s);
        return ret;
    }

    vector<string> ret;

    void dfs(vector<int> *prev, int idx, string str, const string& src) {
        if (idx == -1) {
            cout << str << endl;
            ret.push_back(str.substr(1));
            return;
        }
        if (prev[idx].empty()) return;

        for (int i = 0; i < prev[idx].size(); i++) {
            string tmp = " " + src.substr(prev[idx][i], idx-prev[idx][i]+1) + str;
            dfs(prev, prev[idx][i]-1, tmp, src);
        }
    }
};
