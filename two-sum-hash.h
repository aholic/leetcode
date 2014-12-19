//https://oj.leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> make(int a, int b) {
        vector<int> ret;
        ret.push_back(a > b ? b + 1 : a + 1);
        ret.push_back(a > b ? a + 1 : b + 1);
        return ret;
    }
    unordered_map<int, int> m;
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) m[numbers[i]] = i;

        for (int i = 0; i < numbers.size(); i++) {
            int tmp = target - numbers[i];
            if (m.find(tmp) != m.end() && i != m[tmp]) {
                return make(i, m[tmp]);
            }
        }
    }
};
