// Source: https://leetcode.com/problems/first-missing-positive/
// 2015/5/4

// My Solution
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i != nums.size();) {
            if (nums[i] > 0 && nums[i] < nums.size() && nums[i] != i + 1 && nums[nums[i]-1] != nums[i]) {
                int tmp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = tmp;
            } else ++i;
        }
        for (int i = 0; i != nums.size(); ++i) 
            if (nums[i] != i + 1) return i + 1;
        return nums.size() + 1;
    }
}; // 5ms

// Reference pezy
// (https://github.com/pezy/LeetCode/tree/master/105.%20First%20Missing%20Positive)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i != nums.size(); ++i)
            while (nums[i] > 0 && nums[i] < nums.size() && nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
        for (int i = 0; i != nums.size(); ++i)
            if (nums[i] != i + 1) return i + 1;
        return nums.size() + 1;
    }
}; // 4ms