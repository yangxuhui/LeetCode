// Source: https://leetcode.com/problems/min-stack/
// 2015/6/19

// My Solution
class MinStack {
public:
    void push(int x) {
        s.push(x);
        if (min_indicator.empty() || x <= min_indicator.top()) 
            min_indicator.push(x);
    }

    void pop() {
        if (!s.empty()) {
            if (s.top() == min_indicator.top()) min_indicator.pop();
            s.pop();
        }
    }

    int top() {
        if (!s.empty()) return s.top();
    }

    int getMin() {
        if (!s.empty()) return min_indicator.top();
        else return 0;
    }
private:
    stack<int> s;
    stack<int> min_indicator;
}; // 68ms