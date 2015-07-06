// Source: https://leetcode.com/problems/generate-parentheses/
// 2015/7/6

// Reference pezy(https://github.com/pezy/LeetCode/blob/master/031.%20Generate%20Parentheses/solution.h)
// and https://leetcode.com/discuss/questions/oj/generate-parentheses?sort=votes
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        std::function<void(string, int, int)> addParentheses = [&](string str, int left, int right) {
            if (left == 0 && right == 0) ret.push_back(str);
            if (left > 0) addParentheses(str + "(", left - 1, right + 1);
            if (right > 0) addParentheses(str + ")", left, right - 1);
        };
        addParentheses("", n, 0);
        return ret;
    }
}; // 4ms
