//https://oj.leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int> > solutions;
    vector<int> solution;

    void push_backs(vector<int>& v, int val, int times) {
        while (times--) v.push_back(val);
    }

    void pop_backs(vector<int>& v, int times) {
        while (times--) v.pop_back();
    }

    void search(int idx, vector<int> &candidates, int target) {
        if (target == 0) {
            solutions.push_back(solution);
            return;
        }

        if (idx >= candidates.size()) return;

        for (int i = 0; i <= target / candidates[idx]; i++) {
            push_backs(solution, candidates[idx], i);
            search(idx+1, candidates, target - i * candidates[idx]);
            pop_backs(solution, i);
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        if (candidates.empty()) return (vector<vector<int> >());
        sort(candidates.begin(), candidates.end());
        search(0, candidates, target);
        return solutions;
    }
};
