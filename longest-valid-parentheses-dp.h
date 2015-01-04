//https://oj.leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int findMatch(const vector<int>& vec, const string& s, int idx) {
        if (idx == s.length() -1) return -1;
        if (s[idx+1] == ')') return idx+1;
        if (vec[idx+1] == -1) return -1;

        idx = vec[idx+1];
        return findMatch(vec, s, idx);
    }
    int longestValidParentheses(string s) {
        vector<int> vec(s.length());

        for (int i = s.length() - 1; i >= 0; i--) {
            if (i == s.length() - 1 || s[i] == ')') {
                vec[i] = -1;
            } else if (s[i] == '(') {
                vec[i] = findMatch(vec, s, i);
            }
        }

        int ml = 0, idx = 0, tmp = 0;
        while (idx < vec.size()) {
            if (vec[idx] < 0) {
                idx++;
                tmp = 0;
            } else {
                tmp += (vec[idx] - idx + 1);
                ml = tmp > ml ? tmp : ml;
                idx = vec[idx] + 1;
            }
        }

        return ml;
    }
};
