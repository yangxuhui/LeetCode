// Source: https://leetcode.com/problems/valid-palindrome/
// 2015/6/7

// My Solution
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
            while (i <= j && !isalnum(s[i])) ++i;
            while (i <= j && !isalnum(s[j])) --j;
            if (i > j) return true;
            else if (isalpha(s[i]) && isalpha(s[j])) {
                if (tolower(s[i]) != tolower(s[j])) return false;
            } else if (isdigit(s[i]) && isdigit(s[j])) {
                if (s[i] != s[j]) return false;
            } else return false;
        }
        return true;
    }
}; // 12ms