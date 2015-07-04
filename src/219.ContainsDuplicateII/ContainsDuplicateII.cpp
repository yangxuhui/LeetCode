// Source: https://leetcode.com/problems/contains-duplicate-ii/
// 2015/7/3

// My Solution
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && m[nums[i]] >= i - k) return true;
            m[nums[i]] = i;
        }
        return false;
    }
}; // 76ms