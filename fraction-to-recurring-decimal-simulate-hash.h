//https://oj.leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string itoa(long long i) {
        char str[20];
        sprintf(str, "%ld", i);
        return string(str);
    }

    string negative(bool neg) {
        if (neg) return "-";
        return "";
    }

    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator, den = denominator;
        if (num % den == 0) return itoa(num / den);

        bool neg = num > 0 && den < 0 || num < 0 && den > 0;
        if (num < 0) num = -num;
        if (den < 0) den = -den;

        string ret = itoa(num/den) + ".";
        num %= den;

        unordered_map<long long, int> umap;        
        while (num != 0 && umap.find(num) == umap.end()) {
            umap[num] = ret.length();
            ret += itoa(num*10 / den);
            num = (num * 10) % den;
        }
        if (num != 0) {
            ret.insert(umap[num], "(");
            ret += ")";
        }
        return negative(neg) + ret;
    }
};
