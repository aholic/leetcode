//https://oj.leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    int getLen(const string& s, int idx1, int idx2) {
        int start = idx1, end = idx2;
        while (start >= 0 && end < s.length()) {
            if (s[start] != s[end]) break;
            start --;
            end ++;
        }
        return end - start - 1;
    }

    string longestPalindrome(string s) {
        int maxL1 = 0, maxL2 = 0;
        int p1, p2;

        int tmp;
        for (int i = 0; i < s.length(); i++) {
            tmp = getLen(s, i, i);
            if (tmp > maxL1) {
                maxL1 = tmp;
                p1 = i;
            }

            tmp = getLen(s, i, i+1);
            if (tmp > maxL2) {
                maxL2 = tmp;
                p2 = i;
            }
        }

        if (maxL1 > maxL2) {
            return s.substr(p1 - maxL1 / 2, maxL1);
        } else {
            return s.substr(p2 - maxL2 / 2 + 1, maxL2);
        }
    }
};
