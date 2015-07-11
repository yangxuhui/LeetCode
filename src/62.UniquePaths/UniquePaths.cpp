// Source: https://leetcode.com/problems/unique-paths/
// 2015/7/11

// Reference https://leetcode.com/discuss/9110/my-ac-solution-using-formula
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <=0 || n <= 0) return 0;
        long long ret = 1;
        int numofMove = m + n - 2;
        int minMove = std::min(m-1, n-1);
        for (int i = 1; i <= minMove; ++i) 
            ret = ret * (numofMove - minMove + i) / i;
        return ret;
    }
}; // 0ms