//https://oj.leetcode.com/problems/edit-distance/

class Solution {
public:
    template <class T1, class T2>
    pair<T1, T2> min(pair<T1, T2> a, pair<T1, T2> b) {
        return a.first <= b.first ? a : b;
    }

    template <class T1, class T2>
    pair<T1, T2> min(pair<T1, T2> a, pair<T1, T2> b, pair<T1, T2> c) {
        return min(a, min(b, c));
    }    


    int minDistance(string word1, string word2) {
        if (word1.length() == 0 || word2.length() == 0) return word1.length() + word2.length();

        int dp[word1.length()][word2.length()];
        pair<int, int> prev[word1.length()][word2.length()];
        int tmp = 0;

        for (int i = 0; i < word1.length(); i++) {
            for (int j = 0; j < word2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = (word1[i] == word2[j] ? 0 : 1);
                    prev[i][j] = (word1[i] == word2[j] ? make_pair(i, j) : make_pair(-1, -1));
                } else if (i == 0 && j != 0) {
                    dp[i][j] = dp[i][j-1] + (j == dp[i][j-1] && word1[i] == word2[j] ? 0 : 1);
                    prev[i][j] = (j == dp[i][j-1] && word1[i] == word2[j] ? make_pair(i, j) : prev[i][j-1]);
                } else if (i != 0 && j == 0) {
                    dp[i][j] = dp[i-1][j] + (i == dp[i-1][j] && word1[i] == word2[j] ? 0 : 1);
                    prev[i][j] = (i == dp[i-1][j] && word1[i] == word2[j] ? make_pair(i, j) : prev[i-1][j]);
                } else {
                    tmp = dp[i-1][j] + (i - prev[i-1][j].first <= j - prev[i-1][j].second ? 0 : 1);
                    auto tmp1 = make_pair(tmp, prev[i-1][j]);

                    tmp = dp[i][j-1] + (i - prev[i][j-1].first >= j - prev[i][j-1].second ? 0 : 1);
                    auto tmp2 = make_pair(tmp, prev[i][j-1]);

                    tmp = dp[i-1][j-1] + (word1[i] == word2[j] ? 0 : 1);
                    auto tmp3 = make_pair(tmp, word1[i] == word2[j] ? make_pair(i, j) : prev[i-1][j-1]);

                    dp[i][j] = min(tmp1, tmp2, tmp3).first;
                    prev[i][j] = min(tmp1, tmp2, tmp3).second;
                }
            }
        }
        return dp[word1.length() - 1][word2.length() - 1];
    }
};
