// Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// 2015/6/18

// My Solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int min = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] < min)
                min = nums[i];
        return min;
    }
}; // 8ms