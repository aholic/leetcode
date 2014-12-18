//https://oj.leetcode.com/problems/count-and-say/

class Solution {
public:
    int next(int start, const string& src) {
        int idx = start;
        int len = src.length();
        while (idx < len - 1) {
            if (src[idx] != src[idx+1]) break;
            idx++;
        }
        return idx;
    }
    string iterate(const string& src) {
        string ret = "";
        int idx = 0;
        int tmp = 0;
        while (idx < src.length()) {
            tmp = next(idx, src);
            ret.append(1, tmp-idx+1+'0');
            ret.append(1, src[tmp]);
            idx = tmp + 1;
        }
        return ret;
    }
    string countAndSay(int n) {
        string ret = "1";
        for (int i = 0; i < n - 1; i++) {
            ret = iterate(ret);
        }
        return ret;
    }
};
