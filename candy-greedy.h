//https://oj.leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int> &ratings) {
        int ret = 0, decLen = 0, prev = 0;
        for (int i = 0; i < ratings.size(); i++) {
            if (i != 0 && ratings[i] < ratings[i-1]) {
                decLen++;
                ret += (--prev);
                continue;
            }

            if (decLen != 0) {
                ret += ((1-prev) * (decLen+ (prev < 1 ? 1 : 0)));
                prev = 1;
                decLen = 0;
            }

            if (i == 0 || ratings[i] > ratings[i-1]) {
                prev += 1;
            } else if (ratings[i] == ratings[i-1]) {
                prev = 1;
            }

            ret += prev;
        }

        if (decLen != 0) ret += ((1-prev) * (decLen+ (prev < 1 ? 1 : 0)));

        return ret;
    }
};
