// Source: https://leetcode.com/problems/combination-sum-iii/
// 2015/7/8

// My Solution
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        dfs(vector<int>(), n, 1, k, ret);
        return ret;
    }
private:
    void dfs(vector<int> curr, int target, int begin, int need, vector<vector<int>>& ret) {
        if (target == 0 && need == 0) { ret.push_back(curr); return;}
        if (need == 0) return;
        for (int i = begin; i <= 9 && i <= target; ++i) {
            curr.push_back(i);
            dfs(curr, target - i, i + 1, need - 1, ret);
            curr.pop_back();
        }
    }
}; // 0ms