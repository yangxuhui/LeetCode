// Source: https://leetcode.com/problems/zigzag-conversion/
// 2015/4/3

/* This is my solution 
 * Find the rules of per line words
 */
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows<=1 || nRows>=s.size()) return s;
        string ret;
        int pos = 0;
        bool flag = true;
        for (int i = 1; i <= nRows; ++i) {
            ret.append(1, s[i-1]);
            if (i == 1 || i == nRows) {
                pos = i + 2 * (nRows - 1);
                while (pos <= s.size()) {
                    ret.append(1, s[pos-1]);
                    pos += 2 * (nRows - 1);
                }
            } else {
                pos = i + 2 * (nRows - i);
                flag = true;
                while (pos <= s.size()) {
                    ret.append(1, s[pos-1]);
                    if (flag) {
                        pos += 2 * (i - 1);
                        flag = false;
                    } else {
                        pos += 2 * (nRows - i);
                        flag = true;
                    }
                }
            }
        }
        return ret;
    }
}; // 26ms

/* This is the solution I learned from
 * haoel (https://github.com/haoel/leetcode/blob/master/algorithms/zigZagConversion/zigZagConversion.cpp)
 * This solution is simple and elegant
 */
/***********************************************************
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1 || nRows >= s.size()) return s;
        // the element in svec is per line
        vector<string> svec(nRows);
        int r = 0, step = 0;
        for (string::size_type i = 0; i != s.size(); ++i) {
            if (r == nRows - 1) step = -1;
            if (r == 0) step = 1;
            svec[r] += s[i];
            r += step;
        }
        string ret;
        for (auto elem : svec)
            ret += elem;
        return ret;
    }
}; // 32ms
 *****************************************************************/
