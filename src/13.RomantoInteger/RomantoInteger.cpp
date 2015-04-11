// Source: https://leetcode.com/problems/roman-to-integer/
// 2015/4/11

// My Solution
class Solution {
public:
    int romanToInt(string s) {
		map<char, int> m = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
		int ret = 0;
		int i = 0;
		while (i < s.size() - 1) {
			int j = i + 1;
			if (s[j] == s[i]) {
				do {
					++j;
				} while (j != s.size() && s[j] == s[i]);
				ret += (m[s[i]] * (j - i));
				i = j;
				if (j == s.size()) break;
			} else if (m[s[i]] < m[s[j]]) {
				ret += (m[s[j]] - m[s[i]]);
				i += 2;
			} else {
				ret += m[s[i]];
				++i;
			} 
		}
		if (i != s.size()) {
			ret += m[s[i]];
		}
		return ret; 
	}
}; // 92ms

/*********************************************************************************************
// Reference haoel
// (https://github.com/haoel/leetcode/blob/master/algorithms/romanToInteger/romanToInteger.cpp)
// A more efficient solution
class Solution {
public:
    int romanToInt(string s) {
        int ret = romanCharToInt(s[0]);
        for (int i = 1; i != s.size(); ++i) {
            int pre = romanCharToInt(s[i-1]), curr = romanCharToInt(s[i]);
            if (pre < curr) 
                ret = ret - pre + (curr - pre);
            else
                ret += curr;
        }
        return ret;
    }
private:
    int romanCharToInt(char c) {
        int d = 0;
        switch (c) {
            case 'I':
               d = 1;
               break;
            case 'V':
                d = 5;
                break;
            case 'X':
                d = 10;
                break;
            case 'L':
                d = 50;
                break;
            case 'C':
                d = 100;
                break;
            case 'D':
                d = 500;
                break;
            case 'M':
                d = 1000;
                break;
        }
        return d;
    }
}; // 66ms
************************************************************************************************/
