// Source: https://leetcode.com/problems/length-of-last-word/
// 2015/5/10

// My Solution 
class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos_beg = 0, pos_end = -1;
        for (int i = s.size() - 1; i >= 0; --i)
            if (s[i] != ' ') {
                pos_end = i; break;
            }
        if (pos_end == -1) return 0;
        for (int i = pos_end - 1; i >= 0; --i)
            if (s[i] == ' ') {
                pos_beg = i + 1; break;
            }
        return pos_end - pos_beg + 1;
    }
}; // 4ms

// Solution 2(same idea but more elegrant)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for (int i = s.size() - 1, cnt = 0, flag = 1; i >=0; --i) {
            if (s[i] != ' ') { length = ++cnt; flag = 0; }
            else if(s[i] == ' ' && !flag) break;
        }
        return length;
    }
}; // 4ms