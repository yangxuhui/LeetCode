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
