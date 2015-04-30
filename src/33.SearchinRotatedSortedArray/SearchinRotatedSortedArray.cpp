// Source: https://leetcode.com/problems/search-in-rotated-sorted-array/
// 2015/4/30

// My Solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        while (low < nums.size()-1 && nums[low] != target && nums[low] < nums[low+1]) ++low;
        if (low == nums.size() - 1) {
            if (nums[low] == target) return low;
            else return -1;
        } 
        else if (nums[low] == target) return low;
        else return binary_search(nums,low+1, nums.size()-1, target);
    }
private:
    int binary_search(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
}; // 8ms