//https://oj.leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool equ(char a, char b) {
        if (isalnum(a) && isalnum(b) && (a == b || a - b == 32 || b - a == 32)) return true;
        return false;
    }

    bool isPalindrome(string s) {
        int len = s.length();

        int start = 0, end = len - 1;
        while (start < end) {
            while (start < end && !isalnum(s[start])) start ++;
            while (end > start && !isalnum(s[end])) end--;
            if (start >= end) break;

            if (!equ(s[start], s[end])) return false;
            start++;end--;
        }
        return true;
    }
};
