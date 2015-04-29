// Source: https://leetcode.com/problems/search-insert-position/
// 2015/4/29

// My Solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ret = 0;
        auto iter = find(nums.cbegin(), nums.cend(), target);
        if (iter != nums.cend()) return iter - nums.cbegin();
        else {
            nums.push_back(target);
            sort(nums.begin(), nums.end());
            ret = find(nums.cbegin(), nums.cend(), target) - nums.cbegin();
            return ret;
        }
    }
}; // 19ms