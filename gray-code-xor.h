//https://oj.leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> vec;
        vector<int> masks(1<<n);

        for (int i = 1 ; i < (1 << n); i *= 2) {
            for (int j = i; j < masks.size(); j += i) {
                masks[j-1] = i;
            }
        }

        int itr = 0;
        for (int i = 0; i < (1 << n); i++) {
            vec.push_back(itr);
            itr ^= masks[i];
        }
        return vec;
    }
};
