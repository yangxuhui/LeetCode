// Source: https://leetcode.com/problems/count-and-say/
// 2015/5/3

// My Solution
class Solution {
public:
    string countAndSay(int n) {
        string pre = "1", curr = "1";
        while (--n) {
            curr = "";
            for (string::size_type i = 0; i < pre.size(); ++i) {
                int cnt = 1;
                while (pre[i] == pre[i+1] && i < pre.size()-1) {
                    ++cnt;
                    ++i;
                }
                curr += to_string(cnt).append(1, pre[i]);
            }
            pre = curr;
        }
        return curr;
    }
}; // 6ms