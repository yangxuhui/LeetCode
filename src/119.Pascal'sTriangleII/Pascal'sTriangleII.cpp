// Source: https://leetcode.com/problems/pascals-triangle-ii/
// 2015/6/4

// My Solution
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1, 1);
        for (int i = 1; i < rowIndex; ++i)
            for (int j = i; j > 0; --j)
                ret[j] += ret[j-1];
        return ret;
    }
}; // 0ms