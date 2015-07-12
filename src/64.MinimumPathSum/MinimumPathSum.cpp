// Source: https://leetcode.com/problems/minimum-path-sum/
// 2015/7/12

// Reference pezy
// (https://github.com/pezy/LeetCode/tree/master/038.%20Minimum%20Path%20Sum)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid.front().size();
        if (n == 0) return 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                else if (i == 0) grid[i][j] += grid[i][j-1];
                else if (j == 0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
}; // 28ms