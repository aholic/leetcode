//https://oj.leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        char str1[20];
        char str2[20];
        sprintf(str1, "%d", x);
        bool neg = (str1[0] == '-');
        int len = strlen(str1);

        if (neg) {
            str2[0] = '-';
            for (int i = 1; i < len; i++) str2[i] = str1[len-i];
        } else {
            for (int i = 0; i < len; i++) str2[i] = str1[len-i-1];
        }
        str2[len] = '\0';
        return atoi(str2);
    }
};
