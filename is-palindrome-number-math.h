//https://oj.leetcode.com/problems/palindrome-number/

class Solution {
public:
    int tb[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0) return false;

        int len = 9;
        while (x / tb[len] == 0) len--;

        for (int i = 0; i <= len / 2; i++) {
            if ((x / tb[i]) % 10 != (x / tb[len-i]) % 10) return false;
        }

        return true;
    }
};
