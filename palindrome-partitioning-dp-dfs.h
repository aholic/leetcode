//https://oj.leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    unordered_map<int, vector<vector<string>>> dict;
    vector<vector<bool>> isPal;

    void helper(const string& s, int start) {
        if (dict.find(start) != dict.end()) return;

        vector<vector<string>> ret;
        if (isPal[start][s.length()-1]) ret.push_back({s.substr(start)});
        for (int len = 1; start + len < s.length(); len++) {
            if (!isPal[start][start+len-1]) continue;

            helper(s, start + len);
            auto tmp = dict[start + len];
            for (int i = 0; i < tmp.size(); i++) {
                tmp[i].insert(tmp[i].begin(), s.substr(start, len));
                ret.push_back(tmp[i]);
            }
        }

        dict[start] = ret;
    }

    void initIsPal(const string& s, int len) {
        isPal.resize(len);
        for (int i = 0; i < isPal.size(); i++) isPal[i].resize(len);

        for (int i = len-1; i>= 0; i--) {
            for (int j = i; j <= len-1; j++) {
                if (i == j) {
                    isPal[i][j] = true;
                } else if (i + 1 == j) {
                    isPal[i][j] = s[i] == s[j];
                } else {
                    isPal[i][j] = s[i] == s[j] && isPal[i+1][j-1];
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        initIsPal(s, s.length());
        helper(s, 0);
        return dict[0];
    }
};
