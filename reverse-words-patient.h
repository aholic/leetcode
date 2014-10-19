//https://oj.leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> vec;

        int start = 0, end = 0;
        int len = s.length();

        while (start < len) {
            while (start < len && s[start] == ' ') start++;
            end = start + 1;
            while (end < len && s[end] != ' ') end++;

            if (start < len) vec.push_back(s.substr(start, end-start));

            start = end + 1;
        }

        if (vec.empty()) {
            s = "";
            return;
        }

        int wnum = vec.size();
        s = vec[wnum-1];
        for (int i = wnum - 2; i >= 0; i--) s += (' ' + vec[i]);
    }
};
