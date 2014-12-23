//https://oj.leetcode.com/problems/3sum/

class Solution {
public:
    vector<int> make(int a, int b, int c) {
        vector<int> ret;
        ret.push_back(a);
        ret.push_back(b);
        ret.push_back(c);
        return ret;
    }

    vector<vector<int> > threeSum(vector<int> &num) {
        if (num.size() < 3) return vector<vector<int> >();

        vector<vector<int> > ret;
        sort(num.begin(), num.end());

        int idx = 0, left, right, target;
        while (idx < num.size() - 2) {
            target = 0 - num[idx];
            left = idx + 1;
            right = num.size() - 1;
            while (right > left) {
                if (num[left] + num[right] > target) {
                    right--;
                    while (right > left && num[right] == num[right+1]) right--;
                } else if (num[left] + num[right] < target) {
                    left++;
                    while (left < right && num[left] == num[left-1]) left++;
                } else {
                    ret.push_back(make(num[idx], num[left], num[right]));
                    right--;
                    while (right > left && num[right] == num[right+1]) right--;
                    left++;
                    while (left < right && num[left] == num[left-1]) left++;
                }
            }

            idx++;
            while (idx < num.size() - 2 && num[idx] == num[idx-1]) idx++;
        }

        return ret;
    }
};
