//https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    bool isOp(string str) {
        return (str == "+" || str == "-" || str == "*" || str == "/");
    }

    string calc(string s1, string s2, string op) {
        int i1 = atoi(s1.c_str());
        int i2 = atoi(s2.c_str());

        char buf[30];
        if (op == "+") {
            sprintf(buf, "%d", i1+i2);
        } else if (op == "-") {
            sprintf(buf, "%d", i1-i2);
        } else if (op == "*") {
            sprintf(buf, "%d", i1*i2);
        } else if (op == "/") {
            sprintf(buf, "%d", i1/i2);
        }

        return (string(buf));
    }

    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 0) return 0;

        stack<string> s;
        string s1, s2;
        for (int i = 0; i < tokens.size(); i++) {
            if (isOp(tokens[i])) {
                s2 = s.top();
                s.pop();
                s1 = s.top();
                s.pop();
                s.push(calc(s1, s2, tokens[i]));
            } else {
                s.push(tokens[i]);
            }
        }

        s1 = s.top();
        return (atoi(s1.c_str()));
    }
};
