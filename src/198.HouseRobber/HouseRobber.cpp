// Source: https://leetcode.com/problems/house-robber/
// 2015/7/5

// My Solution
class Solution {
public:
    int rob(vector<int>& nums) {
        int maxSofar = 0;
        for (int i = 0, maxPreSofar = 0, maxendinghere = 0; i < nums.size(); ++i) {
            maxendinghere = maxPreSofar + nums[i];
            maxPreSofar = maxSofar;
            maxSofar = std::max(maxSofar, maxendinghere);
        }
        return maxSofar;
    }
}; // 0ms
