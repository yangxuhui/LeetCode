// Source: https://leetcode.com/problems/happy-number/
// 2015/6/28

// My Solution
class Solution {
public:
    bool isHappy(int n) {
        if (n < 10)
            return (n == 1 || n == 7)  ? true : false;
        else
            return isHappy(translate(n));
    }
private:
    int translate(int n) {
        string str = to_string(n);
        int ret = 0;
        for (auto elem : str)
            ret = ret + (elem - '0') * (elem - '0');
        return ret;
    }
}; // 4ms