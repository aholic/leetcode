//https://oj.leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int l = strlen(s);

        int idx = l - 1;
        while (idx >= 0 && s[idx] == ' ') idx--;

        if (idx == -1) return 0;
        if (s[idx] == ' ') idx--;

        int ret = 0;
        while (idx >= 0 && s[idx] != ' ') {
            idx--;
            ret++;
        }

        return ret;
    }
};
