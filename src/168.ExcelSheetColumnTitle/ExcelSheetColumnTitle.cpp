// Source: https://leetcode.com/problems/excel-sheet-column-title/
// 2015/6/25

// My Solution
class Solution {
public:
    string convertToTitle(int n) {
        string title;
        while (n) {
            int itemp = n % 26;
            char ctemp = (itemp == 0 ? 'Z' : 'A' + itemp - 1);
            title = ctemp + title;
            n /= 26;
            if (itemp == 0) --n;
        }
        return title;
    }
}; // 0ms