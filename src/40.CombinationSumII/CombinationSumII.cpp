// Source: https://leetcode.com/problems/combination-sum-ii/
// 2015/7/8

// My Solution
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        dfs(candidates, target, vector<int>(), 0, ret);
        return ret;
    }
private:
    void dfs(vector<int>& candi, int target, vector<int> curr, int index, vector<vector<int>>& ret) {
        if (target == 0) { ret.push_back(curr); return; }
        for (int i = index; i < candi.size() && candi[i] <= target; ++i) {
            if (i == index || candi[i] != candi[i-1]) {
                curr.push_back(candi[i]);
                dfs(candi, target - candi[i], curr, i + 1, ret);
                curr.pop_back();
            }
        }
    }
}; // 12ms