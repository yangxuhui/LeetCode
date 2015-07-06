// Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// 2015/7/6

// My Solution
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty()) return ret;
        ret.push_back("");
        for (auto c : digits) {
            vector<string> temp;
            for (auto str : ret) {
                for (auto elem : m[c])
                    temp.push_back(str+elem);
            }
            ret = temp;
        }
        return ret;
    }
private:
    map<char, set<string>> m = { {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}}, {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}}, {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}}, {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}}
    };
}; // 4ms
