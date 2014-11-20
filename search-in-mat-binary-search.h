//https://oj.leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) return false;

        int low, high, mid;
        int line = 0;
        if (matrix[0][0] >= target) {
            line = 0;
        } else {
            low = 0;
            high = matrix.size() - 1;
            mid = low + (high - low) / 2;
            while (low <= high) {
                if (matrix[mid][0] < target) {
                    low = mid + 1;
                } else if (matrix[mid][0] > target) {
                    high = mid - 1;
                } else {
                    return true;
                }
                mid = low + (high - low) / 2;
            }
            line = high;
        }

        low = 0;
        high = matrix[line].size() - 1;
        mid = low + (high - low) / 2;
        while (low <= high) {
            if (matrix[line][mid] < target) {
                low = mid + 1;
            } else if (matrix[line][mid] > target) {
                high = mid - 1;
            } else {
                return true;
            }
            mid = low + (high - low) / 2;
        }
        return false;
    }
};
