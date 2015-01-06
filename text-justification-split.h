//https://oj.leetcode.com/problems/text-justification/

class Solution {
public:
    string format(const vector<string> &words, int left, int right, int len) {
        if (left == right - 1) {
            string ret = words[left];
            ret.append(len - words[left].length(), ' ');
            return ret;
        }

        int spaces = len;
        for (int i = left; i < right; i++) spaces -= (words[i].length());

        string ret = words[right - 1];
        for (int i = right - 2; i >= left; i--) {
            ret.insert(0, spaces / (i - left + 1), ' ');
            ret = words[i] + ret;
            spaces -= (spaces / (i - left + 1));
        }

        return ret;
    }

    string reFormatLast(string s) {
        int len = s.length();
        vector<string> words;

        istringstream iss(s);
        do {
            string sub;
            iss >> sub;
            words.push_back(sub);
        } while (iss);

        string ret = words[0];
        for (int i = 1; i < words.size() - 1; i++) {
            ret += ' ';
            ret += words[i];
        }
        ret.append(len-ret.length(), ' ');
        return ret;
    }

    vector<string> fullJustify(vector<string> &words, int len) {
        if (words.size() == 0) return vector<string>(1);

        vector<string> ret;
        int tmp = 0, start = 0, end = 0;
        for (int i = 0; i < words.size(); i++) {
            if (end - start != 0) tmp += 1;
            tmp += words[i].length();

            if (tmp < len) {
                end++;
            } else if (tmp > len) {
                ret.push_back(format(words, start, end, len));
                tmp = words[end].length();
                start = end;
                end++;
            } else {
                end++;
                tmp = 0;
                ret.push_back(format(words, start, end, len));
                start = end;
            }
        }
        if (end - start != 0) ret.push_back(format(words, start, end, len));

        if (ret.size() > 0) ret[ret.size()-1] = reFormatLast(ret[ret.size()-1]);
        return ret;
    }
};
