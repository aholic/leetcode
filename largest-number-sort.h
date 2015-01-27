//https://oj.leetcode.com/problems/largest-number/

bool cmp (const int& i1, const int& i2) {
    char buff1[20];
    char buff2[20];

    sprintf(buff1, "%d", i1);
    sprintf(buff2, "%d", i2);

    string s1(buff1);
    string s2(buff2);

    string ss1 = s1 + s2;
    string ss2 = s2 + s1;

    return ss1 > ss2;
}
class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), cmp);
        string ret = "";
        char buff[30];
        for (int i =0; i < num.size(); i++) {
            sprintf(buff, "%d", num[i]);
            ret += string(buff);
        }

        int i = 0;
        while (i < ret.length() && ret[i] == '0') i++;

        ret = ret.substr(i);

        if (ret == "") return string("0");
        return ret;
    }
};
