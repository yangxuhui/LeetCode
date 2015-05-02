// Source: https://leetcode.com/problems/divide-two-integers/
// 2015/5/2

// My Solution
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == 0) return 0;
        if (divisor == dividend) return 1;
        if (divisor == 1 || divisor == -1) {
            if (dividend != INT_MIN) return (divisor == 1) ? dividend : -dividend;
            else return (divisor == 1) ? dividend : INT_MAX;
        }
        if (divisor == INT_MIN) return 0;
        if (dividend != INT_MIN && abs(dividend) < abs(divisor)) return 0;
        bool flag = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) flag = true;
        bool flag2 = false;
        if (dividend == INT_MIN) {
            flag2 = true;
            dividend += abs(divisor);
            if (abs(dividend) < abs(divisor))
             return flag ? -1 : 1;
        }
        string sdividend = to_string(abs(dividend)), sdivisor = to_string(abs(divisor));
        int rem = 0;
        string result = to_string(getQuotient(stoi(sdividend.substr(0, sdivisor.size())), abs(divisor), rem));
        for (int j = sdivisor.size(); j != sdividend.size(); ++j) {
            string tmp = to_string(rem);
            tmp.append(sdividend, j, 1);
            result += to_string(getQuotient(stoi(tmp), abs(divisor), rem));
        }
        if (flag) {
        	if (flag2)
        		return -(stoi(result) + 1);
        	else return -stoi(result);
        } 
        else {
        	if (flag2)
        		return stoi(result) + 1;
        	else return stoi(result);
        }
    }
private:
    int getQuotient(int a, int b, int &remainder) {
        int ret = 0;
        for (int i = 1; ; ++i) {
            if (a < b) {
                ret = i - 1;
                remainder = a;
                break;
            }
            a -= b;
        }
        return ret;
    }
}; // 24ms

// Reference haoel
// (https://github.com/haoel/leetcode/blob/master/algorithms/divideTwoInt/divideTwoInt.cpp)
class Solution {
public:
    int divide(int dividend, int divisor) {
        // determine sign
        bool flag = false; // false means result > 0 and true means result < 0
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) flag = true;
        unsigned dvd = dividend > 0 ? dividend : -dividend;
        unsigned dvs = divisor > 0 ? divisor : -divisor;
        
        unsigned bit_num[32];
        int i = 0;
        long long d = dvs;
        bit_num[i] = d;
        while (d <= dvd) {
            bit_num[++i] = d = d << 1;
        }
        --i;
        
        unsigned result = 0;
        while (dvd >= dvs) {
            if (dvd >= bit_num[i]) {
                dvd -= bit_num[i];
                result += (1 << i);
            } else {
                --i;
            }
        }
        
        // dividend == INT_MIN && divisor == -1 caused overflow
        if (result > INT_MAX && !flag) return INT_MAX;
        return flag ? -(int)result : (int)result;
    }
}; // 14ms