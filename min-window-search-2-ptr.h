//https://oj.leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string src, string needle) {
        if (src == "" || needle == "") return "";

        int toFind[128], found[128];
        for (int i = 0; i < 128; i++) toFind[i] = found[i] = 0;
        for (const auto& c : needle) toFind[c] += 1;

        int start = 0, end = 0, ml = 0, len = INT_MAX;
        string ret = "";

        while (end < src.length()) {
            if (toFind[src[end]] != 0) {
                found[src[end]] += 1;
                if (found[src[end]] <= toFind[src[end]]) ml += 1;

                if (ml == needle.length()) {
                    while (start <= end) {
                        if (found[src[start]] != 0 && found[src[start]] == toFind[src[start]]) break;
                        if (found[src[start]] != 0) found[src[start]] -= 1;
                        start++;
                    }

                    if (end - start + 1 < len) {
                        len = end - start + 1;
                        ret = src.substr(start, len);
                    }
                    found[src[start]] -= 1;
                    ml -= 1;
                    start ++;
                }
            }
            end++;
        }

        return ret;
    }
};
