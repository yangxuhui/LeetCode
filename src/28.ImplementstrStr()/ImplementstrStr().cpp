// Source: https://leetcode.com/problems/implement-strstr/
// 2015/4/27

// My Soultion1
// Using string class find function
class Solution {
public:
    int strStr(string haystack, string needle) {
        auto pos = haystack.find(needle);
        return (pos == string::npos) ? -1 : pos;
    }
}; // 6ms

// My Soultion2
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;
        int pos = -1;
        for (int i = 0; i < (haystack.size()-needle.size()+1);++i) {
            if (haystack[i] == needle[0]) {
                int j = 1, tmp_pos = i;
                for (int ix = i + 1; j != needle.size() && ix != haystack.size(); ++ix,++j)
                    if (haystack[ix] != needle[j]) break;
                if (j == needle.size()) {
                    pos = tmp_pos;
                    break;
                }
            }
        }
        return pos;
    }
}; // 8ms