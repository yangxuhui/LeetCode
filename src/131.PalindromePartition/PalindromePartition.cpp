// Source: https://leetcode.com/problems/palindrome-partitioning/
// 2015/7/24

// My Solution
class Solution {
public:
    vector<vector<string>> partition(string s) {
        sz = s.size();
        vector<string> vec;
        partition(s, vec, 0);
        return ret;
    }
private:
    vector<vector<string>> ret;
    int sz;
    void partition(const string &s, vector<string> vec, int cnt) {
        for (int i = 1; i <= s.size(); ++i) {
            vector<string> temp = vec;
            if (isPalindrome(s.substr(0, i))) {
                temp.push_back(s.substr(0, i));
                if (cnt + i == sz) ret.push_back(temp);
                else partition(s.substr(i), temp, cnt+i);
            }
        }
    }
    bool isPalindrome(const string &s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
            if (s[i] != s[j]) return false;
        return true;
    }
}; // 332ms

// More effecient Solution
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        partition(s, vec, 0);
        return ret;
    }
private:
    vector<vector<string>> ret;
    void partition(const string &s, vector<string> &vec, int index) {
        if (index == s.size()) {
            ret.push_back(vec);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            int begin = index, end = i;
            bool isPalindrome = true;
            while (begin < end) {
                if (s[begin++] != s[end--]) {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome) {
                vec.push_back(s.substr(index, i - index + 1));
                partition(s, vec, i+1);
                vec.pop_back();
            }
        }
    }
}; // 12ms