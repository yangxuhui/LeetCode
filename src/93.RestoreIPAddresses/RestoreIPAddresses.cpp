// Source: https://leetcode.com/problems/restore-ip-addresses/
// 2015/7/23

// Reference pezy
// https://github.com/pezy/LeetCode/blob/master/123.%20Restore%20IP%20Addresses/solution.h
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() >= 4 && s.size() <= 12) store(s, "", 4);
        return ret;
    }
private:
    vector<string> ret;
    bool isValid(const string &str) {
        if (str.size() > 1 && str[0] == '0') return false;
        int num = std::stoi(str);
        return num >= 0 && num <= 255;
    }
    void store(const string &s, const string &ip, int part) {
        if (part == 0) {
            if (s.empty()) ret.push_back(ip);
            return;
        }
        
        for (int i = 1; i < 4; ++i) {
            if (s.size() < i) break;
            string section = s.substr(0, i);
            if (isValid(section)) {
                if (part != 1) section.append(".");
                store(s.substr(i), ip+section, part-1);
            }
        }
    }
}; // 4ms