// Source: https://leetcode.com/problems/longest-palindromic-substring/
// 2015/7/21

// Reference pezy
// https://github.com/pezy/LeetCode/tree/master/119.%20Longest%20Palindromic%20Substring
class Solution {
public:
    string longestPalindrome(string s) {
        int low = 0, high = 0;
        for (int i = 0; i < s.size() && (s.size()-i)*2 > high-low+1; ++i) {
            palindromeBound(s, i, i, low, high);
            palindromeBound(s, i, i+1, low, high);
        }
        return s.substr(low, high-low+1);
    }
private:
    void palindromeBound(const string &s, int b, int e, int &low, int &high) {
        int len = s.size();
        while (b >= 0 && e < len && s[b] == s[e]) {
            --b;
            ++e;
        }
        ++b; --e;
        if (e - b > high - low) {
            high = e;
            low = b;
        }
    }
}; // 28ms