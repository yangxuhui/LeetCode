// Source: https://leetcode.com/problems/pascals-triangle/
// 2015/6/4

// My Solution
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; ++i) {
            vector<int> tmp(i + 1, 1);
            if (i > 0) {
                for (int j = 1; j < ret[i-1].size(); ++j)
                    tmp[j] = ret[i-1][j-1] + ret[i-1][j];
            }
            ret.push_back(tmp);
        }
        return ret;
    }
}; // 4ms