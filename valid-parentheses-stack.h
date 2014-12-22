//https://oj.leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool left(char c) {
        return c == '(' || c == '{' || c == '[';
    }

    bool right(char c) {
        return c == ')' || c == '}' || c == ']';
    }

    bool match(char c1, char c2) {
        return (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']');
    }

    bool isValid(string s) {
        stack<char> sta;

        for (int i = 0; i < s.size(); i++) {
            if (sta.empty() && right(s[i])) return false;
            if (left(s[i])) {
                sta.push(s[i]);
            } else if (right(s[i])) {
                char tmp = sta.top();
                sta.pop();
                if (!match(tmp, s[i])) return false;
            }
        }

        return sta.empty();
    }
};
