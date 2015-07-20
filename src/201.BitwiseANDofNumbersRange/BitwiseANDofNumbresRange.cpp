// Source: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// 2015/7/20

// My Solution
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0) return 0;
        if (m == INT_MAX) return INT_MAX;
        int ret;
        int l = 0, u = 0;
        range(m, n, l, u);
        if (n == (2 << u) || l < u - 1) return 0;
        else if (m == (2 << l)) return (2 << l);
        else {
            ret = m;
            for (int i = m+1; i < n; ++i)
                ret &= i;
            ret &= n;
            return ret;
        }
    }
private:
    void range(int m, int n, int &l, int &u) {
        int help = 1;
        for (int i = 0; l < 31 && m > help ; ++i) {
            help = help << 1;
            ++l;
        }
        if (l == 31 && m != help) l = 32;
        u += l;
        for (int j = l; u < 31 && n > help ; ++j) {
            help = help << 1;
            ++u;
        }
        if (u == 31 && n != help) u = 32;
    }
}; // 76ms