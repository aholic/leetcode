// https://oj.leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0;
        int high = n-1;
        int mid = low + (high - low) / 2;

        while (low <= high) {
            if (A[mid] < target) {
                low = mid + 1;
            } else if (A[mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
            mid = low + (high - low) / 2;
        }
        return low;
    }
};
