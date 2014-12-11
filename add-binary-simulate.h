//https://oj.leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "") return b;
        if (b == "") return a;
        if (a.length() < b.length()) {
            string tmp = a;
            a = b;
            b = tmp;
        }

        int al = a.length();
        int bl = b.length();

        string ret = "";
        int jw = 0;
        for (int i = 1; i <= bl; i++) {
            int tmp = (a[al-i] - '0') + (b[bl-i] - '0') + jw;
            jw = tmp / 2;
            ret.insert(0, 1, char('0' + (tmp % 2)));
        }
        for (int i = bl + 1; i <= al; i++) {
            int tmp = (a[al-i] - '0') + jw;
            jw = tmp / 2;
            ret.insert(0, 1, char('0' + (tmp % 2)));
        }
        if (jw != 0) ret.insert(0, 1, char('0' + jw));
        return ret;
    }
};
