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

// My Solution2
// Using Binary Search(折半查找)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] <target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
}; // 10ms