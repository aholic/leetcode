//https://oj.leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0) return 0;

        height.push_back(0);
        stack<int> s;
        int idx = 0;
        int ret = 0;
        int tmp;
        while (idx < height.size()) {
            if (s.empty() || height[s.top()] <= height[idx]) {
                s.push(idx++);
                continue;
            }

            tmp = s.top();
            s.pop();
            ret = max(ret, height[tmp] * (s.empty() ? idx : idx - s.top() - 1));
        }

        return ret;
    }
};
