//https://oj.leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string to(int num, int digit) {
        if (digit == 4) return "M";
        if (digit == 3) return (num == 1 ? "C" : "D");
        if (digit == 2) return (num == 1 ? "X" : "L");
        if (digit == 1) return (num == 1 ? "I" : "V");
    }
    string transferBit(int num, int digit) {
        if (num == 9) return to(1, digit) + to(1, digit+1);
        if (num == 8) return to(5, digit) + to(1, digit) + to(1, digit) + to(1, digit);
        if (num == 7) return to(5, digit) + to(1, digit) + to(1, digit);
        if (num == 6) return to(5, digit) + to(1, digit);
        if (num == 5) return to(5, digit);
        if (num == 4) return to(1, digit) + to(5, digit);
        if (num == 3) return to(1, digit) + to(1, digit) + to(1, digit);
        if (num == 2) return to(1, digit) + to(1, digit);
        if (num == 1) return to(1, digit);
        if (num == 0) return "";
    }
    string intToRoman(int num) {
        char buf[5];
        sprintf(buf, "%d", num);
        int len = strlen(buf);

        string ret = "";
        for (int i = 0; i < len; i++) {
            ret += transferBit(buf[i]-'0', len-i);
        }

        return ret;
    }
};
