//https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int exist[128];
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        for (int i = 0; i < sizeof(exist) / sizeof(exist[0]); i++) exist[i] = -1;

        int ret = 0;
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            if (len + 1 > i - exist[s[i]]) {
                len = i - exist[s[i]];
            } else {
                len += 1;
            }
            exist[s[i]] = i;
            if (len > ret) ret = len;
        }
        return ret;
    }
};
