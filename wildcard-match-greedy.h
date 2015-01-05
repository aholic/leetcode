//https://oj.leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int slen = strlen(s);
        int plen = strlen(p);

        int sidx = 0, pidx = 0;
        int stmp = -1, ptmp = -1;

        while (sidx < slen) {
            if (s[sidx] == p[pidx] || p[pidx] == '?') {
                sidx++;
                pidx++;
                continue;
            }
            if (p[pidx] == '*') {
                ptmp = pidx;
                stmp = sidx;
                pidx++;
                continue;
            }
            if (ptmp != -1) {
                pidx = ptmp + 1;
                sidx = stmp + 1;
                stmp++;
                continue;
            }
            return false;
        }

        while (pidx < plen && p[pidx] == '*') pidx++;
        return pidx == plen;
    }
};
