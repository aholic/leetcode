//https://oj.leetcode.com/problems/3sum-closest/

class Solution {
public:
    int diff(int a, int b) {
        return (a > b ? a - b : b - a);
    }
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) return 0;

        int sum = num[0] + num[1] + num[2];
        sort(num.begin(), num.end());

        int idx = 0, left, right;
        while (idx < num.size() - 2) {
            left = idx + 1;
            right = num.size() - 1;
            while (right > left) {
                if (diff(target, num[left] + num[right] + num[idx]) < diff(target, sum)) {
                    sum = num[left] + num[right] + num[idx];
                }

                if (num[left] + num[right] + num[idx]> target) {
                    right--;
                    while (right > left && num[right] == num[right+1]) right--;
                } else if (num[left] + num[right] + num[idx] < target) {
                    left++;
                    while (left < right && num[left] == num[left-1]) left++;
                } else {
                    return target;
                }
            }

            idx++;
            while (idx < num.size() - 2 && num[idx] == num[idx-1]) idx++;
        }
        return sum;
    }
};
