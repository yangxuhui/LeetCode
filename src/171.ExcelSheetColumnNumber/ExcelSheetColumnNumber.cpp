// Source: https://leetcode.com/problems/excel-sheet-column-number/
// 2015/6/24

// My Solution
class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i)
            ret = (s[i] - 'A' + 1) + ret * 26;
        return ret;
    }
}; // 12ms