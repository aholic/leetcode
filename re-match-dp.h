//https://oj.leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    string to(char c) {
        string tmp = "";
        tmp.append(1, c);
        return tmp;
    }

    bool match(const string& p, char c) {
        if (p == ".") return true;
        if (p[0] == c) return true;
        if (p.length() == 2 && p == ".*") return true;

        return false;
    }

    bool anyStar(const string& p) {
        return p.length() == 2 && p[1] == '*';
    }

    int getLongestAnyStar(const vector<string>& pat) {
        int ret = 0;
        while (ret < pat.size() && anyStar(pat[ret])) ret += 1;
        return ret;
    }

    void preAction(vector<string>& pat, const char *p) {
        int pl = strlen(p);
        for (int i = 0; i < pl; i++) {
            if (p[i] == '*') {
                pat[pat.size() - 1].append(1, '*');
                continue;
            }
            pat.push_back(to(p[i]));
        }
    }

    bool isMatch(const char *s, const char *p) {
        int len = strlen(s);
        vector<string> pat;
        preAction(pat, p);

        int longestAnyStar = getLongestAnyStar(pat);

        if (len == 0 && pat.size() == 0) return true;
        if (pat.size() == 0) return false;
        if (len == 0) return longestAnyStar == pat.size();

        vector<vector<bool> > dp(pat.size());
        for (int i = 0; i < pat.size(); i++) dp[i].resize(len);

        for (int i = 0; i < pat.size(); i++) {
            for (int j = 0; j < len; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = match(pat[i], s[j]);
                } else if (i == 0 && j != 0) {
                    dp[i][j] = dp[i][j-1] && match(pat[i], s[j]) && anyStar(pat[i]);
                } else if (i != 0 && j == 0) {
                    dp[i][j] = (anyStar(pat[i]) && dp[i-1][j])
                            || (match(pat[i], s[j]) && longestAnyStar >= i);
                } else {
                    dp[i][j] = ((anyStar(pat[i]) && dp[i-1][j])
                            || (match(pat[i], s[j]) && dp[i-1][j-1])
                            || (anyStar(pat[i]) && dp[i][j-1] && match(pat[i], s[j])));
                }
            }
        }

        return dp[pat.size()-1][len-1];
    }
};
