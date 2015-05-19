// Source: https://leetcode.com/problems/climbing-stairs/
// 2015/5/19

// My Solution
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int ret = 0;
        for (int i = 3, pre1 = 1, pre2 = 2; i <= n; ++i) {
            ret = pre1 + pre2;
            pre1 = pre2;
            pre2 = ret;
        }
        return ret;
    }
}; // 0ms