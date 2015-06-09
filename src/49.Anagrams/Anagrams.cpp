// Source: https://leetcode.com/problems/anagrams/
// 2015/6/9

// My Solution
class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (auto elem : strs) {
            string sig = elem;
            sort(sig.begin(), sig.end());
            m[sig].push_back(elem);
        }
        vector<string> ret;
        for (auto elem : m) 
            if (elem.second.size() > 1)
                for (auto s : elem.second)
                    ret.push_back(s);
        return ret;
    }
}; // 68ms