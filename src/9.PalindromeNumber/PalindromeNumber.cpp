// Source: https://leetcode.com/problems/palindrome-number/
// 2015/4/8

/**********************************************************************************************
// My Solution
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x > INT_MAX) return false;
        if (x < 10) return true;
        string str = to_string(x);
        bool ret = true;
        for (int i = 0, j = str.size() - 1;
            i < j; ++i, --j) {
            if (str[i] != str[j]) {
                ret = false;
                break;
            }    
        }
        return ret;
    }
}; // 158ms

// Reference the solution of haoel
// (https://github.com/haoel/leetcode/blob/master/algorithms/palindromeNumber/palindromeNumber.cpp)
// Thanks!

// Note: How he get the reversed integer
class Solution {
public:
    bool isPalindrome(int x) {
        return (x >= 0 && x == reverse(x));
    }
private:
    int reverse(int x) {
        int ret = 0;
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret;
    }
}; // 131ms
*******************************************************************************************************/

// Note: How he obtained the pair of digits 
class Solution {
public:
    bool isPalindrome(int x) {
        // x is a negative
        if (x < 0) return false;
        // the order of magnitudes of the integer
        int len = 1; 
        for (; x/len >= 10; len *= 10);
        while (x) {
            int left = x/len;
            int right = x % 10;
            if (left != right) return false;
            x = (x % len) / 10;
            len /= 100;
        }
        return true;
    }
}; // 123ms

