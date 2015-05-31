// Source: https://leetcode.com/problems/gray-code/
// 2015/5/31

// Reference pezy
// https://github.com/pezy/LeetCode/blob/master/028.%20Gray%20Code/solution.h
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        for (int i = 0; i != 1<<n; ++i)
            ret.push_back(i/2^i);
        return ret;
    }
}; // 4ms