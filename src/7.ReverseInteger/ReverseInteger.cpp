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
};