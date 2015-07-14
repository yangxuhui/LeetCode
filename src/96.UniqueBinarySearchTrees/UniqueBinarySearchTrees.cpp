// Source: https://leetcode.com/problems/unique-binary-search-trees/
// 2015/7/14

// Reference https://leetcode.com/discuss/24282/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i
class Solution {
public:
    int numTrees(int n) {
        int ret[n+1] = {0};
        ret[0] = ret[1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                ret[i] += ret[j-1] * ret[i-j];
        return ret[n];
    }
}; // 0ms