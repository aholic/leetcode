//https://oj.leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    int cmp(int a, int b) {
        if (a > b) return 1;
        if (a < b) return -1;
        if (a == b) return 0;
    }
    int getNext(string ver, int& start) {
        int tmp = ver.find('.', start);
        int ret = atoi(ver.substr(start, tmp).c_str());
        if (tmp == string::npos) {
            start = ver.length();
        } else {
            start = tmp + 1;
        }
        return ret; 
    }
    int compareVersion(string version1, string version2) {
        int idx1 = 0, idx2 = 0;
        while (idx1 < version1.length() && idx2 < version2.length()) {
            int v1 = getNext(version1, idx1);
            int v2 = getNext(version2, idx2);
            if (v1 != v2) return cmp(v1, v2);
        }

        while (idx1 < version1.length()) {
            if (getNext(version1, idx1) != 0) return 1;
        }
        while (idx2 < version2.length()) {
            if (getNext(version2, idx2) != 0) return -1;
        }
        return 0;
    }
};
