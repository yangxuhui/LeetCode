// Source: https://leetcode.com/problems/permutations/
// 2015/7/9

// My Solution
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.empty()) return ret;
        sort(nums.begin(), nums.end());
        do {
            ret.push_back(nums);
        } while (hasnextPermutation(nums));
        return ret;
    }
private:
    bool hasnextPermutation(vector<int>& vec) {
        if (vec.size() < 2) return false;
        int i = vec.size() - 2;
        while (i >= 0 && vec[i] >= vec[i+1]) --i;
        if (i == -1) return false;
        reverse(begin(vec)+i+1, end(vec));
        auto iter = upper_bound(begin(vec)+i+1, end(vec), vec[i]);
        swap(vec[i], *iter);
        return true;
    }
}; // 16ms