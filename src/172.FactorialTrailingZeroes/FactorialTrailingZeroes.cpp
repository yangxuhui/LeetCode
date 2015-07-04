// Source: https://leetcode.com/problems/factorial-trailing-zeroes/
// 2015/7/4

// Reference https://leetcode.com/discuss/questions/oj/factorial-trailing-zeroes?sort=votes
class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
}; // 4ms

// iterative Solution
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while (n > 0) {
            n /= 5;
            ret += n;
        }
        return ret;
    }
}; // 4ms