//https://oj.leetcode.com/problems/roman-to-integer/

class Solution {
public:
    string pre(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C' || s[i] == 'M') {
                s[i] = '1';
            } else {
                s[i] = '5';
            }
        }
        return s;
    }

    int transfer(string s) {
        if (s.length() == 2 && (s[0] == 'I' && s[1] == 'X' || s[0] == 'X' && s[1] == 'C' || s[0] == 'C' && s[1] == 'M')) return 9;

        s = pre(s);
        if (s == "1") return 1;
        if (s == "11") return 2;
        if (s == "111") return 3;
        if (s == "15") return 4;
        if (s == "5") return 5;
        if (s == "51") return 6;
        if (s == "511") return 7;
        if (s == "5111") return 8;
    }

    int romanToInt(string s) {
        string el[] = { "IV", "LX", "CD", "M" };
        int digit[] = { 0, 0, 0, 0 };

        int idx = 0;
        for (int i = 0; i < 4; i++) {
            idx = s.find_first_of(el[i]);
            if (idx != string::npos) {
                digit[i] = transfer(s.substr(idx, s.length() - idx));
                s = s.substr(0, idx);
            }
        }

        return 1000 * digit[3] + 100 * digit[2] + 10 * digit[1] + digit[0];
    }
};
