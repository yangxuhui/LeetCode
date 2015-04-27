// Source: https://leetcode.com/problems/implement-strstr/
// 2015/4/27

// My Soultion
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        auto pos = haystack.find(needle);
        return (pos == string::npos) ? -1 : pos;
    }
}; // 6ms