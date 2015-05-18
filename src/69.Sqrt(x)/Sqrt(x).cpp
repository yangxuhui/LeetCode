// Source: https://leetcode.com/problems/sqrtx/
// 2015/5/18

// My Solution
class Solution {
public:
    int mySqrt(int x) {
        double guess = 1;
        while (abs(guess * guess - x) > 0.001)
            guess = (guess + x / guess) / 2;
        return guess;
    }
}; // 8ms