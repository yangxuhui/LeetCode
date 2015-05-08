// Source: https://leetcode.com/problems/powx-n/
// 2015/5/8

// My Solution
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1 / positive_pow(x, -n);
        else return positive_pow(x, n);
    }
private:
    double square(double x) {
        return x * x;
    }
    double positive_pow(double x, unsigned n) {
        if (n == 0) return 1;
        else if (n % 2 == 0) return square(positive_pow(x, n/2));
        else return x * positive_pow(x, n - 1);
    }
}; // 9ms