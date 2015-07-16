// Source: https://leetcode.com/problems/single-number-ii/
// 2015/7/16

// Reference pezy
// https://github.com/pezy/LeetCode/tree/master/018.%20Single%20Number%20II
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int low = 0, high = 0;
        for (int i = 0; i < nums.size(); ++i) {
            low ^= nums[i] & ~high;
            high ^= nums[i] & ~low;
        }
        return low;
    }
}; // 12ms