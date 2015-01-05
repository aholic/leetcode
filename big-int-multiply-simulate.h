//https://oj.leetcode.com/problems/multiply-strings/

class Solution {
public:
    string add(string num1, string num2) {
        int idx1 = num1.length() - 1;
        int idx2 = num2.length() - 1;

        string ret = "";
        int tmp, jw = 0;
        while (idx1 >= 0 && idx2 >= 0) {
            tmp = (num1[idx1] - '0') + (num2[idx2] - '0') + jw;
            jw = tmp / 10;
            ret.insert(0, 1, '0' + (tmp % 10));
            idx1--;
            idx2--;
        }

        while (idx1 >= 0) {
            tmp = (num1[idx1] - '0') + jw;
            jw = tmp / 10;
            ret.insert(0, 1, '0' + (tmp % 10));
            idx1--;
        }

        while (idx2 >= 0) {
            tmp = (num2[idx2] - '0') + jw;
            jw = tmp / 10;
            ret.insert(0, 1, '0' + (tmp % 10));
            idx2--;
        }

        if (jw > 0) {
            ret.insert(0, 1, '0' + jw);
        }

        return ret;
    }

    string mul(string num1, string num2) {
        long long n1 = atoi(num1.c_str());
        long long n2 = atoi(num2.c_str());
        char buf[30];
        sprintf(buf, "%lld", n1*n2);
        return string(buf);
    }

    string multiply(string num1, string num2) {
        if (num1.length() < 1 || num2.length() < 1) return "";

        bool isNeg = false;
        if (num1[0] == '-' && num2[0] != '-' || num1[0] != '-' && num2[0] == '-') isNeg = true;
        if (num1[0] == '-') num1 = num1.substr(1);
        if (num2[0] == '-') num2 = num2.substr(1);

        int tmp;
        tmp = num1.length() % 9;
        if (tmp != 0) num1.insert(0, 9-tmp, '0');
        tmp = num2.length() % 9;
        if (tmp != 0) num2.insert(0, 9-tmp, '0');

        int l1 = num1.length();
        int l2 = num2.length();

        string ret = "0";
        string stmp;
        for (int i = 0; i < l1; i += 9) {
            for (int j = 0; j < l2; j += 9) {
                stmp = mul(num1.substr(i, 9), num2.substr(j, 9));
                tmp = l1 - i - 9 + l2 - j - 9;
                stmp.append(tmp, '0');
                ret = add(ret, stmp);
            }
        }

        if (atoi(ret.c_str()) == 0) return string("0");
        if (isNeg) ret.insert(0, 1, '-');

        return ret;
    }
};
