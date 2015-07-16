// Source: https://leetcode.com/problems/triangle/
// 2015/7/16

// My Solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        vector<int> helper(triangle.back().begin(), triangle.back().end());
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j)
                helper[j] = triangle[i][j] + min(helper[j], helper[j+1]);
        }
        return helper.front();
    }
}; // 8ms