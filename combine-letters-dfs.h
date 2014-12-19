//https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    unordered_map<char, vector<string> > word;
    string wrap(char c) {
        string ret = "";
        ret.append(1, c);
        return ret;
    }
    void init() {
        for (char c = 'a'; c <= 'z'; c++) {
            if (c <= 'o') {
                word[(c-'a') / 3 + 2 + '0'].push_back(wrap(c));
            } else {
                if ('p' <= c && c <= 's') {
                    word['7'].push_back(wrap(c));
                } else if ('t' <= c && c <= 'v') {
                    word['8'].push_back(wrap(c));
                } else {
                    word['9'].push_back(wrap(c));
                }
            }
        }
    }

    vector<string> helper(string digits) {
        vector<string> ret;
        if (digits.length() == 0) {
            ret.push_back("");
            return ret;
        }

        const vector<string>& cand = word[digits[0]];

        for (int i = 0; i < cand.size(); i++) {
            vector<string> tmp = helper(digits.substr(1));
            for (int j = 0; j < tmp.size(); j++) {
                ret.push_back(cand[i]+ tmp[j]);
            }
        }

        return ret;
    }
    vector<string> letterCombinations(string digits) {
        init();
        return helper(digits);
    }
};
