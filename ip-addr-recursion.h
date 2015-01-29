//https://oj.leetcode.com/problems/restore-ip-addresses/

class Solution {
public:
    int idx[4];
    string src;

    void push(vector<string>& vec, int idx[4]) {
        char buff[20];
        sprintf(buff, "%d.%d.%d.%d", idx[0], idx[1], idx[2], idx[3]);
        vec.push_back(string(buff));
    }

    void help(vector<string>& vec, string s, int k) {
        if (k == 0 && s == "") {
            push(vec, idx);
            return;
        }
        if (k == 0) return;

        for (int i = 1; i <= 3 && i <= s.length(); i++) {
            int tmp = atoi(s.substr(0, i).c_str());
            if (tmp >= 0 && tmp <= 255 && (tmp < 10 && i == 1 || tmp >= 10 && tmp <= 100 && i == 2 || tmp >= 100 && i == 3)) {
                idx[4-k] = tmp;
                help(vec, s.substr(i), k-1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        src = s;
        help(ret, s, 4);
        return ret;
    }
};
