//https://oj.leetcode.com/problems/generate-parentheses/

class Solution {
public:
    void helper(vector<string>& vec, int n, int left, int right, string current) {
        if (current.length() == n*2) {
            vec.push_back(current);
            return;
        }

        if (left - right < n && left < n) helper(vec, n, left+1, right, current + "(");
        if (left - right > 0 && right < n) helper(vec, n, left, right+1, current + ")");
    } 
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        helper(vec, n, 0, 0, "");
        return vec;
    }
};
