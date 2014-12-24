//https://oj.leetcode.com/problems/4sum/

class Solution {
public:
    vector<int> make(int a, int b, int c, int d) {
        vector<int> ret(4);
        ret[0] = a;
        ret[1] = b;
        ret[2] = c;
        ret[3] = d;
        return ret;
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if (num.size() < 4) return vector<vector<int> >();

        vector<vector<int> > ret;
        sort(num.begin(), num.end());
        int idx1 = 0, idx2, idx3, idx4;
        while (idx1 < num.size() - 3) {
            idx2 = idx1 + 1;
            while (idx2 < num.size() - 2) {
                idx3 = idx2 + 1;
                idx4 = num.size() - 1;
                while (idx3 < idx4) {
                    int tmp = num[idx1] + num[idx2] + num[idx3] + num[idx4];
                    if (tmp > target) {
                        idx4--;
                        while (idx3 < idx4 && num[idx4] == num[idx4+1]) idx4--;
                    } else if (tmp < target) {
                        idx3++;
                        while (idx3 < idx4 && num[idx3] == num[idx3-1]) idx3++;
                    } else {
                        ret.push_back(make(num[idx1], num[idx2], num[idx3], num[idx4]));
                        idx4--;
                        while (idx3 < idx4 && num[idx4] == num[idx4+1]) idx4--;
                        idx3++;
                        while (idx3 < idx4 && num[idx3] == num[idx3-1]) idx3++;
                    }
                }

                idx2++;
                while (idx2 < num.size() - 2 && num[idx2] == num[idx2-1]) idx2++;
            }

            idx1++;
            while (idx1 < num.size() - 3 && num[idx1] == num[idx1-1]) idx1++;
        }

        return ret;
    }
};
