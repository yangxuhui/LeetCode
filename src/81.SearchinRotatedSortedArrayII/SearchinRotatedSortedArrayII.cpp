// Source: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// 2015/5/23

// My Solution
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] == target)
                return true;
            else if (nums[i] > nums[i+1]) {
                low = i + 1;
                break;
            }
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }   
        return false;
    }
}; // 8ms