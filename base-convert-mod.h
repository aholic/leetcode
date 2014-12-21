//https://oj.leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while (n > 0) {
            ret.insert(0, 1, 'A' + ((n - 1) % 26));
            n = (n - 1) / 26;
        }
        return ret;
    }
};
