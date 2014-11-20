//https://oj.leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        for (vector<int>::iterator itr = num.begin(); itr != num.end(); itr++) {
            int tmp = *itr;
            itr = num.erase(itr);

            vector<vector<int> > vec = permute(num);
            for (int i = 0; i < vec.size(); i++) {
                vec[i].push_back(tmp);
                ret.push_back(vec[i]);
            }

            num.insert(itr, tmp);
        }

        if (ret.empty()) ret.resize(1);
        return ret;
    }
};
