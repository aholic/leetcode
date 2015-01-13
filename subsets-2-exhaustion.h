//https://oj.leetcode.com/problems/subsets-ii/

class Solution {
public:
    void push(vector<int>& vec, int num, int times) {
        while (times--) vec.push_back(num);
    }

    void incr(const vector<int>& limit, vector<int>& current) {
        int jw = 1, idx = 0;
        while (idx < current.size() && jw > 0) {
            current[idx] += jw;
            jw = current[idx] / (limit[idx]);
            current[idx] %= (limit[idx]);
            idx += 1;
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &se) {
        if (se.empty()) return vector<vector<int> >(1);

        sort(se.begin(), se.end());

        vector<int> num;
        vector<int> current;
        vector<int> limit;


        int cnt, idx = 0, tmp;
        while (idx < se.size()) {
            tmp = se[idx];
            cnt = 0;

            while (idx < se.size() && se[idx] == tmp) {
                idx++;
                cnt++;
            }

            current.push_back(0);
            num.push_back(tmp);
            limit.push_back(cnt + 1);
        }

        int loop = 1;
        for (int i = 0; i < limit.size(); i++) loop *= (limit[i]);

        vector<vector<int> > ret(loop);
        for (int i = 0; i < loop; i++) {
            vector<int> vtmp;
            for (int j = 0; j < num.size(); j++) push(vtmp, num[j], current[j]);
            ret[i] = vtmp;
            incr(limit, current);
        }

        return ret;
    }
};
