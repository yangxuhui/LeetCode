// Source: https://leetcode.com/problems/find-peak-element/
// 2015/6/21

// My Solution
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 && nums[i] > nums[i+1]) return i;
            else if (i == nums.size() - 1 && nums[i] > nums[i-1]) return i;
            else if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }
    }
}; // 8ms