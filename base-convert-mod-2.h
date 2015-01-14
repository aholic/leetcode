//https://oj.leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string s) {
        if (s == "") return 0;

        int ret = (s[0] - 'A' + 1);
        for (int i = 1; i < s.length(); i++) {
            ret *= 26;
            ret += (s[i] - 'A' + 1);
        }

        return ret;
    }
};
