// Source: https://leetcode.com/problems/set-matrix-zeroes/
// 2015/5/20

// My Solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row_set, col_set;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                if (matrix[i][j] == 0) {
                    row_set.insert(i);
                    col_set.insert(j);
                }
        for (auto row : row_set)
            for (auto &elem : matrix[row])
                elem = 0;
        for (auto col : col_set)
            for (int i = 0; i < matrix.size(); ++i)
                matrix[i][col] = 0;
    }
}; // 84ms