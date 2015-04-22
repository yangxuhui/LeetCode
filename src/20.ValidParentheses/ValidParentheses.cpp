// Source: https://leetcode.com/problems/valid-parentheses/
// 2015/4/22

// My Solution
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) return true;
        // when s.size() is odd, the input string must be invalid 
        if (s.size() % 2 != 0) return false;
        map<char, int> chartoInt = {{'(', 1}, {'{', 1}, {'[', 1}, 
                                    {')', 2}, {'}', 2}, {']', 2}};
        map<char, char> close_brackets = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> stk;
        for (auto c : s) {
            if (chartoInt[c] == 1) stk.push(c);
            else {
                if (stk.empty()) return false;
                else if (stk.top() == close_brackets[c]) stk.pop();
                else return false;
            }
        }
        if (stk.empty()) return true;
        else return false;
    }
}; // 4ms