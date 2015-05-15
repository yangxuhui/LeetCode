// Source: https://leetcode.com/problems/spiral-matrix-ii/
// 2015/5/15

// My Solution
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return vector<vector<int>>();
        if (n == 1) return vector<vector<int>>(1, {1});
        vector<int> tmp(n, 0);
        vector<vector<int>> ret(n, tmp);
        int i = 0, i_beg = 1, i_end = n - 1;
        int j = 0, j_beg = 0, j_end = n - 1;
        bool i_flag = true, j_flag = true;
        int num = 1;
        while (i_flag || j_flag) {
            if (j_flag) {
                if (j_beg <= j_end) {
                    if (j_beg == j_end) j_flag = false;
                    for (j = j_beg; j <= j_end; ++j) ret[i][j] = num++;
                    --j;
                    j_end = j_beg; j_beg = j - 1;
                } else {
                    for (j = j_beg; j >= j_end; --j) ret[i][j] = num++;
                    ++j;
                    j_end = j_beg; j_beg = j + 1;
                }
            }
            if (i_flag) {
                if (i_beg <= i_end) {
                    if (i_beg == i_end) i_flag = false;
                    for (i = i_beg; i <= i_end; ++i) ret[i][j] = num++;
                    --i;
                    i_end = i_beg; i_beg = i - 1;
                } else {
                    for (i = i_beg; i >= i_end; --i) ret[i][j] = num++;
                    ++i;
                    i_end = i_beg; i_beg = i + 1;
                }
            }
        }
        return ret;
    }
}; // 6ms