// Source: https://leetcode.com/problems/plus-one/
// 2015/5/17

// My Solution
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0) return {1};
        vector<int> sum_vec(digits.size()+1, 0);
        int index = sum_vec.size() - 1, carry = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int sum = digits[i] + carry + (i == digits.size() - 1 ? 1 : 0);
            sum_vec[index--] = sum % 10;
            carry = sum / 10;
        }
        if (carry) {
            sum_vec[index] = carry;
            return sum_vec;
        }
        else return vector<int>(sum_vec.begin()+1, sum_vec.end());
    }
}; // 4ms