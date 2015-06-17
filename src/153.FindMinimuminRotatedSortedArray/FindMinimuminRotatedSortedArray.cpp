// Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// 2015/6/17

// My Solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int low = 0, high = nums.size() - 1;
        while (low + 1 != high) {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[mid-1]) return nums[mid];
            else if (nums[mid] > nums[0]) low = mid;
            else high = mid;
        }
        return nums[low] < nums[high] ? nums[0] : nums[high];
    }
}; // 5ms