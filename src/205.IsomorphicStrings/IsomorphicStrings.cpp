// Source: https://leetcode.com/problems/isomorphic-strings/
// 2015/7/1

// My Solution
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, vector<int>> m1, m2;
        for (size_t i = 0; i < s.size(); ++i) {
            m1[s[i]].push_back(i);
            m2[t[i]].push_back(i);
        }
        map<int, set<vector<int>>> cnt_to_pos1, cnt_to_pos2;
        for (auto elem : m1)
            cnt_to_pos1[elem.second.size()].insert(elem.second);
        for (auto elem : m2)
            cnt_to_pos2[elem.second.size()].insert(elem.second);
        return cnt_to_pos1 == cnt_to_pos2;
    }
}; // 56ms

// Reference https://leetcode.com/discuss/33854/my-6-lines-solution
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[128] = {0}, m2[128] = {0};
        for (int i = 0; i < s.size(); ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
}; // 8ms