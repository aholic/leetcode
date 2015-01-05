//https://oj.leetcode.com/problems/anagrams/

class Solution {
public:
    void st(string& src) {
        int cnt[26];
        for (int i = 0; i < 26; i++) cnt[i] = 0;
        for (int i = 0; i < src.length(); i++) cnt[src[i]-'a']++;

        int tmp = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                src[tmp++] = (i + 'a');
            }
        }
    }

    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, int> um;
        string tmp;
        for (int i = 0; i < strs.size(); i++) {
            tmp = strs[i];
            st(tmp);
            um[tmp] += 1;
        }

        vector<string> ret;
        for (int i = 0; i < strs.size(); i++) {
            tmp = strs[i];
            st(tmp);
            if (um[tmp] > 1) ret.push_back(strs[i]);
        }

        return ret;
    }
};
