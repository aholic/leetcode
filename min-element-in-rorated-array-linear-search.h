//https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int> &num) {
        vector<int>::iterator minNum = min_element(num.begin(), num.end());
        return (*minNum);
    }
};
