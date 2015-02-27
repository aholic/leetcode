//https://oj.leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    string n2a(int n) {
        if (n == 0) return "A";
        if (n == 1) return "C";
        if (n == 2) return "G";
        if (n == 3) return "T";
    }

    int a2n(char c) {
        if (c == 'A') return 0;
        if (c == 'C') return 1;
        if (c == 'G') return 2;
        if (c == 'T') return 3;
    }

    int seq2num(string seq) {
        int ret = 0;
        for (int i = 0; i < seq.length(); i++) {
            ret *= 4;
            ret += a2n(seq[i]);
        }
        return ret;
    }

    string num2seq(int num) {
        string ret;
        while (num > 0) {
            ret = n2a(num % 4) + ret;
            num /= 4;
        }

        while (ret.length() < 10) ret = n2a(0) + ret;
        return ret;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> cnt;
        vector<string> ret;
        int magic = (1 << 18);

        if (s.length() <= 10) return ret;

        int num = seq2num(s.substr(0, 10));
        cnt[num]++;
        for (int i = 1; i < s.length()-9; i++) {
            num -= magic * a2n(s[i-1]);
            num *= 4;
            num += a2n(s[i+9]);
            cnt[num]++;
        }

        for (const auto& seq : cnt) {
            if (seq.second >= 2) ret.push_back(num2seq(seq.first));
        }
        return ret;
    }
};
