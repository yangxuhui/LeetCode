// Source: https://leetcode.com/problems/reverse-integer/
// 2015/4/7

/******************************************************************************************
// My Solution
// Using string
class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        bool flag = false; // indicate whether x < 0 
        if (x < 0) {
            flag = true;
            x = -x;
        }
        string str = to_string(x);
        string ret_str;
        for (auto it = str.crbegin(); it != str.crend(); ++it)
            ret_str += *it;
        int ret;
        try {
            ret = stoi(ret_str.substr(ret_str.find_first_not_of("0")));
        } catch (out_of_range err) {
            return 0;
        }
        return (flag ? -ret : ret);
    }
}; //19ms
***********************************************************************************************/

// Reference the solution of haeol
// (https://github.com/haoel/leetcode/blob/master/algorithms/reverseInteger/reverseInteger.cpp)
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x) {
            if (ret > INT_MAX/10 || ret < INT_MIN/10)
                return 0;
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret;
    }
}; // 14ms