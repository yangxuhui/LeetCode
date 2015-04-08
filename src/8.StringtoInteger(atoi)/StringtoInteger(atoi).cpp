// Source: https://leetcode.com/problems/string-to-integer-atoi/
// 2015/4/7

// Reference the solution of haeol
// (https://github.com/haoel/leetcode/blob/master/algorithms/stringToIntegerAtoi/stringToIntegerAtoi.cpp)

class Solution {
public:
    int atoi(string str) {
        if (str.empty()) return 0;
        auto pos = str.find_first_not_of(" ");
        if (pos == string::npos) return 0;
        str = str.substr(pos);
        int ret = 0;
        bool neg = false;
        if (str[0] == '+' || str[0] == '-') {
            if (str.size() == 1) return 0;
            neg = (str[0] == '-');
            str = str.substr(1);
        }
        for (auto c : str) {
            if (!isdigit(c)) break;
            int digit = c - '0';
            if (neg) {
                if (-ret < (INT_MIN + digit)/10)
                    return INT_MIN;
            } else {
                if (ret > (INT_MAX - digit)/10)
                    return INT_MAX;
            }
            ret = ret * 10 + digit;
        }
        return neg? -ret : ret;
    }
}; // 20ms