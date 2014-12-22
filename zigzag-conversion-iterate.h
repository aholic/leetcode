//https://oj.leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) return s;

        string ret = "";
        ret.reserve(s.length());

        int step = 2 * nRows - 2;

        for (int j = 0; j < s.length(); j += step) {
            ret.append(1, s[j]);
        }

        for (int i = 1; i < nRows - 1; i++) {
            for (int j = i; j < s.length(); j += step) {
                ret.append(1, s[j]);
                int tmp = step - 2 * i + j;
                if (tmp < s.length()) ret.append(1, s[tmp]);
            }
        }

        for (int j = nRows - 1; j < s.length(); j += step) {
            ret.append(1, s[j]);
        }

        return ret;
    }
};
