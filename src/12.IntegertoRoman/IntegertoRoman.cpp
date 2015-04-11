// Source: https://leetcode.com/problems/integer-to-roman/
// 2015/4/10

/**********************************************************************************************
// Reference haoel
// (https://github.com/haoel/leetcode/blob/master/algorithms/integerToRoman/integerToRoman.cpp)
// A more elegant solution
class Solution {
public:
    string intToRoman(int num) {
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ret;
        for (int i = 0; num != 0; ++i) {
            while (num >= arr[i]) {
                ret += symbol[i];
                num -= arr[i];
            }
        }
        return ret;
    }
}; // 51ms
************************************************************************************************/
// My Solution
class Solution {
public:
    string intToRoman(int num) {
        string ret_str;
		if (num >= 1000) {
			ret_str.append(num / 1000, 'M');
			num %= 1000; 
    	}
		int len = 100;
    	char carry[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
		int i = 0, j = 1, k = 2;
    	while (num) {
			int digit = num/len;
			if (digit) {
				if (digit < 4)
					ret_str.append(digit, carry[k]);
				else if (digit == 4) {
					ret_str.append(1, carry[k]);
					ret_str.append(1, carry[j]);
				} else if (digit == 5)
					ret_str.append(1, carry[j]);
				else if (digit == 9) {
					ret_str.append(1, carry[k]);
					ret_str.append(1, carry[i]);
				} else {
					ret_str.append(1, carry[j]);
					ret_str.append(digit - 5, carry[k]);  
				}
			}
			num %= len;
			len /= 10;
			i += 2; j += 2; k += 2;
		}
		return ret_str;
    }
}; // 42ms
