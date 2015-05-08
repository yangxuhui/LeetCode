// Source: https://leetcode.com/problems/rotate-image/
// 2015/5/8

// My Solution
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0, a = 1, bound = n - 2; i <= (n-1) / 2; ++i, ++a, --bound) {
            for (int j = i; j <= bound; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-a][n-j-1];
                matrix[n-a][n-j-1] = matrix[j][n-a];
                matrix[j][n-a] = tmp;
            }
        }
    }
}; // 6ms