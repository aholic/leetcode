//https://oj.leetcode.com/problems/implement-strstr/

class Solution {
public:
    bool cmp (char* str1, char *str2) {
        while (*str1 != '\0' && *str2 != '\0') {
            if (*str1 != *str2) return false;
            str1++;
            str2++;
        }
        return true;
    }
    int strStr(char *haystack, char *needle) {
        int hlen = strlen(haystack);
        int nlen = strlen(needle);

        if (nlen == 0) return 0;
        if (hlen == 0) return -1;

        char *itr = haystack;
        while (*itr != '\0' && hlen - (itr - haystack) >= nlen) {
            if (cmp(itr, needle)) return (itr - haystack);
            itr++;
        }
        return -1;
    }
};
