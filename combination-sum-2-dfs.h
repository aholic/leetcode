//https://oj.leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int> > solutions;
    vector<int> solution;

    void search(int idx, vector<int> &candidates, int target) {
        if (target == 0) {
            solutions.push_back(solution);
            return;
        }

        if (idx >= candidates.size()) return;
        if (candidates[idx] > target) return;

        int next = idx + 1;
        while (next < candidates.size() && candidates[next] == candidates[next - 1]) next++;
        if (next != candidates.size()) search(next, candidates, target);

        solution.push_back(candidates[idx]);
        search(idx+1, candidates, target - candidates[idx]);
        solution.pop_back();
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        if (candidates.empty()) return (vector<vector<int> >());
        sort(candidates.begin(), candidates.end());
        search(0, candidates, target);
        return solutions;
    }
};
