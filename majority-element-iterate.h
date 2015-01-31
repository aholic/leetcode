//https://oj.leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int ret, cnt = 0;
        for (int i = 0; i < num.size(); i++) {
            if (cnt == 0) {
                ret = num[i];
                cnt++;
            } else {
                if (num[i] == ret) {
                    cnt ++;
                } else {
                    cnt --;
                }
            }
        }
        return ret;
    }
};
