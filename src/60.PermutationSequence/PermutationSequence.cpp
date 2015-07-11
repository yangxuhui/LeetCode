// Source: https://leetcode.com/problems/permutation-sequence/
// 2015/7/11

// Reference https://leetcode.com/discuss/11023/most-concise-c-solution-minimal-memory-required
// https://github.com/pezy/LeetCode/blob/master/108.%20Permutation%20Sequence/solution.h
class Solution {
public:
    string getPermutation(int n, int k) {
        string ret(n, '0');
        int fact = 1;
        for (int i = 1; i <=n; ++i) {
            fact *= i;
            ret[i-1] += i;
        }
        for (int i = 0; i <n; ++i) {
            fact /= n - i;
            int index = (k - 1)/fact + i;
            char c = ret[index];
            for (int j = index; j > i; --j)
                ret[j] = ret[j-1];
            ret[i] = c;
            k = k - (index - i) * fact;
        }
        return ret;
    }
}; // 0ms