// Source: https://leetcode.com/problems/spiral-matrix/
// 2015/5/12

// My Solution
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return vector<int>();
        vector<int> ret;
        if (matrix[0].size() == 1) {
            for (int i = 0; i < matrix.size(); ++i)
                ret.push_back(matrix[i][0]);
            return ret;
        }
        if (matrix.size() == 1) {
            for (auto elem : matrix[0])
                ret.push_back(elem);
            return ret;
        }
        int i = 0, i_beg = 1, i_end = matrix.size() - 1;
        int j = 0, j_beg = 0, j_end = matrix[0].size() - 1;
        bool flag_i = true, flag_j = true;
        while (flag_i || flag_j) {
            if (flag_j) {
                if (j_beg <= j_end) {
                    if (j_beg == j_end) flag_j = false;
                    for (j = j_beg; j <= j_end; ++j)
                        ret.push_back(matrix[i][j]);
                    --j;
                    if (flag_j) {
                        if (!flag_i) flag_j = false;
                        j_end = j_beg; j_beg = j - 1;
                    }
                } else {
                    for (j = j_beg; j >= j_end; --j)
                        ret.push_back(matrix[i][j]);
                    ++j;
                    if (!flag_i) flag_j = false;
                    j_end = j_beg; j_beg = j + 1;
                }
            }
            if (flag_i) {
                if (i_beg <= i_end) {
                    if (i_beg == i_end) flag_i = false;
                    for (i = i_beg; i <= i_end; ++i)
                        ret.push_back(matrix[i][j]);
                    --i;
                    if (flag_i) {
                        if (!flag_j) flag_i = false;
                        i_end = i_beg; i_beg = i - 1;
                    }
                } else {
                    for (i = i_beg; i >= i_end; --i)
                        ret.push_back(matrix[i][j]);
                    ++i;
                    if (!flag_j) flag_i = false;
                    i_end = i_beg; i_beg = i + 1;
                } 
            }
        }
        return ret;
    }
}; // 2ms