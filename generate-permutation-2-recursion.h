//https://oj.leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<int> getTemp(const vector<int> &num, int idx) {
        vector<int> ret(num);
        ret.erase(ret.begin() + idx);
        return ret;
    }
    vector<vector<int> > helper(const vector<int> &num) {
        vector<vector<int> > ret;
        for (int i = 0; i < num.size(); i++) {
            if (i != 0 && num[i] == num[i-1]) continue;

            vector<vector<int> > vec = helper(getTemp(num, i));
            for (int j = 0; j < vec.size(); j++) {
                vec[j].push_back(num[i]);
                ret.push_back(vec[j]);
            }
        }
        if (ret.empty()) ret.resize(1);
        return ret;
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        return helper(num);
    }
};
