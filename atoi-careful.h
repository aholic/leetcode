//https://oj.leetcode.com/submissions/detail/13394220/

class Solution {
public:
    int atoi(const char *str) {
        int len = strlen(str);
        int flag = 1;
        int start = 0;

        while (start < len && str[start] == ' ') start++;
        if (str[start] == '-' || str[start] == '+') {
            if (str[start] == '-') flag = -1;
            start ++;
            while (start < len && str[start] == '0') start++;
        }

        if (start == len || !isdigit(str[start])) return 0;

        int end = start+1;
        while(end < len && isdigit(str[end])) end++;

        string tmp;
        for (int i = start; i < end; i++) tmp += str[i];

        if (flag == 1 && (tmp.length() == 10 && tmp >= string("2147483647") || tmp.length() > 10)) return INT_MAX;
        if (flag == -1 && (tmp.length() == 10 && tmp >= string("2147483648") || tmp.length() > 10)) return INT_MIN;

        int ret = 0;
        for (int i = start; i < end; i++) {
            ret *= 10;
            ret += (str[i] - '0');
        }

        return ret * flag;
    }
};
