//https://oj.leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> vec(digits);

        int jinwei = 1;
        for (int i = vec.size() - 1; i >= 0; i--) {
            vec[i] += jinwei;
            jinwei = vec[i] / 10;
            if (vec[i] / 10 > 0) vec[i] %= 10;
        }

        if (jinwei != 0) {
            vec.insert(vec.begin(), jinwei);
        }

        return vec;
    }
};
