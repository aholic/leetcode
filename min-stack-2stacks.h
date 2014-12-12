//https://oj.leetcode.com/problems/min-stack/

class MinStack {
public:
    stack<int> _data;
    stack<int> _minVal;
    void push(int x) {
        _data.push(x);
        if (_minVal.empty() || x <= _minVal.top()) {
            _minVal.push(x);
        }
    }

    void pop() {
        int tmp = _data.top();
        _data.pop();

        if (tmp <= _minVal.top()) _minVal.pop();
    }

    int top() {
        return _data.top();
    }

    int getMin() {
        return _minVal.top();
    }
};
