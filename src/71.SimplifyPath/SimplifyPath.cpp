// Source: https://leetcode.com/problems/simplify-path/
// 2015/7/13

// Reference pezy
// (https://github.com/pezy/LeetCode/blob/master/128.%20Simplify%20Path/solution.h)
class Solution {
public:
    string simplifyPath(string path) {
        string ret, temp;
        stack<string> s;
        for (istringstream iss(path); getline(iss, temp, '/');) {
            if (temp == ".." && !s.empty()) s.pop();
            else if (temp == ".." || temp == "." || temp == "") continue;
            else s.push(temp);
        }
        while (!s.empty()) {
            ret = "/" + s.top() + ret;
            s.pop();
        }
        return ret.empty() ? "/" : ret;
    }
}; // 12ms
