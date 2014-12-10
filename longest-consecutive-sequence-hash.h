//https://oj.leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int getLen(int num, int maxLen, unordered_map<int, int>& p) {
        int ret = 1;

        for (int i = 1; i < maxLen; i++) {
            if (p.find(num+i) == p.end()) break;
            p.erase(num+i);
            ret += 1;
        }

        for (int i = 1; i < maxLen; i++) {
            if (p.find(num-i) == p.end()) break;
            p.erase(num-i);
            ret += 1;
        }

        return ret;
    }

    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> p;
        for (int i = 0; i < num.size(); i++) p[num[i]] = i;

        int len = 0, tmp;
        for (int i = 0; i < num.size(); i++) {
            if (p.find(num[i]) != p.end()) {
                tmp = getLen(num[i], num.size(), p);
                if (tmp > len) len = tmp;
            }
        }

        return len;
    }
};
