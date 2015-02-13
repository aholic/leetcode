//https://oj.leetcode.com/problems/maximum-gap/

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;

        int pow10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

        vector<int> buck[10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < num.size(); j++) {
                buck[(num[j]/pow10[i])%10].push_back(num[j]);
            }
            num.clear();
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < buck[j].size(); k++) {
                    num.push_back(buck[j][k]);
                }
                buck[j].clear();
            }
        }

        int ret = 0;
        for (int i = 1; i < num.size(); i++) {
            if (ret < num[i] - num[i-1]) {
                ret = num[i] - num[i-1];
            }
        }

        return ret;
    }
};
