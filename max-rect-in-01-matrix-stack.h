//https://oj.leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int maxRectInLine(vector<int>& line) {
        if (line.size() == 0) return 0;

        line.push_back(0);
        stack<int> s;
        int idx = 0, ret = 0;
        while (idx < line.size()) {
            if (s.empty() || line[s.top()] <= line[idx]) {
                s.push(idx++);
                continue;
            }

            int tmp = s.top();
            s.pop();
            ret = max(ret, line[tmp] * (s.empty() ? idx : idx - s.top() - 1));
        }
        return ret;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > line(m);
        for (int i = 0; i < m; i++) line[i].resize(n);

        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == '0') {
                    cnt = 0;
                } else {
                    cnt++;
                }
                line[i][j] = cnt;
            }
        }

        int ret = 0;
        for (int i = 0; i < line.size(); i++) ret = max(ret, maxRectInLine(line[i]));

        return ret;
    }
};
