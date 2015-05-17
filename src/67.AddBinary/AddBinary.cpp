// Source: https://leetcode.com/problems/add-binary/
// 2015/5/17

// My Solution 
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() == 0 || b.size() == 0)
            return a.size() == 0 ? b : a;
        string sum_str(a.size() > b.size() ? a.size() + 1 : b.size() + 1, '0');
        int carry = 0, index = sum_str.size() - 1;
        int i = a.size()-1, j = b.size() - 1;
        for (; i >= 0 && j >= 0; --i, --j) {
            int sum = a[i] - '0' + b[j] - '0' + carry;
            sum_str[index--] = sum % 2 + '0';
            carry = sum / 2;
        }
        while (i >= 0) {
            int sum = a[i] - '0' + carry;
            sum_str[index--] = sum % 2 + '0';
            carry = sum / 2;
            --i;
        }
        while (j >= 0) {
            int sum = b[j] - '0' + carry;
            sum_str[index--] = sum % 2 + '0';
            carry = sum / 2;
            --j;
        }
        sum_str[index] = carry + '0';
        return carry ? sum_str : sum_str.substr(1, sum_str.size() - 1);
    }
}; // 4ms