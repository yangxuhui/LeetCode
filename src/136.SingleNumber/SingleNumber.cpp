// Source: https://leetcode.com/problems/single-number/
// 2015/6/29

// My Solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (size_t i = 0; i < nums.size(); ++i)
            ret ^= nums[i];
        return ret;
    }
}; // 20ms