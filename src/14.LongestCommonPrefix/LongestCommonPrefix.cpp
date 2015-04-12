// Source: https://leetcode.com/problems/longest-common-prefix/
// 2015/4/12

// My Solution
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string max_prefix;
        // strs is empty, return empty string
        if (strs.size() == 0) return max_prefix;
        // strs has only one string, return the string
        if (strs.size() == 1) return strs[0];
        // initiation, longest common prefix is the first string
        max_prefix = strs[0];
        auto iter = strs.begin() + 1;
        while (iter != strs.end()) {
            int index = 0;
            while (index != max_prefix.size() && index != iter->size()) {
                if (max_prefix[index] != (*iter)[index])
                    break;
                ++index;
            }
            if (index == 0) return "";
            if (index == iter->size()) 
                max_prefix = *iter;
            else 
                max_prefix = max_prefix.substr(0, index);
            ++iter;
        }
        return max_prefix;
    }
}; // 9ms