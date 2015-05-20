// Source: https://leetcode.com/problems/search-a-2d-matrix/
// 2015/5/20

// My Solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) low = mid + 1;
            else high = mid - 1;
        }
        int row = low - 1;
        if (row < 0) return false;
        low = 0, high = matrix[row].size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
}; // 16ms