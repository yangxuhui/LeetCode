// Source: https://leetcode.com/problems/jump-game/
// 2015/5/12

// My Solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int index = nums.size() - 2;
        while (index >= 0) {
            int step = 1;
            if (nums[index] >= step) {
                --index; continue;
            } else {
                if (index == 0) return false;
                while (index > 0) {
                    ++step; --index;
                    if (nums[index] >= step) break;
                    if (index == 0) return false;
                }
                --index;
            }
        }
        if (index < 0) return true;
    }
}; // 16ms