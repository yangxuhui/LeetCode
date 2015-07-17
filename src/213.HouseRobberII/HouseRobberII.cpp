// Source : https://leetcode.com/problems/house-robber-ii/
// 2015/7/17

// My Solution
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        return std::max(maxRob(nums, 0, nums.size()-2), maxRob(nums, 1, nums.size()-1));
    }
private:
    int maxRob(vector<int>& nums, int begin, int end) {
        int maxSofar = 0;
        for (int i = begin, maxPresofar = 0, maxEndinghere = 0; i <= end; ++i) {
            maxEndinghere = maxPresofar + nums[i];
            maxPresofar = maxSofar;
            maxSofar = std::max(maxSofar, maxEndinghere);
        }
        return maxSofar;
    }
}; // 0ms