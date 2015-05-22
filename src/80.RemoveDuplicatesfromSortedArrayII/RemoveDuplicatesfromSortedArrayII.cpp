// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// 2015/5/22

// My Solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int cnt = 0;
            while (i < nums.size()-1 && nums[i] == nums[i+1]) {
                ++i;
                ++cnt;
            }
            nums[len++] = nums[i];
            if (cnt > 0) nums[len++] = nums[i];
        }
        return len;
    }
}; // 20ms