// Source: https://leetcode.com/problems/isomorphic-strings/
// 2015/7/1

// My Solution
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, vector<int>> m1, m2;
        for (size_t i = 0; i < s.size(); ++i)
            m1[s[i]].push_back(i);
        for (size_t i = 0; i < t.size(); ++i)
            m2[t[i]].push_back(i);
        map<int, set<vector<int>>> cnt_to_pos1, cnt_to_pos2;
        for (auto elem : m1)
            cnt_to_pos1[elem.second.size()].insert(elem.second);
        for (auto elem : m2)
            cnt_to_pos2[elem.second.size()].insert(elem.second);
        return cnt_to_pos1 == cnt_to_pos2;
    }
}; // 56ms