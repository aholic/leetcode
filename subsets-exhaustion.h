//https://oj.leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());

        vector<vector<int> > ret;

        int k = S.size();
        for (int i = 0; i < (1 << k); i++) {
            vector<int> tmp;
            for (int j = 0; j < k; j++) {
                if (i & (1 << j)) tmp.push_back(S[j]);
                }
                ret.push_back(tmp);
            }

            return ret;
        }
};
