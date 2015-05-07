// Source: https://leetcode.com/problems/multiply-strings/
// 2015/5/6

// My Solution
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string ret = "0";
        int cnt = 0;
        for (int i = num2.size() - 1; i >= 0; --i) {
            string product = char_multi_string(num1, num2[i]);
            product.append(cnt++, '0');
            ret = add_strings(ret, product);
        }
        return ret;
    }
private:
    string char_multi_string(string num, char c) {
        int ival = c - '0';
        if (ival == 0) return "0";
        int up = 0;
        string ret;
        for (int i = num.size()-1; i >= 0; --i) {
            int product = (num[i] - '0') * ival + up;
            up = product / 10;
            ret.insert(0, 1, (product % 10 + '0'));
        }
        if (up != 0) ret.insert(0, 1, up + '0');
        return ret;
    }
    string add_strings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        string ret;
        int up = 0;
        while (i >=0 && j >=0) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + up;
            up = sum / 10;
            ret.insert(0, 1, (sum % 10 + '0'));
            --i; --j;
        }
        while (i >= 0) {
            int sum = (num1[i] - '0') + up;
            up = sum / 10;
            ret.insert(0, 1, (sum % 10 + '0'));
            --i;
        }
        while (j >= 0) {
            int sum = (num2[j] - '0') + up;
            up = sum / 10;
            ret.insert(0, 1, (sum % 10 + '0'));
            --j;
        }
        if (up != 0) ret.insert(0, 1, up + '0');
        return ret;
    }
}; // 38ms

// Reference pezy
// (https://github.com/pezy/LeetCode/tree/master/124.%20Multiply%20Strings)
class Solution {
public:
    string multiply(string num1, string num2) {
        string ret(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                int sum = (ret[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                ret[i+j+1] = sum % 10 + '0';
                carry = sum / 10;
            }
            ret[i] += carry;
        }
        auto pos = ret.find_first_not_of("0");
        if (pos != string::npos) return ret.substr(pos);
        else return "0";
    }
}; // 18ms