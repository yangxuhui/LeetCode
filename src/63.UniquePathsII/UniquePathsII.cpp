// Source: https://leetcode.com/problems/unique-paths-ii/
// 2015/7/11

// Reference pezy
// (https://github.com/pezy/LeetCode/blob/master/062.%20Unique%20Paths%20II/solution.h)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        vector<int> steps(obstacleGrid.front().cbegin(), obstacleGrid.front().cend());
        auto flag = find(steps.begin(), steps.end(), 1);
        fill(steps.begin(), flag, 1);
        fill(flag, steps.end(), 0);
        int m = obstacleGrid.size(), n = obstacleGrid.front().size();
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) steps[j] = 0;
                else if (j != 0) steps[j] += steps[j-1];
            }
        }
        return steps[n-1];
    }
}; // 4ms
