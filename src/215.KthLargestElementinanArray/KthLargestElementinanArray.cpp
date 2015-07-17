// Source : https://leetcode.com/problems/kth-largest-element-in-an-array/
// 2015/7/17

// My Solution
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
}; // 12ms