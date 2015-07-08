// Source: 
// 2015/7/8

// Reference pezy(https://github.com/pezy/LeetCode/blob/master/075.%20Combination%20Sum/solution.h)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        dfs(candidates, target, vector<int>{}, 0, ret);
        return ret;
    }
private:
    void dfs(vector<int>& candi, int target, vector<int> curr, int index, vector<vector<int>>& ret) {
        if (target == 0) { ret.push_back(curr); return; }
        for (int i = index; i < candi.size() && candi[i] <= target; ++i) {
            curr.push_back(candi[i]);
            dfs(candi, target - candi[i], curr, i, ret);
            curr.pop_back();
        }
    }
}; // 20ms