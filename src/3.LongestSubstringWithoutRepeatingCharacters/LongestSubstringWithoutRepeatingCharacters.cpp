// Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// 2015/4/1

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string::size_type length = 0;
        string str;
        for (auto c : s) {
            auto pos = str.find(c);
            if (pos != string::npos) {
                if (str.size() > length)
                    length = str.size();
                str.erase(0, pos + 1);
            }
            str.append(1, c);
        }
        if (str.size() > length) length = str.size();
        return length;
    }
}; // 22ms
